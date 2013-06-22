/*
 * RouteViewModel.hpp
 *
 * Created on: 10-feb.-2013
 * Author: Sam Verschueren		<sam.verschueren@gmail.com>
 */
#ifndef ROUTEVIEWMODEL_HPP_
#define ROUTEVIEWMODEL_HPP_

#include "ConnectionService.hpp"
#include "FavoriteService.hpp"

#include <QObject>
#include <QDate>
#include <bb/cascades/GroupDataModel>
using namespace bb::cascades;

class RouteViewModel : public QObject {
	Q_OBJECT

	Q_PROPERTY(QString from READ getFrom WRITE setFrom NOTIFY fromChanged FINAL)
	Q_PROPERTY(QString to READ getTo WRITE setTo NOTIFY toChanged FINAL)
	Q_PROPERTY(QDate date READ getDate WRITE setDate NOTIFY dateChanged FINAL)
	Q_PROPERTY(QTime time READ getTime WRITE setTime NOTIFY timeChanged FINAL)
	Q_PROPERTY(int type READ getType WRITE setType NOTIFY typeChanged FINAL)
	Q_PROPERTY(bool favorite READ isFavorite WRITE setFavorite NOTIFY favoriteChanged FINAL)
	Q_PROPERTY(GroupDataModel* resultDataModel READ getResultDataModel NOTIFY dataModelChanged)
	Q_PROPERTY(Connection* selectedItem READ getSelectedItem NOTIFY selectionChanged)

	Q_PROPERTY(FavoriteService* service WRITE setFavoriteService)

	Q_SIGNALS:
	    void fromChanged(const QString &from);
	    void toChanged(const QString &to);
	    void dateChanged(const QDate &date);
	    void timeChanged(const QTime &time);
	    void typeChanged(int type);
	    void favoriteChanged(bool favorite);
	    void dataModelChanged(GroupDataModel *dataModel);
	    void selectionChanged(Connection *connection);

	    void searchCompleted(const QString &error);

	    void netwerkError(const QString &error);

	private:
		QString from;
		QString to;
		QDate date;
		QTime time;
		int type;
		bool favorite;

		Connection* selectedItem;

		ConnectionService connectionService;
		FavoriteService *favoriteService;
		GroupDataModel *resultDataModel;

	private slots:
	    void downloadCompleted(const QList<Connection*> &connections, const QString &error);

	public:
	    RouteViewModel(QObject *parent = 0) : QObject(parent), connectionService(this) {
	        connect(&this->connectionService, SIGNAL(downloadCompleted(QList<Connection*>, QString)), this, SLOT(downloadCompleted(QList<Connection*>, QString)));

	        resultDataModel = new GroupDataModel();
	        resultDataModel->setGrouping(ItemGrouping::None);
	    }

	    ~RouteViewModel();

	    QString getFrom() const;
	    void setFrom(const QString &from);

	    QString getTo() const;
	    void setTo(const QString &to);

	    QDate getDate() const;
	    void setDate(const QDate &date);

	    QTime getTime() const;
	    void setTime(const QTime &time);

	    int getType() const;
	    void setType(int type);

	    bool isFavorite() const;
	    void setFavorite(bool favorite);

	    Connection* getSelectedItem() const;
	    void setSelectedItem(Connection *connection);

	    GroupDataModel* getResultDataModel();
	    void setFavoriteService(FavoriteService *service);

		Q_INVOKABLE void search();
		Q_INVOKABLE void favoriteMe();
		Q_INVOKABLE void select(const QVariantList &index);
};

#endif /* ROUTEVIEWMODEL_HPP_ */
