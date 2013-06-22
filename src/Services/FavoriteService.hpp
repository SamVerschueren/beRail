/*
 * FavoriteService.hpp
 *
 * This service will retrieve all the favorite routes of the user. In this case, this
 * is done from the local file system. We just save a JSON file on the disk with the data
 * but it's also possible to do it with a database on the device. I thought a database would be
 * overkill because people will never save more than 10 favorites I guess.
 *
 * This service offers a create, read and delete function to the programmer who wants to use this
 * service.
 *
 * Created on: 7-mrt.-2013
 * Author: Sam Verschueren      <sam.verschueren@gmail.com>
 */

#ifndef FAVORITESERVICE_HPP_
#define FAVORITESERVICE_HPP_

#include <QObject>
#include <QVariantList>
#include <QDir>
#include "DisruptionService.hpp"

class FavoriteService : public QObject {
    Q_OBJECT

    signals:
        void dataChanged(const QVariantList &favorites);

    private:
        QFile *file;
        QVariantList data;
        bool isLoaded;

        void rewrite();

    public:
        FavoriteService(QObject *parent=0) : QObject(parent), isLoaded(false) {
            QDir home = QDir::home();

            file = new QFile(home.absoluteFilePath("favorites.json"));

            DisruptionService* service = new DisruptionService();
            service->findAll();
        }
        ~FavoriteService();

        void findAll();
        void add(const QString &from, const QString &to);
        void remove(const QString from, const QString to);
        bool isFavorite(const QString &from, const QString &to);
};

#endif /* FAVORITESERVICE_HPP_ */
