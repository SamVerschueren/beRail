import bb.cascades 1.0

Page {
    titleBar: TitleBar {
        title: routeVM.selectedItem.departure.name + " - " + routeVM.selectedItem.arrival.name
    }
    ScrollView {
        Container {
            leftPadding: 10.0
            topPadding: 10.0
            rightPadding: 20.0
            bottomPadding: 10.0
    
            Container {
                preferredHeight: 60
                layout: StackLayout {
                    orientation: LayoutOrientation.LeftToRight
                }

                ImageView {
                    imageSource: "asset:///images/start.png"
                    preferredHeight: 60
                    preferredWidth: 60
                }
    
                Label {
                    text: routeVM.selectedItem.departure.name
                    layoutProperties: StackLayoutProperties {
                        spaceQuota: 1.0
                    }
                }

                Label {
                    text: Qt.formatDateTime(routeVM.selectedItem.departure.time, "hh:mm")
                }

                Label {
                    text: "+" + (routeVM.selectedItem.departure.delay / 60)
                    textStyle.color: Color.Red
                    visible: routeVM.selectedItem.departure.delay != 0
                }
    
                Label {
                    text: routeVM.selectedItem.departure.platform == 0 ? "-" : routeVM.selectedItem.departure.platform
                    preferredWidth: 100
                    textStyle.textAlign: TextAlign.Right
                }
            }
    
            Container {
                id: viaContainer
            }
    
            Container {
                preferredHeight: 61
                layout: StackLayout {
                    orientation: LayoutOrientation.LeftToRight
                }
                
                ImageView {
                    imageSource: "asset:///images/end.png"
                    preferredHeight: 60
                    preferredWidth: 60
                }
    
                Label {
                    text: routeVM.selectedItem.arrival.name
                    layoutProperties: StackLayoutProperties {
                        spaceQuota: 1.0
                    }
                }
    
                Label {
                    text: Qt.formatDateTime(routeVM.selectedItem.arrival.time, "hh:mm")
                }
    
                Label {
                    text: routeVM.selectedItem.arrival.platform == 0 ? "-" : routeVM.selectedItem.arrival.platform
                    preferredWidth: 100
                    textStyle.textAlign: TextAlign.Right
                }
            }
        }
        onCreationCompleted: {
            var directionObject = directionComponent.createObject();
            directionObject.direction = routeVM.selectedItem.departure.direction
            viaContainer.add(directionObject)
    
            var totalVias = routeVM.selectedItem.countVias()

            var item;

            for(var i=0; i<totalVias; i++) {
                item = routeVM.selectedItem.getViaAt(i);

                var via = viaStation.createObject();
                via.via = item

                viaContainer.add(via)

                var directionObject = directionComponent.createObject();
                directionObject.direction = item.direction
    
                viaContainer.add(directionObject)
            }
        }
        attachedObjects: [
            ComponentDefinition {
                id: viaStation
    
                Container {
                    property variant via
    
                    preferredHeight: 60
                    horizontalAlignment: HorizontalAlignment.Fill
                    layout: StackLayout {
                        orientation: LayoutOrientation.LeftToRight
                    }
    
                    ImageView {
                        imageSource: "asset:///images/mid.png"
                    }
    
                    Label {
                        text: via.name
                        layoutProperties: StackLayoutProperties {
                            spaceQuota: 1.0
                        }
                        verticalAlignment: VerticalAlignment.Center
                    }

                    Label {
                        text: via.departureTime
                    }

                    Label {
                        text: via.departurePlatform
                        preferredWidth: 100
                        textStyle.textAlign: TextAlign.Right
                    }
                    /*Container {
                        Label {
                            text: via.arrivalTime
                        }

                        Label {
                            text: via.departureTime
                        }
                    }

                    Container {
                        preferredWidth: 100

                        Label {
                            text: via.arrivalPlatform
                            preferredWidth: 100
                            textStyle.textAlign: TextAlign.Right
                        }

                        Label {
                            text: via.departurePlatform
                            preferredWidth: 100
                            textStyle.textAlign: TextAlign.Right
                        }
                    }*/
                }
            },
            ComponentDefinition {
                id: directionComponent
    
                Container {
                    property string direction
    
                    preferredHeight: 60
                    horizontalAlignment: HorizontalAlignment.Fill
                    layout: StackLayout {
                        orientation: LayoutOrientation.LeftToRight
                    }
    
                    ImageView {
                        imageSource: "asset:///images/direction.png"
                    }
    
                    Label {
                        text: direction
                        textStyle.fontSize: FontSize.XSmall
                        textStyle.fontStyle: FontStyle.Italic
                        textStyle.color: Color.Gray
                    }
                }
            }
        ]
    }
}
