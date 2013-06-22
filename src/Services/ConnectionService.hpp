/*
 * ConnectionService.hpp
 *
 * The header file that describes all the methods and stuff for the
 * ConnectionService.
 *
 * The ConnectionService knows how to download and process the data
 * concerning a connection between two stations. It has a signal method
 * that is emitted when the download and processing of the data is
 * completed.
 *
 * Created on: 16-feb.-2013
 * Author: Sam Verschueren      <sam.verschueren@gmail.com>
 */

#ifndef CONNECTIONSERVICE_HPP_
#define CONNECTIONSERVICE_HPP_

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QList>
#include "Station.hpp"
#include "ViaStation.hpp"
#include "Connection.hpp"

class ConnectionService : public QObject {
    Q_OBJECT

    signals:
        void downloadCompleted(const QList<Connection*> &connections, const QString &error);

    private:
        QNetworkAccessManager *networkAccessManager;

        // private methods
        Connection* toConnection(const QVariantMap &data) const;
        Station* toStation(const QVariantMap &data) const;
        ViaStation* toViaStation(const QVariantMap &data) const;

    public:
        ConnectionService(QObject *parent);
        ~ConnectionService();

        void findConnectionBy(const QString &from, const QString &to, const QDateTime &dateTime, int type) const;

    private slots:
        void requestFinished(QNetworkReply *reply);
};

#endif /* CONNECTIONSERVICE_HPP_ */
