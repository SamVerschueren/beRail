/*
 * FavoriteService.cpp
 *
 * Created on: 7-mrt.-2013
 * Author: Sam Verschueren      <sam.verschueren@gmail.com>
 */

#include "FavoriteService.hpp"

#include <QDebug>
#include <QDir>
#include <QTemporaryFile>
#include <bb/data/JsonDataAccess>
using namespace bb::data;

/**
 * The destructor will close all the resources and will delete
 * dynamically allocated memory.
 */
FavoriteService::~FavoriteService() {
    // Flush and close the file to make sure that the data is permanent.
    file->flush();
    file->close();

    delete file;
}

/**
 * This method will retrieve all the favorites from the datasource. In this case
 * it's just a JSON file saved on the local harddisk. But it can also be retrieved
 * off of a webservice. When this method is finished, it will emit a signal in order
 * that the FavoritesViewModel can add the data to the GroupDataModel.
 */
void FavoriteService::findAll() {
    if(!isLoaded) {
        if(!file->isOpen() || !file->isReadable()) {
            file->open(QIODevice::ReadOnly);
        }

        JsonDataAccess jda;

        if(file->exists() && file->isOpen()) {
            data = jda.load(file).toList();
        }

        isLoaded = true;
    }

    emit dataChanged(data);
}

/**
 * Adds the route to the favorites of the user. In this case, the favorites
 * are saved in a json file.
 *
 * @param from The start of the route.
 * @param to The end of the route.
 */
void FavoriteService::add(const QString &from, const QString &to) {
    QVariantMap record;
    record["from"] = from;
    record["to"] = to;

    // Add the data to the list
    this->data.append(record);

    // Notify the observers that the data has been changed.
    emit dataChanged(data);

    // Rewrite the file
    this->rewrite();
}

/**
 * This method will remove a favorite station and notifies the
 * observers that the data has been changed.
 *
 * @param from The start of the route.
 * @param to The end of the route.
 */
void FavoriteService::remove(const QString from, const QString to) {
    QVariantMap map;

    for(int i=0; i<data.size(); i++) {
        map = data[i].toMap();

        // Only remove the data when the from and to are in the list
        if(map["from"] == from && map["to"] == to) {
            // Remove the data at the correct position
            data.removeAt(i);

            // notifies the observers
            emit dataChanged(data);

            // Rewrite the data in the file
            this->rewrite();

            return;
        }
    }
}

/**
 * Returns if the route provided is favorited on this device.
 *
 * @param from The start of the route.
 * @param to The end of the route.
 * @return bool True if this route is a favorite; false otherwhise.
 */
bool FavoriteService::isFavorite(const QString &from, const QString &to) {
    for(int i=0; i<data.size(); i++) {
        QVariantMap map = data[i].toMap();

        if(map["from"] == from && map["to"] == to) {
            qDebug() << "FavoriteService::isFavorite YES";

            return true;
        }
    }

    qDebug() << "FavoriteService::isFavorite NO";

    return false;
}

/**
 * This method will rewrite the data in the file on the local storage.
 * If the file exists, it will first remove the file and create the new file.
 * The data is then rewritten to the new file.
 */
void FavoriteService::rewrite() {
    if(file->isOpen() && !file->isWritable()) {
        file->close();
    }

    if(!file->isOpen() || !file->isWritable()) {
        file->open(QIODevice::WriteOnly | QIODevice::Truncate);
    }

    qDebug() << "FavoriteService::rewrite";

    JsonDataAccess jda;

    jda.save(this->data, file);
}
