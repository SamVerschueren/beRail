/*
 * ConnectionService.cpp
 *
 * The implementation of the <em>ConnectionService</em> class. You can find
 * more information about this class in the <em>ConnectionService</em> header
 * file.
 *
 * Created on: 16-feb.-2013
 * Author: Sam Verschueren      <sam.verschueren@gmail.com>
 */

#include <QNetworkRequest>
#include <bb/data/JsonDataAccess>
#include "ConnectionService.hpp"
using namespace bb::data;

/**
 * Initializes the <em>ConnectionService</em>.
 *
 * @param parent The parent of this object. Most of the time the object that created this object.
 */
ConnectionService::ConnectionService(QObject *parent=0) : QObject(parent) {
    this->networkAccessManager = new QNetworkAccessManager(this);

    // Connect with the finished signal of the networkAccessManager
    connect(this->networkAccessManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(requestFinished(QNetworkReply*)));
}

/**
 * Deletes all the used resources.
 */
ConnectionService::~ConnectionService() {
    delete networkAccessManager;
}

/**
 * Finds 5 connections depending on the paramters passed in this method.
 *
 * @param from The station where you are comming from.
 * @param to The station where you want to go to.
 * @param dateTime The DateTime when you want to depart/arrive.
 * @param type The type that indicates if the time should be seen as departure time or arrival
 *             time. If the type equals to 0, it means departure, if the type equals 1, it means arrival.
 */
void ConnectionService::findConnectionBy(const QString &from, const QString &to, const QDateTime &dateTime, int type) const {
    QString urlDate = dateTime.toString("ddMMyy");
    QString urlTime = dateTime.toString("hhmm");
    QString timeSelector = type==0?"depart":"arrive";
    QString lang = tr("nl");

    // Create a new network request and set the url.
    QNetworkRequest request;
    request.setUrl(QUrl("http://api.irail.be/connections/?format=json&to=" + to + "&from=" + from + "&date=" + urlDate + "&time=" + urlTime + "&timeSel=" + timeSelector + "&lang=" + lang));
    // Execute the request by using the network access manager.
    this->networkAccessManager->get(request);
}

/**
 * This slot is connected with the finished signal of the <em>QNetworkAccessManager</em>.
 * When that signal is emitted, this method will be executed.
 *
 * @param reply The reply that the network access manager returns.
 */
void ConnectionService::requestFinished(QNetworkReply *reply) {
    QList<Connection*> connectionsList;

    if(reply->error() == QNetworkReply::NoError) {
        const QByteArray result(reply->readAll());

        JsonDataAccess jda;

        QVariantMap data = jda.loadFromBuffer(result).toMap();

        QVariantList list = data.value("connection").value<QVariantList>();

        Q_FOREACH(const QVariant &connections, list) {
            Connection *connection = this->toConnection(connections.value<QVariantMap>());

            connectionsList.append(connection);
        }

        emit downloadCompleted(connectionsList, "");
    }
    else {
        emit downloadCompleted(connectionsList, tr("Er is geen netwerk beschikbaar."));
    }
}

/**
 * Converts the data received as parameter, to a real world <em>Connection</em> object.
 * This method will make use of the toStation() method to convert data to a
 * <em>Station</em> object.
 *
 * @param data The data that should be converted to the connection object.
 * @return Connection The Connection object.
 */
Connection* ConnectionService::toConnection(const QVariantMap &data) const {
    int duration = data.value("duration").value<QString>().toInt();
    Station *departure = this->toStation(data.value("departure").value<QVariantMap>());
    Station *arrival = this->toStation(data.value("arrival").value<QVariantMap>());

    QVariantList list = data.value("vias").value<QVariantMap>().value("via").value<QVariantList>();

    Connection *result = new Connection(QTime().addSecs(duration), departure, arrival);

    QList<ViaStation*> tempList;

    for(int i=0; i<list.length(); i++) {
        tempList.append(this->toViaStation(list.at(i).value<QVariantMap>()));
    }

    for(int i=0; i<tempList.length(); i++) {
        ViaStation* firstVia = tempList.at(i);

        if(i < tempList.length()-1) {
            ViaStation* secondVia = tempList.at(i+1);

            firstVia->setDirection(secondVia->getDirection());
        }
        else {
            firstVia->setDirection(arrival->getDirection());
        }

        result->addVia(firstVia);
    }

    return result;
}

/**
 * Converts the data received as parameter, to a real world <em>Station</em> object.
 *
 * @param data The data that should be converted to the station.
 * @return Station The station object.
 */
Station* ConnectionService::toStation(const QVariantMap &data) const {
    QString name = data.value("station").value<QString>();
    QString direction = data.value("direction").value<QVariantMap>().value("name").value<QString>();
    int unixTimestamp = data.value("time").value<QString>().toInt();
    int delay = data.value("delay").value<QString>().toInt();
    int platform = data.value("platform").value<QString>().toInt();

    return new Station(name, direction, QDateTime::fromTime_t(unixTimestamp), delay, platform);
}

/**
 * Converts the data received as parameter to a real world <em>ViaStation</em> object.
 *
 * @param data The data that should be converted to the viastation.
 * @return The ViaStation object.
 */
ViaStation* ConnectionService::toViaStation(const QVariantMap &data) const {
    int arrivalTimestamp = data.value("arrival").value<QVariantMap>().value("time").value<QString>().toInt();
    int departureTimestamp = data.value("departure").value<QVariantMap>().value("time").value<QString>().toInt();

    QString name = data.value("station").value<QString>();
    QString direction = data.value("direction").value<QVariantMap>().value("name").value<QString>();
    QDateTime arrivalTime = QDateTime::fromTime_t(arrivalTimestamp);
    int arrivalPlatform = data.value("arrival").value<QVariantMap>().value("platform").value<QString>().toInt();
    QDateTime departureTime = QDateTime::fromTime_t(departureTimestamp);
    int departurePlatform = data.value("departure").value<QVariantMap>().value("platform").value<QString>().toInt();

    return new ViaStation(name, direction, arrivalTime, arrivalPlatform, departureTime, departurePlatform);
}
