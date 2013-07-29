/*
 * MainViewModel.cpp
 *
 * Created on: 21-jul.-2013
 * Author: Sam Verschueren		<sam.verschueren@gmail.com>
 */

#include <QDebug>
#include "MainViewModel.hpp"

MainViewModel::MainViewModel() {
    this->settings = new QSettings("samver", "beRail", this);
}

MainViewModel::~MainViewModel() {
    delete settings;
}

int MainViewModel::getStationLanguage() {
    qDebug() << tr("nl");

    QString lang = settings->value("stationlang", tr("nl")).toString();

    if(lang == "nl") return 0;
    if(lang == "en") return 1;
    if(lang == "fr") return 2;
    if(lang == "de") return 3;

    return 0;
}

void MainViewModel::setStationLanguage(int option) {
    switch(option) {
        case 0:
            settings->setValue("stationlang", "nl");
            break;
        case 1:
            settings->setValue("stationlang", "en");
            break;
        case 2:
            settings->setValue("stationlang", "fr");
            break;
        case 3:
            settings->setValue("stationlang", "de");
            break;
    }

    emit stationLanguageChanged(option);
}
