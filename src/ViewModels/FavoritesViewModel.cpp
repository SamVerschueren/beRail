/*
 * FavoritesViewModel.cpp
 *
 * Created on: 9-mrt.-2013
 * Author: Sam Verschueren
 */

#include "FavoritesViewModel.hpp"

/**
 * Destroy all the resources and dynamically allocated memory.
 */
FavoritesViewModel::~FavoritesViewModel() {
    delete dataModel;
}

/**
 * This setter is used to do dependency injection of the correct service. This is
 * done to make sure that we work with the same service in all our classes. We want only
 * one object that manipulates the datasource because otherwhise we would have some strange
 * behaviour in our application. The real injection happens in the QML when this viewmodel
 * is being constructed.
 *
 * @param service The FavoriteService that we can work with.
 */
void FavoritesViewModel::setFavoriteService(FavoriteService *service) {
    // Set the service
    this->favoriteService = service;

    // Connect the datachanged signal of the service to the datachanged slot.
    connect(this->favoriteService, SIGNAL(dataChanged(QVariantList)), this, SLOT(favoritesDataChanged(QVariantList)));

    // Start loading the favorites
    this->favoriteService->findAll();
}

/**
 * Returns the datamodel so that it can be used in the view to populate a list
 * easily.
 *
 * @return The GroupDataModel that holds the favorites data.
 */
GroupDataModel* FavoritesViewModel::getDataModel() {
    return dataModel;
}

/**
 * This slot is connected to the dataChanged signal of the FavoritesService and is executed
 * when the data in the service is changed. When the data is changed, we delete
 * all the data in the DataModel and insert the new data.
 *
 * @param favorites The data to be inserted in the datamodel.
 */
void FavoritesViewModel::favoritesDataChanged(const QVariantList &favorites) {
    // clear the data.
    this->dataModel->clear();

    // repopulate the datamodel
    for(int i=0; i<favorites.length(); i++) {
        this->dataModel->insert(favorites[i].toMap());
    }

    emit dataModelChanged(dataModel);
}

/**
 * This method will remove the selected item off of the DataModel and calls
 * the FavoritesService to remove this data out of the datasource.
 */
Q_INVOKABLE void FavoritesViewModel::remove(QVariantList indexPath) {
    QVariantMap map = dataModel->data(indexPath).toMap();

    // TODO How well is the performance of rebuilding the entire datamodel instead of
    // just deleting one??
    //this->dataModel->removeAt(selected);

    this->favoriteService->remove(map["from"].toString(), map["to"].toString());
}
