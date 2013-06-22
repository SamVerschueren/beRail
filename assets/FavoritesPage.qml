import bb.cascades 1.0
import bb.system 1.0
import be.rail.viewmodels 1.0

Page {
    id: favPage
    Container {
        layout: DockLayout { }

        ListView {
            id: favoriteList
            dataModel: favoritesVM.dataModel

            listItemComponents: [
                ListItemComponent {
                    type: "item"

                    Container {
                        id: mainContainer
                        background: ListItem.active ? Color.create("#CC00A8DF") : (ListItem.selected ? Color.create("#00A8DF") : Color.Transparent)

                        contextActions: [
                            ActionSet {
                                title: qsTr("Favoriet")
                                subtitle: ListItemData.from + " - " + ListItemData.to
                                actions: [
                                    DeleteActionItem {
                                        title: qsTr("Verwijderen")
                                        onTriggered: {
                                            deleteDialog.show()
                                        }
                                    }
                                ]
                                attachedObjects: [
                                    SystemDialog {
                                        id: deleteDialog
                                        title: qsTr("Verwijderen")
                                        body: qsTr("Bent u zeker dat u de route van %1 naar %2 wil verwijderen?").arg(ListItemData.from).arg(ListItemData.to)
                                        onFinished: {
                                            if (value == 2) {
                                                mainContainer.ListItem.view.remove(mainContainer.ListItem.indexPath);

                                                confirmToast.show();
                                            }
                                        }
                                    },
                                    SystemToast {
                                        id: confirmToast
                                        body: qsTr("De route is verwijderd.")
                                    }
                                ]
                            }
                        ]

                        Container {
                            horizontalAlignment: HorizontalAlignment.Fill
                            topPadding: 10.0
                            leftPadding: 10.0
                            rightPadding: 10.0
                            bottomPadding: 10.0
                            layout: StackLayout {
                                orientation: LayoutOrientation.LeftToRight
                            }

                            Container {
                                layout: StackLayout {
                                    orientation: LayoutOrientation.LeftToRight
                                }
                                
                                Container {
                                    rightMargin: 20
                                    Label {
                                        text: qsTr("Van") + ":"
                                        textStyle.color: Color.LightGray
                                    }
                                    Label {
                                        text: qsTr("Tot") + ":"
                                        textStyle.color: Color.LightGray
                                    }
                                }
                                Container {
                                    Label {
                                        text: ListItemData.from
                                    }
                                    Label {
                                        text: ListItemData.to
                                    }
                                }
                            }
                        }
                        Container {
                            preferredHeight: 2
                            preferredWidth: 800
                            background: Color.create("#eeeeee")
                        }
                    }
                }
            ]
            onTriggered: {
                // This is invoked when the user short presses the item
                var selectedItem = dataModel.data(indexPath);
                
                rootTabbedPane.search(selectedItem.from, selectedItem.to);
            }
            
            function remove(indexPath) {
                favoritesVM.remove(indexPath);
            }
        }
        
        Container {
            verticalAlignment: VerticalAlignment.Center
            horizontalAlignment: HorizontalAlignment.Center
            visible: favoritesVM.dataModel.isEmpty()
            leftPadding: 20.0
            rightPadding: 20.0

            Label {
                text: qsTr("Geen favorieten")
                textStyle.fontSize: FontSize.XXLarge
                horizontalAlignment: HorizontalAlignment.Center
            }
            Label {
                text: qsTr("Begin met toevoegen van je favoriete routes.")
                multiline: true
                textStyle.textAlign: TextAlign.Center
            }
        }
    }
    attachedObjects: [
        FavoritesViewModel {
            id: favoritesVM
            service: favoriteService
        }
    ]
}
