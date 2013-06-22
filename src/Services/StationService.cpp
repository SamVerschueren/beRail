/*
 * StationService.cpp
 *
 * Created on: 16-feb.-2013
 * Author: Sam Verschueren      <sam.verschueren@gmail.com>
 */

#include <QDebug>
#include <bb/data/JsonDataAccess>
#include "StationService.hpp"
using namespace bb::data;

/**
 * Creates a new instance of the <em>StationService</em>.
 *
 * @param parent The parent object. Mostly the object that created this one.
 */
StationService::StationService(QObject *parent = 0) : QObject(parent) {

}

/**
 * Delete all the resources used in the applicaton.
 */
StationService::~StationService() {

}

/**
 * Loads the data from the datasource. The datasource bould be a regular
 * json file, or it could be data from the server.
 *
 * When the data is loaded, the findAllStationsCompleted signal is emitted.
 */
void StationService::load() {
    JsonDataAccess jda;

    QString fileName = tr("stations.json");

    QVariantMap data = jda.load("app/native/assets/data/" + fileName).toMap();

    QVariantList l = data.value("station").value<QVariantList>();

    Q_FOREACH(const QVariant &station, l) {
        QString name(station.value<QVariantMap>().value("name").value<QString>());

        resultList.append(name);
    }

    emit findAllStationsCompleted(resultList);
}
