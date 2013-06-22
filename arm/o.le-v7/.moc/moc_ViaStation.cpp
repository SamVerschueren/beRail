/****************************************************************************
** Meta object code from reading C++ file 'ViaStation.hpp'
**
** Created: Fri 21. Jun 20:42:28 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/Models/ViaStation.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ViaStation.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ViaStation[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   12,   11,   11, 0x05,
      48,   38,   11,   11, 0x05,
      86,   74,   11,   11, 0x05,
     125,  116,   11,   11, 0x05,
     167,  153,   11,   11, 0x05,
     199,  116,   11,   11, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_ViaStation[] = {
    "ViaStation\0\0name\0nameChanged(QString)\0"
    "direction\0directionChanged(QString)\0"
    "arrivalTime\0arrivalTimeChanged(QDateTime)\0"
    "platform\0arrivalPlatformChanged(int)\0"
    "departureTime\0departureTimeChanged(QDateTime)\0"
    "departurePlatformChanged(int)\0"
};

void ViaStation::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ViaStation *_t = static_cast<ViaStation *>(_o);
        switch (_id) {
        case 0: _t->nameChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->directionChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->arrivalTimeChanged((*reinterpret_cast< const QDateTime(*)>(_a[1]))); break;
        case 3: _t->arrivalPlatformChanged((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 4: _t->departureTimeChanged((*reinterpret_cast< const QDateTime(*)>(_a[1]))); break;
        case 5: _t->departurePlatformChanged((*reinterpret_cast< const int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ViaStation::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ViaStation::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ViaStation,
      qt_meta_data_ViaStation, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ViaStation::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ViaStation::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ViaStation::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ViaStation))
        return static_cast<void*>(const_cast< ViaStation*>(this));
    return QObject::qt_metacast(_clname);
}

int ViaStation::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void ViaStation::nameChanged(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ViaStation::directionChanged(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ViaStation::arrivalTimeChanged(const QDateTime & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ViaStation::arrivalPlatformChanged(const int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void ViaStation::departureTimeChanged(const QDateTime & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void ViaStation::departurePlatformChanged(const int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_END_MOC_NAMESPACE
