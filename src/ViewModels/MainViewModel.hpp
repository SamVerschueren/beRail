/*
 * MainViewModel.hpp
 *
 * Created on: 21-jul.-2013
 * Author: Sam Verschueren		<sam.verschueren@gmail.com>
 */

#ifndef MAINVIEWMODEL_HPP_
#define MAINVIEWMODEL_HPP_

#include <QObject>
#include <QSettings>

class MainViewModel : public QObject {
    Q_OBJECT

    Q_PROPERTY(int stationLanguage READ getStationLanguage WRITE setStationLanguage FINAL)

    private:
        QSettings* settings;

    public:
        MainViewModel();
        ~MainViewModel();

        int getStationLanguage();
        void setStationLanguage(int option);

    signals:
        void stationLanguageChanged(int option);
};

#endif /* MAINVIEWMODEL_HPP_ */
