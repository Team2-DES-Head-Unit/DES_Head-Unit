/****************************************************************************
** Meta object code from reading C++ file 'BluetoothManager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../HeadUnit/BluetoothManager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'BluetoothManager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BluetoothManager_t {
    QByteArrayData data[17];
    char stringdata0[279];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BluetoothManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BluetoothManager_t qt_meta_stringdata_BluetoothManager = {
    {
QT_MOC_LITERAL(0, 0, 16), // "BluetoothManager"
QT_MOC_LITERAL(1, 17, 16), // "deviceDiscovered"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 10), // "deviceName"
QT_MOC_LITERAL(4, 46, 10), // "deviceType"
QT_MOC_LITERAL(5, 57, 17), // "discoveryFinished"
QT_MOC_LITERAL(6, 75, 17), // "connectedToDevice"
QT_MOC_LITERAL(7, 93, 22), // "disconnectedFromDevice"
QT_MOC_LITERAL(8, 116, 23), // "deviceDiscoveredHandler"
QT_MOC_LITERAL(9, 140, 20), // "QBluetoothDeviceInfo"
QT_MOC_LITERAL(10, 161, 10), // "deviceInfo"
QT_MOC_LITERAL(11, 172, 24), // "discoveryFinishedHandler"
QT_MOC_LITERAL(12, 197, 16), // "connectedHandler"
QT_MOC_LITERAL(13, 214, 19), // "disconnectedHandler"
QT_MOC_LITERAL(14, 234, 14), // "startDiscovery"
QT_MOC_LITERAL(15, 249, 13), // "stopDiscovery"
QT_MOC_LITERAL(16, 263, 15) // "connectToDevice"

    },
    "BluetoothManager\0deviceDiscovered\0\0"
    "deviceName\0deviceType\0discoveryFinished\0"
    "connectedToDevice\0disconnectedFromDevice\0"
    "deviceDiscoveredHandler\0QBluetoothDeviceInfo\0"
    "deviceInfo\0discoveryFinishedHandler\0"
    "connectedHandler\0disconnectedHandler\0"
    "startDiscovery\0stopDiscovery\0"
    "connectToDevice"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BluetoothManager[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   69,    2, 0x06 /* Public */,
       5,    0,   74,    2, 0x06 /* Public */,
       6,    0,   75,    2, 0x06 /* Public */,
       7,    0,   76,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   77,    2, 0x08 /* Private */,
      11,    0,   80,    2, 0x08 /* Private */,
      12,    0,   81,    2, 0x08 /* Private */,
      13,    0,   82,    2, 0x08 /* Private */,

 // methods: name, argc, parameters, tag, flags
      14,    0,   83,    2, 0x02 /* Public */,
      15,    0,   84,    2, 0x02 /* Public */,
      16,    1,   85,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    3,

       0        // eod
};

void BluetoothManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<BluetoothManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->deviceDiscovered((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 1: _t->discoveryFinished(); break;
        case 2: _t->connectedToDevice(); break;
        case 3: _t->disconnectedFromDevice(); break;
        case 4: _t->deviceDiscoveredHandler((*reinterpret_cast< const QBluetoothDeviceInfo(*)>(_a[1]))); break;
        case 5: _t->discoveryFinishedHandler(); break;
        case 6: _t->connectedHandler(); break;
        case 7: _t->disconnectedHandler(); break;
        case 8: _t->startDiscovery(); break;
        case 9: _t->stopDiscovery(); break;
        case 10: _t->connectToDevice((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QBluetoothDeviceInfo >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (BluetoothManager::*)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BluetoothManager::deviceDiscovered)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (BluetoothManager::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BluetoothManager::discoveryFinished)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (BluetoothManager::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BluetoothManager::connectedToDevice)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (BluetoothManager::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BluetoothManager::disconnectedFromDevice)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject BluetoothManager::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_BluetoothManager.data,
    qt_meta_data_BluetoothManager,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *BluetoothManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BluetoothManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BluetoothManager.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int BluetoothManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void BluetoothManager::deviceDiscovered(const QString & _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void BluetoothManager::discoveryFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void BluetoothManager::connectedToDevice()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void BluetoothManager::disconnectedFromDevice()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
