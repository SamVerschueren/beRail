/*
 * StationService.hpp
 *
 * Created on: 16-feb.-2013
 * Author: Sam Verschueren      <sam.verschueren@gmail.com>
 */

#ifndef STATIONSERVICE_HPP_
#define STATIONSERVICE_HPP_

#include <QObject>
#include <QSettings>

class StationService: public QObject {
    Q_OBJECT

    signals:
        void findAllStationsCompleted(const QList<QString> &list);

    private:
        QList<QString> resultList;
        QSettings* settings;

    public:
        StationService();
        ~StationService();

        void load();
};

#endif /* STATIONSERVICE_HPP_ */
