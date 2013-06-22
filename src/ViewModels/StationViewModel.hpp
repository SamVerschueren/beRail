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
	Q_PROPERTY(GroupDataModel* dataModel READ getDataModel)

	Q_SIGNALS:
	    void filterChanged(const QString &filter);

	private:
	    QString filter;
	    GroupDataModel *dataModel;

	    QList<QString> stations;
		StationService stationService;

		void applyFilter();

	public:
		StationViewModel(QObject *parent=0) : QObject(parent), stationService(this) {
		    dataModel = new GroupDataModel(QStringList() << "name");
		}
		~StationViewModel();

		QString getFilter() const;
		void setFilter(const QString &filter);
		GroupDataModel* getDataModel();

	private slots:
	    void findAllStationsCompleted(const QList<QString> &stations);
};

#endif /* STATIONVIEWMODEL_HPP_ */
