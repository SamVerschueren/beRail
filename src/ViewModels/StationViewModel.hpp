/*
 * StationViewModel.hpp
 *
 * Created on: 8-feb.-2013
 * Author: Sam Verschueren		<sam.verschueren@gmail.com>
 */
#ifndef STATIONVIEWMODEL_HPP_
#define STATIONVIEWMODEL_HPP_

#include <QObject>
#include <bb/cascades/GroupDataModel>
#include "StationService.hpp"
using namespace bb::cascades;

class StationViewModel : public QObject {
	Q_OBJECT

	Q_PROPERTY(QString filter READ getFilter WRITE setFilter NOTIFY filterChanged FINAL)
	Q_PROPERTY(GroupDataModel* dataModel READ getDataModel NOTIFY dataModelChanged FINAL)

	Q_SIGNALS:
	    void filterChanged(const QString &filter);
	    void dataModelChanged(GroupDataModel* dataModel);

	private:
	    QString filter;
	    GroupDataModel *dataModel;

	    QList<QString> stations;
		StationService* stationService;

		void applyFilter();

	public:
		StationViewModel();
		~StationViewModel();

		QString getFilter() const;
		void setFilter(const QString &filter);

		GroupDataModel* getDataModel();

		Q_INVOKABLE void loadStations();

	private slots:
	    void findAllStationsCompleted(const QList<QString> &stations);
};

#endif /* STATIONVIEWMODEL_HPP_ */
