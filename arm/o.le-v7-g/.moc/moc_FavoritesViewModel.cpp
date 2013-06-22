/****************************************************************************
** Meta object code from reading C++ file 'FavoritesViewModel.hpp'
**
** Created: Fri 21. Jun 20:10:26 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/ViewModels/FavoritesViewModel.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FavoritesViewModel.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_FavoritesViewModel[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       2,   39, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      26,   20,   19,   19, 0x05,
      73,   60,   19,   19, 0x05,
     113,  102,   19,   19, 0x05,

 // slots: signature, parameters, type, tag, flags
     150,  140,   19,   19, 0x08,

 // methods: signature, parameters, type, tag, flags
     195,  185,   19,   19, 0x02,

 // properties: name, type, flags
     232,  216, 0x00495009,
     259,  242, 0x0009500a,

 // properties: notify_signal_id
       0,
       0,

       0        // eod
};

static const char qt_meta_stringdata_FavoritesViewModel[] = {
    "FavoritesViewModel\0\0model\0"
    "dataModelChanged(GroupDataModel*)\0"
    "selectedFrom\0selectedFromChanged(QString)\0"
    "selectedTo\0selectedToChanged(QString)\0"
    "favorites\0favoritesDataChanged(QVariantList)\0"
    "indexPath\0remove(QVariantList)\0"
    "GroupDataModel*\0dataModel\0FavoriteService*\0"
    "service\0"
};

void FavoritesViewModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        FavoritesViewModel *_t = static_cast<FavoritesViewModel *>(_o);
        switch (_id) {
        case 0: _t->dataModelChanged((*reinterpret_cast< GroupDataModel*(*)>(_a[1]))); break;
        case 1: _t->selectedFromChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->selectedToChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->favoritesDataChanged((*reinterpret_cast< const QVariantList(*)>(_a[1]))); break;
        case 4: _t->remove((*reinterpret_cast< QVariantList(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData FavoritesViewModel::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject FavoritesViewModel::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_FavoritesViewModel,
      qt_meta_data_FavoritesViewModel, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FavoritesViewModel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FavoritesViewModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FavoritesViewModel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FavoritesViewModel))
        return static_cast<void*>(const_cast< FavoritesViewModel*>(this));
    return QObject::qt_metacast(_clname);
}

int FavoritesViewModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< GroupDataModel**>(_v) = getDataModel(); break;
        }
        _id -= 2;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 1: setFavoriteService(*reinterpret_cast< FavoriteService**>(_v)); break;
        }
        _id -= 2;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void FavoritesViewModel::dataModelChanged(GroupDataModel * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FavoritesViewModel::selectedFromChanged(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void FavoritesViewModel::selectedToChanged(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
