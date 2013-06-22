/*
 * Connection.hpp
 *
 * Created on: 16-feb.-2013
 * Author: Sam Verschueren      <sam.verschueren@gmail.com>
 */

#ifndef CONNECTION_HPP_
#define CONNECTION_HPP_

#include <QObject>
#include <QVariant>
#include "Station.hpp"
#include "ViaStation.hpp"

class Connection : public QObject {
    Q_OBJECT

    Q_PROPERTY(QTime duration READ getDuration)
    Q_PROPERTY(Station* departure READ getDeparture)
    Q_PROPERTY(Station* arrival READ getArrival)

    Q_SIGNALS:
        void durationChanged(const QTime &duration);
        void departureChanged(const Station *station);
        void arrivalChanged(const Station *station);

    private:
        QTime duration;
        Station *departure;
        Station *arrival;

        QList<ViaStation*> vias;

    public:
        Connection(const QTime &duration, Station *departure, Station *arrival);
        ~Connection();

        void setDuration(const QTime &duration);
        QTime getDuration() const;

        void setDeparture(Station *departure);
        Station *getDeparture() const;

        void setArrival(Station *arrival);
        Station *getArrival() const;

        void addVia(ViaStation *via);

        Q_INVOKABLE int countVias() const;
        Q_INVOKABLE QVariant getViaAt(int index) const;
};

#endif /* CONNECTION_HPP_ */
