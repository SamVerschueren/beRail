/*
 * Station.cpp
 *
 * Created on: 16-feb.-2013
 * Author: Sam Verschueren      <sam.verschueren@gmail.com>
 */

#include "Station.hpp"

Station::Station() {

}

Station::Station(const QString &name, const QString &direction, const QDateTime &time, int delay, int platform) {
    this->setName(name);
    this->setDirection(direction);
    this->setTime(time);
    this->setDelay(delay);
    this->setPlatform(platform);
}

void Station::setDirection(const QString &direction) {
    if(this->direction != direction) {
        this->direction = direction;

        emit directionChanged(direction);
    }
}

QString Station::getDirection() const {
    return this->direction;
}

void Station::setName(const QString &name) {
    if(this->name != name) {
        this->name = name;

        emit nameChanged(name);
    }
}

QString Station::getName() const {
    return this->name;
}

void Station::setTime(const QDateTime &time) {
    if(this->time != time) {
        this->time = time;

        emit timeChanged(time);
    }
}

QDateTime Station::getTime() const {
    return this->time;
}

void Station::setDelay(int delay) {
    if(this->delay != delay) {
        this->delay = delay;

        emit delayChanged(platform);
    }
}

int Station::getDelay() const {
    return this->delay;
}

void Station::setPlatform(int platform) {
    if(this->platform != platform) {
        this->platform = platform;

        emit platformChanged(platform);
    }
}

int Station::getPlatform() const {
    return this->platform;
}
