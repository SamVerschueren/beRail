/****************************************************************************
** Meta object code from reading C++ file 'StationViewModel.hpp'
**
** Created: Fri 21. Jun 20:42:51 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/ViewModels/StationViewModel.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'StationViewModel.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_StationViewModel[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       2,   24, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      25,   18,   17,   17, 0x05,

 // slots: signature, parameters, type, tag, flags
      57,   48,   17,   17, 0x08,

 // properties: name, type, flags
      18,   98, 0x0a495903,
     122,  106, 0x00095009,

 // properties: notify_signal_id
       0,
       0,

       0        // eod
};

static const char qt_meta_stringdata_StationViewModel[] = {
    "StationViewModel\0\0filter\0"
    "filterChanged(QString)\0stations\0"
    "findAllStationsCompleted(QList<QString>)\0"
    "QString\0GroupDataModel*\0dataModel\0"
};

void StationViewModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        StationViewModel *_t = static_cast<StationViewModel *>(_o);
        switch (_id) {
        case 0: _t->filterChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->findAllStationsCompleted((*reinterpret_cast< const QList<QString>(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData StationViewModel::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject StationViewModel::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_StationViewModel,
      qt_meta_data_StationViewModel, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &StationViewModel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *StationViewModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *StationViewModel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_StationViewModel))
        return static_cast<void*>(const_cast< StationViewModel*>(this));
    return QObject::qt_metacast(_clname);
}

int StationViewModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = getFilter(); break;
        case 1: *reinterpret_cast< GroupDataModel**>(_v) = getDataModel(); break;
        }
        _id -= 2;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setFilter(*reinterpret_cast< QString*>(_v)); break;
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
void StationViewModel::filterChanged(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
