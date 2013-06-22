/*
 * DisruptionsViewModel.hpp
 *
 * Created on: 21-mrt.-2013
 * Author: Sam Verschueren      <sam.verschueren@gmail.com>
 */

#ifndef DISRUPTIONSVIEWMODEL_HPP_
#define DISRUPTIONSVIEWMODEL_HPP_

#include <QObject>
#include <QVariantList>
#include <bb/cascades/GroupDataModel>
#include "DisruptionService.hpp"
#include "Disruption.hpp"
using namespace bb::cascades;

class DisruptionsViewModel : public QObject {
    Q_OBJECT

    Q_PROPERTY(GroupDataModel* dataModel READ getDataModel NOTIFY dataModelChanged)
    Q_PROPERTY(DisruptionService* service WRITE setDisruptionService)

    Q_SIGNALS:
        void dataModelChanged(GroupDataModel *dataModel);
        void completed(const QString &error);

    private:
        GroupDataModel* dataModel;
        DisruptionService* service;

    private slots:
        void downloadCompleted(const QList<Disruption*> &disruptions, const QString &error);

    public:
        DisruptionsViewModel(QObject* parent = 0) : QObject(parent) {
            dataModel = new GroupDataModel();
            dataModel->setGrouping(ItemGrouping::None);
        }
        ~DisruptionsViewModel();

        void setDisruptionService(DisruptionService* service);

        GroupDataModel* getDataModel();
};

#endif /* DISRUPTIONSVIEWMODEL_HPP_ */
