// Default empty project template
#include "BeRail.hpp"

#include <bb/cascades/Application>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/AbstractPane>
#include "StationViewModel.hpp"
#include "RouteViewModel.hpp"
#include "FavoritesViewModel.hpp"
#include "FavoriteService.hpp"
#include "DisruptionService.hpp"
#include "DisruptionsViewModel.hpp"
#include "ViaStation.hpp"
using namespace bb::cascades;

BeRail::BeRail(bb::cascades::Application *app) : QObject(app)
{
    qmlRegisterType<StationViewModel>("be.rail.viewmodels", 1, 0, "StationViewModel");
    qmlRegisterType<RouteViewModel>("be.rail.viewmodels", 1, 0, "RouteViewModel");
    qmlRegisterType<FavoritesViewModel>("be.rail.viewmodels", 1, 0, "FavoritesViewModel");
    qmlRegisterType<DisruptionsViewModel>("be.rail.viewmodels", 1, 0, "DisruptionsViewModel");

    qmlRegisterType<FavoriteService>("be.rail.services", 1, 0, "FavoriteService");
    qmlRegisterType<DisruptionService>("be.rail.services", 1, 0, "DisruptionService");

    qRegisterMetaType<QObject*>("Station*");
    qRegisterMetaType<GroupDataModel*>("GroupDataModel*");
    qRegisterMetaType<QObject*>("Connection*");
    qRegisterMetaType<QObject*>("ViaStation*");

    // create scene document from main.qml asset
    // set parent to created document to ensure it exists for the whole application lifetime
    QmlDocument *qml = QmlDocument::create("asset:///main.qml").parent(this);
    // create root object for the UI
    AbstractPane *root = qml->createRootObject<AbstractPane>();
    // set created root object as a scene
    app->setScene(root);
}
