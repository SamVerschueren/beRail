/*
 * Connection.cpp
 *
 * Created on: 16-feb.-2013
 * Author: Sam Verschueren      <sam.verschueren@gmail.com>
 */

#include <QDebug>
#include "Connection.hpp"

Connection::Connection(const QTime &duration, Station *departure, Station *arrival) :
    duration(duration), departure(departure), arrival(arrival)
{

}

Connection::~Connection() {
    delete departure;
    delete arrival;

    for(int i=0; i<vias.size(); i++) {
        delete vias.at(i);
    }
}

void Connection::setDuration(const QTime &duration) {
    if(this->duration != duration) {
        this->duration = duration;

        emit durationChanged(duration);
    }
}

QTime Connection::getDuration() const {
    return this->duration;
}

void Connection::setDeparture(Station *departure) {
    if(this->departure != departure) {
        this->departure = departure;

        emit departureChanged(departure);
    }
}

Station* Connection::getDeparture() const {
    return this->departure;
}

void Connection::setArrival(Station* arrival) {
    if(this->arrival != arrival) {
        this->arrival = arrival;

        emit arrivalChanged(arrival);
    }
}

Station* Connection::getArrival() const {
    return this->arrival;
}

void Connection::addVia(ViaStation* via) {
    this->vias.append(via);
}

Q_INVOKABLE int Connection::countVias() const {
    return this->vias.size();
}

Q_INVOKABLE QVariant Connection::getViaAt(int index) const {
    ViaStation* via = this->vias.at(index);

    QMap<QString, QVariant> map;
    map["direction"] = via->getDirection();
    map["name"] = via->getName();
    map["arrivalTime"] = via->getArrivalTime().toString("hh:mm");
    map["arrivalPlatform"] = via->getArrivalPlatform() == 0 ? "-" : QString::number(via->getArrivalPlatform());
    map["departureTime"] = via->getDepartureTime().toString("hh:mm");
    map["departurePlatform"] = via->getDeparturePlatform() == 0 ? "-" : QString::number(via->getDeparturePlatform());

    return map;
}
