/*
 * DisruptionService.cpp
 *
 * Created on: 20-mrt.-2013
 * Author: Sam Verschueren      <sam.verschueren@gmail.com>
 */

#include <QNetworkRequest>
#include <QDebug>
#include <bb/cascades/QmlDocument>
#include <QtXml>
#include "DisruptionService.hpp"
using namespace bb::cascades;

/**
 * Release the dynamically allocated memory.
 */
DisruptionService::~DisruptionService() {
    delete networkAccessManager;
}

/**
 * This method is called from outside and will create a new network
 * request in order to download the rss feed. When the request is finished,
 * the requestFinished method is invoked.
 */
void DisruptionService::findAll() {
    // TODO This method is invoked twice, have a look if this is really invoked twice...

    // Create a new network request and set the url.
    QNetworkRequest request;
    request.setUrl(QUrl("http://www.railtime.be/website/RSS/RssInfoBar_" + tr("nl") + ".xml"));

    // Execute the request by using the network access manager.
    this->networkAccessManager->get(request);
}

/**
 * This method is invoked when the request of the networkAccessManager is finished.
 * When this method is finished parsing, it will emit the signal downloadCompleted. Other
 * classes can connect with the downloadCompleted signal and they will be notified
 * when this request is finished.
 *
 * @param reply The network reply of the request.
 */
void DisruptionService::requestFinished(QNetworkReply *reply) {
    QList<Disruption*> disruptionsList;

    if(reply->error() == QNetworkReply::NoError) {
        QByteArray data = reply->readAll();

        QString xml = QString::fromUtf8(data.data(), data.size());

        QDomDocument doc;
        doc.setContent(xml);

        QDomNodeList items = doc.elementsByTagName("item");

        for(int i=0; i<items.count(); i++) {
            QDomElement element = items.at(i).toElement();

            QString title = element.elementsByTagName("title").at(0).toElement().text();
            QString description = element.elementsByTagName("description").at(0).toElement().text();
            QString pubDate = element.elementsByTagName("pubDate").at(0).toElement().text();
            pubDate = pubDate.remove(" GMT", Qt::CaseInsensitive).trimmed();

            QLocale loc(QLocale::English);

            QDateTime pub = loc.toDateTime(pubDate, "ddd, dd MMM yyyy hh:mm:ss");

            Disruption* disruption = new Disruption(title);
            disruption->setDescription(description);
            disruption->setPublicationDate(pub);

            disruptionsList.append(disruption);
        }

        emit downloadCompleted(disruptionsList, "");
    }
    else {
        emit downloadCompleted(disruptionsList, "Network is not available");
    }
}

