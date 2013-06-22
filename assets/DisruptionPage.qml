import bb.cascades 1.0
import be.rail.viewmodels 1.0

Page {
    Container {
        layout: DockLayout {
        }

        ActivityIndicator {
            id: activityIndicator
            verticalAlignment: VerticalAlignment.Center
            horizontalAlignment: HorizontalAlignment.Center
            preferredWidth: 200
            preferredHeight: 200
            visible: true
            running: true
        }
        
        ListView {
            id: favoriteList
            dataModel: disruptionsVM.dataModel
            listItemComponents: [
                ListItemComponent {
                    type: "item"

                    Container {
                        background: ListItem.active ? Color.create("#CC00A8DF") : (ListItem.selected ? Color.create("#00A8DF") : Color.Transparent)

                        contextActions: [
                            ActionSet {
                                title: qsTr("Storing")
                                subtitle: ListItemData.title
                                actions: [
                                    InvokeActionItem {
                                        id: invoker
                                        data: ListItemData.title + " #beRail"
                                        query {
                                            mimeType: "text/plain"
                                            invokeActionId: "bb.action.SHARE"
                                        }
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
                            layout: StackLayout { }
                            
                            Label {
                                text: ListItemData.title
                                multiline: true
                                textStyle.fontWeight: FontWeight.W400
                            }
                            
                            Label {
                                text: ListItemData.description
                                multiline: true
                                textStyle.fontWeight: FontWeight.W100
                            }
                            
                            Label {
                                text: Qt.formatDateTime(ListItemData.date, "dd MMM yyyy hh:mm")
                                horizontalAlignment: HorizontalAlignment.Right
                                textStyle.color: Color.Gray
                                textStyle.fontWeight: FontWeight.W100
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
        }

        Container {
            id: messageContainer
            visible: false
            verticalAlignment: VerticalAlignment.Center
            horizontalAlignment: HorizontalAlignment.Center
            leftPadding: 20.0
            rightPadding: 20.0

            Label {
                id: messageTitle
                text: qsTr("Geen storingen")
                textStyle.fontSize: FontSize.XXLarge
                horizontalAlignment: HorizontalAlignment.Center
            }
            Label {
                id: message
                text: qsTr("Geen belangrijke storingen op het netwerk.")
                multiline: true
                textStyle.textAlign: TextAlign.Center
            }
        }
    }
    
    attachedObjects: [
        DisruptionsViewModel {
            id: disruptionsVM
            service: disruptionService
            onCompleted: {
                activityIndicator.running = false;
                activityIndicator.visible = false;

                console.log(disruptionsVM.dataModel.size());

                if(error == "") {
                    messageContainer.visible = disruptionsVM.dataModel.size() == 0
                }
                else {
                    messageTitle.text = qsTr("Netwerkfout")
                    message.text = qsTr("Er is geen netwerk beschikbaar.")
                    
                    messageContainer.visible = true
                }
            }
        }
    ]
}
