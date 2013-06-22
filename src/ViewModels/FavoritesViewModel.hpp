/*
 * FavoritesViewModel.hpp
 *
 * This ViewModel is used to show the data that the user marked
 * as favorites in a nice listview. When the user selects an item,
 * the system will look up the correct station and shows that data to
 * the user.
 *
 * Created on: 9-mrt.-2013
 * Author: Sam Verschueren      <sam.verschueren@gmail.com>
 */

#ifndef FAVORITESVIEWMODEL_HPP_
#define FAVORITESVIEWMODEL_HPP_

#include "FavoriteService.hpp"

#include <QObject>
#include <QVariantList>
#include <bb/cascades/GroupDataModel>
using namespace bb::cascades;

class FavoritesViewModel : public QObject {
    Q_OBJECT

    Q_PROPERTY(GroupDataModel* dataModel READ getDataModel NOTIFY dataModelChanged)
    Q_PROPERTY(FavoriteService* service WRITE setFavoriteService)

    Q_SIGNALS:
        void dataModelChanged(GroupDataModel *model);
        void selectedFromChanged(QString selectedFrom);
        void selectedToChanged(QString selectedTo);

    private:
        FavoriteService *favoriteService;
        GroupDataModel *dataModel;

    private slots:
        void favoritesDataChanged(const QVariantList &favorites);

    public:
        FavoritesViewModel(QObject *parent=0) : QObject(parent) {
            dataModel = new GroupDataModel();
            dataModel->setGrouping(ItemGrouping::None);
        }
        ~FavoritesViewModel();

        void setFavoriteService(FavoriteService *service);

        GroupDataModel* getDataModel();

        Q_INVOKABLE void remove(QVariantList indexPath);
};

#endif /* FAVORITESVIEWMODEL_HPP_ */
