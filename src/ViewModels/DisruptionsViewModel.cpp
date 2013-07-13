/*
 * DisruptionsViewModel.cpp
 *
 * Created on: 21-mrt.-2013
 * Author: Sam Verschueren      <sam.verschueren@gmail.com>
 */

#include "DisruptionsViewModel.hpp"

DisruptionsViewModel::~DisruptionsViewModel() {
    delete dataModel;
}

void DisruptionsViewModel::setDisruptionService(DisruptionService* service) {
    this->service = service;

    connect(service, SIGNAL(downloadCompleted(QList<Disruption*>, QString)), this, SLOT(downloadCompleted(QList<Disruption*>, QString)));

    this->service->findAll();
}

/**
 * Returns the datamodel so that it can be used in the view to populate a list
 * easily.
 *
 * @return The GroupDataModel that holds the disruption data.
 */
GroupDataModel* DisruptionsViewModel::getDataModel() {
    return dataModel;
}

void DisruptionsViewModel::downloadCompleted(const QList<Disruption*> &disruptions, const QString &error) {
    for(int i=0; i<disruptions.length(); i++) {
        this->dataModel->insert(disruptions.at(i));
    }

    emit dataModelChanged(this->dataModel);

    qDebug() << "downloadcompleted";
    emit completed(error);
}
