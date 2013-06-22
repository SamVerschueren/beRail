/****************************************************************************
** Meta object code from reading C++ file 'RouteViewModel.hpp'
**
** Created: Fri 21. Jun 20:10:31 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/ViewModels/RouteViewModel.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'RouteViewModel.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_RouteViewModel[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       9,   84, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: signature, parameters, type, tag, flags
      21,   16,   15,   15, 0x05,
      45,   42,   15,   15, 0x05,
      69,   64,   15,   15, 0x05,
      93,   88,   15,   15, 0x05,
     117,  112,   15,   15, 0x05,
     143,  134,   15,   15, 0x05,
     175,  165,   15,   15, 0x05,
     220,  209,   15,   15, 0x05,
     256,  250,   15,   15, 0x05,
     281,  250,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
     321,  303,   15,   15, 0x08,

 // methods: signature, parameters, type, tag, flags
     367,   15,   15,   15, 0x02,
     376,   15,   15,   15, 0x02,
     395,  389,   15,   15, 0x02,

 // properties: name, type, flags
      16,  416, 0x0a495903,
      42,  416, 0x0a495903,
      64,  424, 0x0e495903,
      88,  430, 0x0f495903,
     112,  436, 0x02495903,
     134,  440, 0x01495903,
     461,  445, 0x00495009,
     489,  477, 0x00495009,
     519,  502, 0x0009500a,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,
       4,
       5,
       6,
       7,
       0,

       0        // eod
};

static const char qt_meta_stringdata_RouteViewModel[] = {
    "RouteViewModel\0\0from\0fromChanged(QString)\0"
    "to\0toChanged(QString)\0date\0"
    "dateChanged(QDate)\0time\0timeChanged(QTime)\0"
    "type\0typeChanged(int)\0favorite\0"
    "favoriteChanged(bool)\0dataModel\0"
    "dataModelChanged(GroupDataModel*)\0"
    "connection\0selectionChanged(Connection*)\0"
    "error\0searchCompleted(QString)\0"
    "netwerkError(QString)\0connections,error\0"
    "downloadCompleted(QList<Connection*>,QString)\0"
    "search()\0favoriteMe()\0index\0"
    "select(QVariantList)\0QString\0QDate\0"
    "QTime\0int\0bool\0GroupDataModel*\0"
    "resultDataModel\0Connection*\0selectedItem\0"
    "FavoriteService*\0service\0"
};

void RouteViewModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        RouteViewModel *_t = static_cast<RouteViewModel *>(_o);
        switch (_id) {
        case 0: _t->fromChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->toChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->dateChanged((*reinterpret_cast< const QDate(*)>(_a[1]))); break;
        case 3: _t->timeChanged((*reinterpret_cast< const QTime(*)>(_a[1]))); break;
        case 4: _t->typeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->favoriteChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->dataModelChanged((*reinterpret_cast< GroupDataModel*(*)>(_a[1]))); break;
        case 7: _t->selectionChanged((*reinterpret_cast< Connection*(*)>(_a[1]))); break;
        case 8: _t->searchCompleted((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->netwerkError((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->downloadCompleted((*reinterpret_cast< const QList<Connection*>(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 11: _t->search(); break;
        case 12: _t->favoriteMe(); break;
        case 13: _t->select((*reinterpret_cast< const QVariantList(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData RouteViewModel::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject RouteViewModel::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_RouteViewModel,
      qt_meta_data_RouteViewModel, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &RouteViewModel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *RouteViewModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *RouteViewModel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RouteViewModel))
        return static_cast<void*>(const_cast< RouteViewModel*>(this));
    return QObject::qt_metacast(_clname);
}

int RouteViewModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = getFrom(); break;
        case 1: *reinterpret_cast< QString*>(_v) = getTo(); break;
        case 2: *reinterpret_cast< QDate*>(_v) = getDate(); break;
        case 3: *reinterpret_cast< QTime*>(_v) = getTime(); break;
        case 4: *reinterpret_cast< int*>(_v) = getType(); break;
        case 5: *reinterpret_cast< bool*>(_v) = isFavorite(); break;
        case 6: *reinterpret_cast< GroupDataModel**>(_v) = getResultDataModel(); break;
        case 7: *reinterpret_cast< Connection**>(_v) = getSelectedItem(); break;
        }
        _id -= 9;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setFrom(*reinterpret_cast< QString*>(_v)); break;
        case 1: setTo(*reinterpret_cast< QString*>(_v)); break;
        case 2: setDate(*reinterpret_cast< QDate*>(_v)); break;
        case 3: setTime(*reinterpret_cast< QTime*>(_v)); break;
        case 4: setType(*reinterpret_cast< int*>(_v)); break;
        case 5: setFavorite(*reinterpret_cast< bool*>(_v)); break;
        case 8: setFavoriteService(*reinterpret_cast< FavoriteService**>(_v)); break;
        }
        _id -= 9;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 9;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void RouteViewModel::fromChanged(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void RouteViewModel::toChanged(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void RouteViewModel::dateChanged(const QDate & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void RouteViewModel::timeChanged(const QTime & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void RouteViewModel::typeChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void RouteViewModel::favoriteChanged(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void RouteViewModel::dataModelChanged(GroupDataModel * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void RouteViewModel::selectionChanged(Connection * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void RouteViewModel::searchCompleted(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void RouteViewModel::netwerkError(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}
QT_END_MOC_NAMESPACE
