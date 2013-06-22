/*
 * Disruption.hpp
 *
 * Created on: 20-mrt.-2013
 * Author: Sam Verschueren
 */

#ifndef DISRUPTION_HPP_
#define DISRUPTION_HPP_

#include <QObject>
#include <QDateTime>

class Disruption : public QObject {
    Q_OBJECT

    Q_PROPERTY(QString title READ getTitle WRITE setTitle NOTIFY titleChanged)
    Q_PROPERTY(QString description READ getDescription WRITE setDescription NOTIFY descriptionChanged)
    Q_PROPERTY(QDateTime date READ getPublicationDate WRITE setPublicationDate NOTIFY dateChanged)

    Q_SIGNALS:
        void titleChanged(const QString &title);
        void descriptionChanged(const QString &description);
        void dateChanged(const QDateTime &date);

    private:
        QString title;
        QString description;
        QDateTime pubDate;

    public:
        Disruption(const QString &title);

        QString getTitle() const;
        void setTitle(const QString &title);

        QString getDescription() const;
        void setDescription(const QString &description);

        QDateTime getPublicationDate() const;
        void setPublicationDate(const QDateTime &pubDate);
};

#endif /* DISRUPTION_HPP_ */
