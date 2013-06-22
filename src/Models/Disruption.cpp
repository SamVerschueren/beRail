/*
 * Disruption.cpp
 *
 * Created on: 20-mrt.-2013
 * Author: Sam Verschueren      <sam.verschueren@gmail.com>
 */

#include "Disruption.hpp"

/**
 * Creates a new disruption with a title. This is the minimum data that we
 * want to show to the user.
 *
 * @param title The title of the disruption
 */
Disruption::Disruption(const QString &title) {
    this->setTitle(title);
}

/**
 * Returns the title.
 *
 * @return The title of the disruption
 */
QString Disruption::getTitle() const {
    return this->title;
}

/**
 * This method will set the title and notifies the observers that the
 * title has changed. He will do this, if and only if the title provided
 * is different from the model's title.
 *
 * @param title The title of the disruption
 */
void Disruption::setTitle(const QString &title) {
    if(this->title != title) {
        this->title = title;

        emit titleChanged(title);
    }
}

/**
 * Returns the description of the disruption.
 *
 * @return The description.
 */
QString Disruption::getDescription() const {
    return this->description;
}

/**
 * This method will set the description and notifies the observers that the
 * description has changed. He will do this, if and only if the description provided
 * is different from the model's description.
 *
 * @param description The description of the disruption
 */
void Disruption::setDescription(const QString &description) {
    if(this->description != description) {
        this->description = description;

        emit descriptionChanged(description);
    }
}

/**
 * Returns the publication date of the disruption. This is the date and time
 * that RailTime published the disruption on their website.
 *
 * @return The date and time that this disruption was published.
 */
QDateTime Disruption::getPublicationDate() const {
    return this->pubDate;
}

/**
 * This method will set the datetime and notifies the observers that the
 * datetime has changed. He will do this, if and only if the datetime provided
 * is different from the model's datetime.
 *
 * @param pubDate The publication date and time of the disruption
 */
void Disruption::setPublicationDate(const QDateTime &pubDate) {
    if(this->pubDate != pubDate) {
        this->pubDate = pubDate;

        emit dateChanged(pubDate);
    }
}
