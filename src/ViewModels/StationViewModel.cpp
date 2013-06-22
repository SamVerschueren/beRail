/*
 * StationViewModel.cpp
 *
 * Created on: 8-feb.-2013
 * Author: Sam Verschueren		<sam.verschueren@gmail.com>
 */
#include "StationViewModel.hpp"

StationViewModel::~StationViewModel() {
    delete dataModel;
}

/**
 * Returns a pointer to the <em>GroupDataModel</em>. If the data is loaded,
 * the service will not be asked to load the data again. If this is the
 * first time that the UI asks for the data model, the service is asked
 * the load the data. The ViewModel does not know where the data comes
 * from, it could be either from a file or from the server. This method connects
 * with the signal from the service that is emitted when the data is loaded.
 *
 * @return The datamodel that can be shown in the UI.
 */
GroupDataModel* StationViewModel::getDataModel() {
    // If the viewmodel does not have any stations yet, start loading them
    if(stations.size() == 0) {
        connect(&stationService, SIGNAL(findAllStationsCompleted(QList<QString>)), this, SLOT(findAllStationsCompleted(QList<QString>)));
        stationService.load();
    }

    return dataModel;
}

/**
 * Returns the filter that is applied on the data.
 *
 * @return The filter string that is applied.
 */
QString StationViewModel::getFilter() const {
    return filter;
}

/**
 * Sets the string provided as the filter to filter the data. When
 * the filter is not the same as the previous filter, the filterChanged
 * signal is emitted and the filter is applied on the data.
 *
 * @param filter The string to filter on.
 */
void StationViewModel::setFilter(const QString &filter) {
    if(this->filter != filter) {
        this->filter = filter;

        emit filterChanged(filter);

        applyFilter();
    }
}

/**
 * This method is called when the stations are loaded from the server or
 * from a file on the device.
 *
 * @param stations The <em>QList</em> with all the names of the stations.
 */
void StationViewModel::findAllStationsCompleted(const QList<QString> &stations) {
    this->stations = stations;

    disconnect(&stationService, SIGNAL(findAllStationsCompleted(QList<QString>)), this, SLOT(findAllStationsCompleted(QList<QString>)));

    Q_FOREACH(const QString &name, stations) {
        QVariantMap map;
        map["name"] = name;

        dataModel->insert(map);
    }
}

/**
 * Applies the filter on the data. It clears the model and repopulate it
 * with data that matches the filter.
 */
void StationViewModel::applyFilter() {
    dataModel->clear();

    Q_FOREACH(const QString &name, stations) {
        if(name.indexOf(filter.trimmed(), 0, Qt::CaseInsensitive) != -1) {
            QVariantMap map;
            map["name"] = name;

            dataModel->insert(map);
        }
    }
}
