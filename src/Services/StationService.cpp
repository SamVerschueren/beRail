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
StationService::StationService() {
    this->settings = new QSettings("samver", "beRail", this);
}

/**
 * Delete all the resources used in the applicaton.
 */
StationService::~StationService() {
    delete settings;
}

/**
 * Loads the data from the datasource. The datasource would be a regular
 * json file, or it could be data from the server.
 *
 * When the data is loaded, the findAllStationsCompleted signal is emitted.
 */
void StationService::load() {
    JsonDataAccess jda;

    QString fileName = QString("stations_%1.json").arg(settings->value("stationlang", tr("nl")).toString());

    QVariantMap data = jda.load("app/native/assets/data/" + fileName).toMap();

    QVariantList l = data.value("station").value<QVariantList>();

    resultList.clear();

    foreach(const QVariant &station, l) {
        QString name(station.value<QVariantMap>().value("name").value<QString>());

        resultList.append(name);
    }

    emit findAllStationsCompleted(resultList);
}
