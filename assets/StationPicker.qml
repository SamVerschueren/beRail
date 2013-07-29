import bb.cascades 1.0
import be.rail.viewmodels 1.0

Sheet {
    id: sheet
    signal stationPicked(string value)
    
    Page {
        id: pickerPage
        titleBar: TitleBar {
            title: qsTr("Zoeken")
            dismissAction: ActionItem {
                title: qsTr("Annuleren")
                onTriggered: {                    
                    stationList.scrollToPosition(ScrollPosition.Beginning, ScrollAnimation.None);
                    searchTextField.text = ""
                    sheet.close();
                }
            }
        }
        
        Container {
            Container {
                topPadding: 10
                leftPadding: 10
                rightPadding: 10

                TextField {
                    id: searchTextField
                    text: stationVM.filter
                    hintText: qsTr("Station")
                    onTextChanging: stationVM.filter = text
                }
            }

            Container {
                layout: DockLayout {

                }

                ListView {
                    id: stationList
                    layout: StackListLayout {
                        headerMode: ListHeaderMode.Sticky
                    }
                    dataModel: stationVM.dataModel
                    onTriggered: {
                        var str = indexPath.toString();

                        if (str.indexOf(",") != -1) {
                            select(indexPath)
                        }
                    }
                    onSelectionChanged: {
                        if (selected) {
                            stationPicked(dataModel.data(indexPath).name)
                            stationVM.filter = ""

                            scrollToPosition(ScrollPosition.Beginning, ScrollAnimation.None);
                            // Close sheet and clears the selection of the listview
                            sheet.close()

                            clearSelection()
                        }
                    }
                }

                Container {
                    id: messageContainer
                    visible: stationVM.dataModel.size() == 0
                    verticalAlignment: VerticalAlignment.Center
                    horizontalAlignment: HorizontalAlignment.Center
                    leftPadding: 20.0
                    rightPadding: 20.0

                    Label {
                        id: messageTitle
                        text: qsTr("Geen station")
                        textStyle.fontSize: FontSize.XXLarge
                        horizontalAlignment: HorizontalAlignment.Center
                    }
                    Label {
                        id: message
                        text: qsTr("Er is geen station gevonden met uw zoekterm. De taal van de stationsnamen kan u wijzigen bij instellingen.")
                        multiline: true
                        textStyle.textAlign: TextAlign.Center
                    }
                }
            }
        }
        attachedObjects: [
            StationViewModel {
                id: stationVM
                filter: searchTextField.text
                
            }
        ]
    }
    onOpened: {
        searchTextField.requestFocus();
    }
    
    function reload() {
        stationVM.loadStations();
    }
}