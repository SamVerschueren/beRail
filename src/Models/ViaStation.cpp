/*
 * ViaStation.cpp
 *
 *  Created on: 2-apr.-2013
 *      Author: Sam
 */

#include "ViaStation.hpp"

ViaStation::ViaStation(const QString &name, const QString &direction, const QDateTime &arrival, int arrivalPlatform, const QDateTime &departure, int departurePlatform) {
    this->setName(name);
    this->setDirection(direction);
    this->setArrivalTime(arrival);
    this->setArrivalPlatform(arrivalPlatform);
    this->setDepartureTime(departure);
    this->setDeparturePlatform(departurePlatform);
}

QString ViaStation::getName() const {
    return this->name;
}

void ViaStation::setName(const QString &name) {
    if(this->name != name) {
        this->name = name;

        emit nameChanged(name);
    }
}

QString ViaStation::getDirection() const {
    return this->direction;
}

void ViaStation::setDirection(const QString &direction) {
    if(this->direction != direction) {
        this->direction = direction;

        emit directionChanged(direction);
    }
}

QDateTime ViaStation::getArrivalTime() const {
    return this->arrivalTime;
}

void ViaStation::setArrivalTime(const QDateTime &arrivalTime) {
    if(this->arrivalTime != arrivalTime) {
        this->arrivalTime = arrivalTime;

        emit arrivalTimeChanged(arrivalTime);
    }
}

int ViaStation::getArrivalPlatform() const {
    return this->arrivalPlatform;
}

void ViaStation::setArrivalPlatform(int arrivalPlatform) {
    if(this->arrivalPlatform != arrivalPlatform) {
        this->arrivalPlatform = arrivalPlatform;

        emit arrivalPlatformChanged(arrivalPlatform);
    }
}

QDateTime ViaStation::getDepartureTime() const {
    return this->departureTime;
}

void ViaStation::setDepartureTime(const QDateTime &departureTime) {
    if(this->departureTime != departureTime) {
        this->departureTime = departureTime;

        emit departureTimeChanged(departureTime);
    }
}

int ViaStation::getDeparturePlatform() const {
    return this->departurePlatform;
}

void ViaStation::setDeparturePlatform(int departurePlatform) {
    if(this->departurePlatform != departurePlatform) {
        this->departurePlatform = departurePlatform;

        emit departurePlatformChanged(departurePlatform);
    }
}
