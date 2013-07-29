import bb.cascades 1.0
import be.rail.viewmodels 1.0
import be.rail.services 1.0

TabbedPane {
    id: rootTabbedPane
    showTabsOnActionBar: true

    Menu.definition: MenuDefinition {
        settingsAction: SettingsActionItem {
           onTriggered: {
               settingsSheet.open();
           }
        }
    }

    Tab {
        id: routeTab
        title: qsTr("Route")
        imageSource: "asset:///images/bb_action_search.png"

        RoutePage {
            id: routePage
        }
    }

    Tab {
        title: qsTr("Favorieten")
        imageSource: "asset:///images/bb_action_favorite.png"

        FavoritesPage {
            id: favoritePage
        }
    }

    Tab {
        title: qsTr("Storingen")
        imageSource: "asset:///images/bb_action_disturbance.png"

        DisruptionPage {
            
        }
    }

    attachedObjects: [
        MainViewModel {
            id: mainViewModel
            onStationLanguageChanged: {
                stationSheet.reload();
            }
        },
        StationPicker {
            id: stationSheet
        },
        FavoriteService {
            id: favoriteService
        },
        DisruptionService {
            id: disruptionService
        },
        SettingsSheet {
            id: settingsSheet
        }
    ]

    function search(from, to) {
        routePage.search(from, to)

        rootTabbedPane.activeTab = routeTab
    }
}