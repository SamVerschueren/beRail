/*
 * ViaStation.hpp
 *
 *  Created on: 2-apr.-2013
 *      Author: Sam
 */

#ifndef VIASTATION_HPP_
#define VIASTATION_HPP_

#include <QObject>
#include <QDateTime>

class ViaStation : public QObject {
    Q_OBJECT

    Q_SIGNALS:
        void nameChanged(const QString &name);
        void directionChanged(const QString &direction);
        void arrivalTimeChanged(const QDateTime &arrivalTime);
        void arrivalPlatformChanged(const int platform);
        void departureTimeChanged(const QDateTime &departureTime);
        void departurePlatformChanged(const int platform);

    private:
        QString name;
        QString direction;

        QDateTime arrivalTime;
        int arrivalPlatform;

        QDateTime departureTime;
        int departurePlatform;

    public:
        ViaStation(const QString &name, const QString &direction, const QDateTime &arrival, int arrivalPlatform, const QDateTime &departure, int departurePlatform);

        QString getName() const;
        void setName(const QString &name);

        QString getDirection() const;
        void setDirection(const QString &direction);

        QDateTime getArrivalTime() const;
        void setArrivalTime(const QDateTime &arrivalTime);

        int getArrivalPlatform() const;
        void setArrivalPlatform(int arrivalPlatform);

        QDateTime getDepartureTime() const;
        void setDepartureTime(const QDateTime &departureTime);

        int getDeparturePlatform() const;
        void setDeparturePlatform(int departurePlatform);
};

#endif /* VIASTATION_HPP_ */
