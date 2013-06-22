/*
 * DisruptionService.hpp
 *
 * This service loads all the official railtime disruptions in our
 * applications. The disruptions can be found at the railtime.be website
 * and is a simple RSS feed that we parse here.
 *
 * Created on: 20-mrt.-2013
 * Author: Sam Verschueren      <sam.verschueren@gmail.com>
 */

#ifndef DISRUPTIONSERVICE_HPP_
#define DISRUPTIONSERVICE_HPP_

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QList>
#include "Disruption.hpp"

class DisruptionService : public QObject {
    Q_OBJECT;

    Q_SIGNALS:
        void downloadCompleted(const QList<Disruption*> &disruptions, const QString &error);

    private:
        QNetworkAccessManager *networkAccessManager;

    public:
        DisruptionService(QObject *parent = 0) : QObject(parent) {
            this->networkAccessManager = new QNetworkAccessManager(this);

            // Connect with the finished signal of the networkAccessManager
            connect(this->networkAccessManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(requestFinished(QNetworkReply*)));
        }
        ~DisruptionService();

        void findAll();

    private slots:
        void requestFinished(QNetworkReply *reply);
};

#endif /* DISRUPTIONSERVICE_HPP_ */
