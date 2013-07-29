import bb.cascades 1.0

Sheet {
    id: settingsSheet
    Page {
        titleBar: TitleBar {
            title: qsTr("Instellingen")
            acceptAction: ActionItem {
                title: qsTr("Opslaan")
                onTriggered: {
                    settingsSheet.close()
                }
            }
        }
        Container {
            topPadding: 20.0
            DropDown {
                id: stationLanguage
                title: qsTr("Stationsnamen")
                horizontalAlignment: HorizontalAlignment.Center
                selectedIndex: mainViewModel.stationLanguage
                onSelectedIndexChanged: {
                    mainViewModel.stationLanguage = selectedIndex
                }
                options: [
                    Option {
                        text: "Nederlands"
                    },
                    Option {
                        text: "English"
                    },
                    Option {
                        text: "Français"
                    },
                    Option {
                        text: "Deutsch"
                    }
                ]
            }
        }
    }
}