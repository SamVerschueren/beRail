/****************************************************************************
** Meta object code from reading C++ file 'Station.hpp'
**
** Created: Fri 21. Jun 20:10:09 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/Models/Station.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Station.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Station[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       5,   39, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: signature, parameters, type, tag, flags
      14,    9,    8,    8, 0x05,
      45,   35,    8,    8, 0x05,
      76,   71,    8,    8, 0x05,
     105,   99,    8,    8, 0x05,
     132,  123,    8,    8, 0x05,

 // properties: name, type, flags
       9,  153, 0x0a495103,
      35,  153, 0x0a495103,
      71,  161, 0x10495103,
      99,  171, 0x02495103,
     123,  171, 0x02495103,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,
       4,

       0        // eod
};

static const char qt_meta_stringdata_Station[] = {
    "Station\0\0name\0nameChanged(QString)\0"
    "direction\0directionChanged(QString)\0"
    "time\0timeChanged(QDateTime)\0delay\0"
    "delayChanged(int)\0platform\0"
    "platformChanged(int)\0QString\0QDateTime\0"
    "int\0"
};

void Station::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Station *_t = static_cast<Station *>(_o);
        switch (_id) {
        case 0: _t->nameChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->directionChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->timeChanged((*reinterpret_cast< const QDateTime(*)>(_a[1]))); break;
        case 3: _t->delayChanged((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 4: _t->platformChanged((*reinterpret_cast< const int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Station::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Station::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Station,
      qt_meta_data_Station, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Station::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Station::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Station::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Station))
        return static_cast<void*>(const_cast< Station*>(this));
    return QObject::qt_metacast(_clname);
}

int Station::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
        case 0: *reinterpret_cast< QString*>(_v) = getName(); break;
        case 1: *reinterpret_cast< QString*>(_v) = getDirection(); break;
        case 2: *reinterpret_cast< QDateTime*>(_v) = getTime(); break;
        case 3: *reinterpret_cast< int*>(_v) = getDelay(); break;
        case 4: *reinterpret_cast< int*>(_v) = getPlatform(); break;
        }
        _id -= 5;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setName(*reinterpret_cast< QString*>(_v)); break;
        case 1: setDirection(*reinterpret_cast< QString*>(_v)); break;
        case 2: setTime(*reinterpret_cast< QDateTime*>(_v)); break;
        case 3: setDelay(*reinterpret_cast< int*>(_v)); break;
        case 4: setPlatform(*reinterpret_cast< int*>(_v)); break;
        }
        _id -= 5;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 5;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Station::nameChanged(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Station::directionChanged(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Station::timeChanged(const QDateTime & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Station::delayChanged(const int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Station::platformChanged(const int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
