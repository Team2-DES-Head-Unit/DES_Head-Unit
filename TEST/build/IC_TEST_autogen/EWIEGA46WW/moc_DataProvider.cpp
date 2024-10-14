/****************************************************************************
** Meta object code from reading C++ file 'DataProvider.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "DataProvider.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DataProvider.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DataProvider_t {
    QByteArrayData data[12];
    char stringdata0[144];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DataProvider_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DataProvider_t qt_meta_stringdata_DataProvider = {
    {
QT_MOC_LITERAL(0, 0, 12), // "DataProvider"
QT_MOC_LITERAL(1, 13, 12), // "speedChanged"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 15), // "minSpeedChanged"
QT_MOC_LITERAL(4, 43, 15), // "maxSpeedChanged"
QT_MOC_LITERAL(5, 59, 10), // "rpmChanged"
QT_MOC_LITERAL(6, 70, 13), // "minRPMChanged"
QT_MOC_LITERAL(7, 84, 13), // "maxRPMChanged"
QT_MOC_LITERAL(8, 98, 13), // "generateSpeed"
QT_MOC_LITERAL(9, 112, 11), // "generateRPM"
QT_MOC_LITERAL(10, 124, 10), // "speedValue"
QT_MOC_LITERAL(11, 135, 8) // "rpmValue"

    },
    "DataProvider\0speedChanged\0\0minSpeedChanged\0"
    "maxSpeedChanged\0rpmChanged\0minRPMChanged\0"
    "maxRPMChanged\0generateSpeed\0generateRPM\0"
    "speedValue\0rpmValue"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DataProvider[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       2,   62, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    0,   55,    2, 0x06 /* Public */,
       4,    0,   56,    2, 0x06 /* Public */,
       5,    0,   57,    2, 0x06 /* Public */,
       6,    0,   58,    2, 0x06 /* Public */,
       7,    0,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   60,    2, 0x08 /* Private */,
       9,    0,   61,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
      10, QMetaType::Int, 0x00495001,
      11, QMetaType::Int, 0x00495001,

 // properties: notify_signal_id
       0,
       3,

       0        // eod
};

void DataProvider::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DataProvider *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->speedChanged(); break;
        case 1: _t->minSpeedChanged(); break;
        case 2: _t->maxSpeedChanged(); break;
        case 3: _t->rpmChanged(); break;
        case 4: _t->minRPMChanged(); break;
        case 5: _t->maxRPMChanged(); break;
        case 6: _t->generateSpeed(); break;
        case 7: _t->generateRPM(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DataProvider::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataProvider::speedChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DataProvider::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataProvider::minSpeedChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (DataProvider::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataProvider::maxSpeedChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (DataProvider::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataProvider::rpmChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (DataProvider::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataProvider::minRPMChanged)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (DataProvider::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataProvider::maxRPMChanged)) {
                *result = 5;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<DataProvider *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->speedValue(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->rpmValue(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject DataProvider::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_DataProvider.data,
    qt_meta_data_DataProvider,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DataProvider::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DataProvider::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DataProvider.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int DataProvider::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
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
void DataProvider::speedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void DataProvider::minSpeedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void DataProvider::maxSpeedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void DataProvider::rpmChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void DataProvider::minRPMChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void DataProvider::maxRPMChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
