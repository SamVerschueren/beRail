import bb.cascades 1.0
import bb.system 1.0
import be.rail.viewmodels 1.0

NavigationPane {
    id: navigationPane
    property Button element

    Page {
        id: router
        titleBar: TitleBar {
            title: "beRail"
            acceptAction: ActionItem {
                id: searchAction
                enabled: false
                title: qsTr("Zoeken")
                onTriggered: startSearch()
            }
        }

        Container {
            layout: DockLayout {
            }
            verticalAlignment: VerticalAlignment.Fill
            horizontalAlignment: HorizontalAlignment.Fill

            ActivityIndicator {
                id: activityIndicator
                verticalAlignment: VerticalAlignment.Center
                horizontalAlignment: HorizontalAlignment.Center
                preferredWidth: 200
                preferredHeight: 200
                visible: false
            }

            ScrollView {
                id: contentScroller
                verticalAlignment: VerticalAlignment.Fill
                horizontalAlignment: HorizontalAlignment.Fill
                
                Container {
                    layout: StackLayout {
                    }
                    horizontalAlignment: HorizontalAlignment.Fill
                    topPadding: 30
                    leftPadding: 20
                    rightPadding: 20

                    Button {
                        id: cmdFrom
                        text: qsTr("Van")
                        horizontalAlignment: HorizontalAlignment.Fill
                        onClicked: {
                            element = cmdFrom;

                            stationSheet.open();
                        }
                    }

                    Button {
                        id: cmdTo
                        text: qsTr("Tot")
                        horizontalAlignment: HorizontalAlignment.Fill
                        onClicked: {
                            element = cmdTo;

                            stationSheet.open();
                        }
                    }

                    Container {
                        layout: StackLayout {
                            orientation: LayoutOrientation.LeftToRight
                        }

                        DateTimePicker {
                            id: datePicker
                        }

                        DateTimePicker {
                            id: timePicker
                            mode: DateTimePickerMode.Time
                            minuteInterval: 10
                        }
                    }

                    SegmentedControl {
                        id: type
                        options: [
                            Option {
                                text: qsTr("Vertrekken")
                            },
                            Option {
                                text: qsTr("Aankomen")
                            }
                        ]
                    }
                }
            }
        }

        onCreationCompleted: {
            stationSheet.stationPicked.connect(stationPickedCompleted)
        }

        function stationPickedCompleted(text) {
            element.text = text;
            
            if(routeVM.from != '' && routeVM.to != '') {
                searchAction.enabled = true
            }
        }

        attachedObjects: [
            RouteViewModel {
                id: routeVM
                from: cmdFrom.text != qsTr("Van") ? cmdFrom.text : ""
                to: cmdTo.text != qsTr("Tot") ? cmdTo.text : ""
                date: datePicker.value
                time: timePicker.value
                type: type.selectedIndex
                service: favoriteService
                onSelectionChanged: {
                    var detailPage = detailResultPage.createObject();

                    navigationPane.push(detailPage);
                }
                onSearchCompleted: {
                    if (error != "") {
                        contentScroller.visible = true;
                        activityIndicator.visible = false;
                        activityIndicator.stop();

                        toast.body = qsTr(error);
                        toast.show();
                    } else {
                        var resultPage = searchResultPage.createObject();
                        
                        navigationPane.push(resultPage);

                        contentScroller.visible = true;
                        activityIndicator.visible = false;
                        activityIndicator.stop();
                    }

                    searchAction.enabled = true;
                }
                onNetwerkError: {
                    contentScroller.visible = true;
                    activityIndicator.visible = false;
                    activityIndicator.stop();
                    
                    dialog.body = error;
                    dialog.show();
                    
                    searchAction.enabled = true;
                }
            },
            SystemToast {
                id: toast
            },
            SystemDialog {
                id: dialog
                title: qsTr("Fout")
                cancelButton.label: undefined
            }
        ]
    }
    
    attachedObjects: [
        ComponentDefinition {
            id: searchResultPage
            source: "asset:///SearchResultPage.qml"
        },
        ComponentDefinition {
            id: detailResultPage
            source: "asset:///DetailResultPage.qml"
        }
    ]
    
    function startSearch() {
        searchAction.enabled = false;
        contentScroller.visible = false;
        activityIndicator.visible = true;
        activityIndicator.start();
        
        routeVM.search();
    }
    
    function search(from, to) {
        cmdFrom.text = from
        cmdTo.text = to
        
        startSearch()
    }
}
