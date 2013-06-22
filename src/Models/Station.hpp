/*
 * Station.hpp
 *
 * Created on: 16-feb.-2013
 * Author: Sam Verschueren      <sam.verschueren@gmail.com>
 */

#ifndef STATION_HPP_
#define STATION_HPP_

#include <QObject>
#include <QTime>

class Station : public QObject {
    Q_OBJECT

    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString direction READ getDirection WRITE setDirection NOTIFY directionChanged)
    Q_PROPERTY(QDateTime time READ getTime WRITE setTime NOTIFY timeChanged)
    Q_PROPERTY(int delay READ getDelay WRITE setDelay NOTIFY delayChanged)
    Q_PROPERTY(int platform READ getPlatform WRITE setPlatform NOTIFY platformChanged)

    Q_SIGNALS:
        void nameChanged(const QString &name);
        void directionChanged(const QString &direction);
        void timeChanged(const QDateTime &time);
        void delayChanged(const int delay);
        void platformChanged(const int platform);

    private:
        QString name;
        QString direction;
        QDateTime time;
        int delay;
        int platform;

    public:
        Station();
        Station(const QString &name, const QString &direction, const QDateTime &time, int delay, int platform);

        void setName(const QString &name);
        QString getName() const;

        void setDirection(const QString &direction);
        QString getDirection() const;

        void setTime(const QDateTime &time);
        QDateTime getTime() const;

        void setDelay(int delay);
        int getDelay() const;

        void setPlatform(int platform);
        int getPlatform() const;
};

#endif /* STATION_HPP_ */
