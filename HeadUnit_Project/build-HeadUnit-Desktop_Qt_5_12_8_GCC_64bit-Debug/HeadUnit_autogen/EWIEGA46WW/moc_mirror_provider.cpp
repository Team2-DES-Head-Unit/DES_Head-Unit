/****************************************************************************
** Meta object code from reading C++ file 'mirror_provider.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../HeadUnit/mirror_provider.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mirror_provider.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MirrorProvider_t {
    QByteArrayData data[12];
    char stringdata0[124];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MirrorProvider_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MirrorProvider_t qt_meta_stringdata_MirrorProvider = {
    {
QT_MOC_LITERAL(0, 0, 14), // "MirrorProvider"
QT_MOC_LITERAL(1, 15, 12), // "stateChanged"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 11), // "getisLoaded"
QT_MOC_LITERAL(4, 41, 11), // "changeState"
QT_MOC_LITERAL(5, 53, 22), // "QProcess::ProcessState"
QT_MOC_LITERAL(6, 76, 8), // "newState"
QT_MOC_LITERAL(7, 85, 4), // "init"
QT_MOC_LITERAL(8, 90, 13), // "QQuickWindow*"
QT_MOC_LITERAL(9, 104, 6), // "parent"
QT_MOC_LITERAL(10, 111, 3), // "end"
QT_MOC_LITERAL(11, 115, 8) // "isLoaded"

    },
    "MirrorProvider\0stateChanged\0\0getisLoaded\0"
    "changeState\0QProcess::ProcessState\0"
    "newState\0init\0QQuickWindow*\0parent\0"
    "end\0isLoaded"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MirrorProvider[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       1,   48, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   40,    2, 0x0a /* Public */,
       4,    1,   41,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
       7,    1,   44,    2, 0x02 /* Public */,
      10,    0,   47,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Bool,
    QMetaType::Void, 0x80000000 | 5,    6,

 // methods: parameters
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,

 // properties: name, type, flags
      11, QMetaType::Bool, 0x00495001,

 // properties: notify_signal_id
       0,

       0        // eod
};

void MirrorProvider::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MirrorProvider *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->stateChanged(); break;
        case 1: { bool _r = _t->getisLoaded();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 2: _t->changeState((*reinterpret_cast< QProcess::ProcessState(*)>(_a[1]))); break;
        case 3: _t->init((*reinterpret_cast< QQuickWindow*(*)>(_a[1]))); break;
        case 4: _t->end(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QQuickWindow* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MirrorProvider::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MirrorProvider::stateChanged)) {
                *result = 0;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<MirrorProvider *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->getisLoaded(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject MirrorProvider::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_MirrorProvider.data,
    qt_meta_data_MirrorProvider,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MirrorProvider::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MirrorProvider::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MirrorProvider.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int MirrorProvider::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void MirrorProvider::stateChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE