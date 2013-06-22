/*
 * RouteViewModel.cpp
 *
 * Created on: 10-feb.-2013
 * Author: Sam Verschueren		<sam.verschueren@gmail.com>
 */

#include <QDebug>
#include "RouteViewModel.hpp"

RouteViewModel::~RouteViewModel() {
    delete resultDataModel;
}

QString RouteViewModel::getFrom() const {
    return this->from;
}

void RouteViewModel::setFrom(const QString &from) {
    if(this->from != from) {
        this->from = from;

        emit fromChanged(from);
    }
}

QString RouteViewModel::getTo() const {
    return this->to;
}

void RouteViewModel::setTo(const QString &to) {
    if(this->to != to) {
        this->to = to;

        emit toChanged(to);
    }
}

QDate RouteViewModel::getDate() const {
    return this->date;
}

void RouteViewModel::setDate(const QDate &date) {
    if(this->date != date) {
        this->date = date;

        emit dateChanged(date);
    }
}

QTime RouteViewModel::getTime() const {
    return this->time;
}

void RouteViewModel::setTime(const QTime &time) {
    if(this->time != time) {
        this->time = time;

        emit timeChanged(time);
    }
}

int RouteViewModel::getType() const {
    return this->type;
}

void RouteViewModel::setType(int type) {
    if(this->type != type) {
        this->type = type;

        emit typeChanged(type);
    }
}

bool RouteViewModel::isFavorite() const {
    return this->favorite;
}

void RouteViewModel::setFavorite(bool favorite) {
    if(this->favorite != favorite) {
        this->favorite = favorite;

        emit favoriteChanged(favorite);
    }
}

Connection* RouteViewModel::getSelectedItem() const {
    return this->selectedItem;
}

void RouteViewModel::setSelectedItem(Connection *connection) {
    this->selectedItem = connection;

    emit selectionChanged(connection);
}

GroupDataModel* RouteViewModel::getResultDataModel() {
    return this->resultDataModel;
}

void RouteViewModel::setFavoriteService(FavoriteService *service) {
    this->favoriteService = service;
}

/**
 * This method will be fired when the <em>ConnectionService</em> is done
 * downloading and processing the data.
 *
 * @param connections A <em>QList</em> that holds all pointers to the connection objects.
 * @param error The error message that occurs when the search could not be completed
 */
void RouteViewModel::downloadCompleted(const QList<Connection*> &connections, const QString &error) {
    qDebug() << "RouteViewModel:: downloading of the connections completed.";

    if(error != "") {
        emit netwerkError(error);
    }
    else {
        resultDataModel->clear();

        // Add them in reverse order because it's impossible to sort on an object
        for(int i=connections.length()-1; i>=0; i--) {
            resultDataModel->insert(connections.at(i));
        }

        emit searchCompleted("");
    }
}

/**
 * This method is invoked when the user clicks the search button in the
 * UI. When all the fields are in a valid state, the <em>ConnectionService</em>
 * will be asked the find all the connections between the two stations
 * provided by the user.
 * When some fields are in a non-valid state, the searchCompleted signal
 * will be emitted with as second argument an error message instead of
 * an empty string.
 */
void RouteViewModel::search() {
    if(from == "") {
        emit searchCompleted(tr("Kies uw vertrekplaats."));
        return;
    }
    else if(to == "") {
        emit searchCompleted(tr("Kies uw bestemming."));
        return;
    }
    else if(to == from) {
        emit searchCompleted(tr("Uw vertrekplaats moet verschillend zijn van uw bestemming."));
        return;
    }

    this->setFavorite(favoriteService->isFavorite(from, to));

    this->connectionService.findConnectionBy(from, to, QDateTime(this->date, this->time), this->type);
}

void RouteViewModel::favoriteMe() {
    if(this->isFavorite()) {
        this->favoriteService->remove(this->from, this->to);

        this->setFavorite(false);
    }
    else {
        this->favoriteService->add(this->from, this->to);

        this->setFavorite(true);
    }

    emit favoriteChanged(this->favorite);
}

void RouteViewModel::select(const QVariantList &index) {
    QObject* object = qvariant_cast<QObject*>(resultDataModel->data(index));

    Connection* connection = qobject_cast<Connection*>(object);

    this->setSelectedItem(connection);
}
