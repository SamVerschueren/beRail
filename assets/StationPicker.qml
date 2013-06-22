import bb.cascades 1.0
import be.rail.viewmodels 1.0

Sheet {
    id: sheet
    signal stationPicked(string value)
    
    Page {
        id: pickerPage
        titleBar: TitleBar {
            title: qsTr("Station")
            dismissAction: ActionItem {
                title: qsTr("Annuleren")
                onTriggered: {
                    stationList.scrollToPosition(ScrollPosition.Beginning, ScrollAnimation.None);

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
                    hintText: qsTr("Filter")
                    onTextChanging: stationVM.filter = text
                }
            }

            ListView {
                id: stationList
                layout: StackListLayout {
                    headerMode: ListHeaderMode.Sticky
                }
                dataModel: stationVM.dataModel
                onTriggered: {
                    var str = indexPath.toString();
                    
                    if(str.indexOf(",") != -1) {
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
}