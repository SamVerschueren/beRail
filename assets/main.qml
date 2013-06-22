// Default empty project template
import bb.cascades 1.0
import be.rail.services 1.0

TabbedPane {
    id: rootTabbedPane
    showTabsOnActionBar: true

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

    /*Tab {
        title: qsTr("Liveboard")
        

        Page {
            
        }
    }*/

    Tab {
        title: qsTr("Storingen")
        imageSource: "asset:///images/bb_action_disturbance.png"

        DisruptionPage {
            
        }
    }

    attachedObjects: [
        FavoriteService {
            id: favoriteService
        },
        DisruptionService {
            id: disruptionService
        }
    ]

    function search(from, to) {
        routePage.search(from, to)

        rootTabbedPane.activeTab = routeTab
    }
}