/****************************************************************************
** Meta object code from reading C++ file 'Gauge.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Gauge.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Gauge.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_gauge_t {
    QByteArrayData data[24];
    char stringdata0[336];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_gauge_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_gauge_t qt_meta_stringdata_gauge = {
    {
QT_MOC_LITERAL(0, 0, 5), // "gauge"
QT_MOC_LITERAL(1, 6, 22), // "speedometerSizeChanged"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 17), // "startAngleChanged"
QT_MOC_LITERAL(4, 48, 17), // "alignAngleChanged"
QT_MOC_LITERAL(5, 66, 18), // "lowestRangeChanged"
QT_MOC_LITERAL(6, 85, 19), // "highestRangeChanged"
QT_MOC_LITERAL(7, 105, 12), // "ValueChanged"
QT_MOC_LITERAL(8, 118, 15), // "arcWidthChanged"
QT_MOC_LITERAL(9, 134, 17), // "outerColorChanged"
QT_MOC_LITERAL(10, 152, 17), // "innerColorChanged"
QT_MOC_LITERAL(11, 170, 16), // "textColorChanged"
QT_MOC_LITERAL(12, 187, 22), // "backgroundColorChanged"
QT_MOC_LITERAL(13, 210, 15), // "speedometerSize"
QT_MOC_LITERAL(14, 226, 10), // "startAngle"
QT_MOC_LITERAL(15, 237, 10), // "alignAngle"
QT_MOC_LITERAL(16, 248, 11), // "lowestRange"
QT_MOC_LITERAL(17, 260, 12), // "highestRange"
QT_MOC_LITERAL(18, 273, 5), // "Value"
QT_MOC_LITERAL(19, 279, 8), // "arcWidth"
QT_MOC_LITERAL(20, 288, 10), // "outerColor"
QT_MOC_LITERAL(21, 299, 10), // "innerColor"
QT_MOC_LITERAL(22, 310, 9), // "textColor"
QT_MOC_LITERAL(23, 320, 15) // "backgroundColor"

    },
    "gauge\0speedometerSizeChanged\0\0"
    "startAngleChanged\0alignAngleChanged\0"
    "lowestRangeChanged\0highestRangeChanged\0"
    "ValueChanged\0arcWidthChanged\0"
    "outerColorChanged\0innerColorChanged\0"
    "textColorChanged\0backgroundColorChanged\0"
    "speedometerSize\0startAngle\0alignAngle\0"
    "lowestRange\0highestRange\0Value\0arcWidth\0"
    "outerColor\0innerColor\0textColor\0"
    "backgroundColor"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_gauge[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
      11,   80, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      11,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x06 /* Public */,
       3,    0,   70,    2, 0x06 /* Public */,
       4,    0,   71,    2, 0x06 /* Public */,
       5,    0,   72,    2, 0x06 /* Public */,
       6,    0,   73,    2, 0x06 /* Public */,
       7,    0,   74,    2, 0x06 /* Public */,
       8,    0,   75,    2, 0x06 /* Public */,
       9,    0,   76,    2, 0x06 /* Public */,
      10,    0,   77,    2, 0x06 /* Public */,
      11,    0,   78,    2, 0x06 /* Public */,
      12,    0,   79,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
      13, QMetaType::QReal, 0x00495103,
      14, QMetaType::QReal, 0x00495103,
      15, QMetaType::QReal, 0x00495103,
      16, QMetaType::QReal, 0x00495103,
      17, QMetaType::QReal, 0x00495103,
      18, QMetaType::QReal, 0x00495103,
      19, QMetaType::Int, 0x00495103,
      20, QMetaType::QColor, 0x00495103,
      21, QMetaType::QColor, 0x00495103,
      22, QMetaType::QColor, 0x00495103,
      23, QMetaType::QColor, 0x00495103,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,
       4,
       5,
       6,
       7,
       8,
       9,
      10,

       0        // eod
};

void gauge::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<gauge *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->speedometerSizeChanged(); break;
        case 1: _t->startAngleChanged(); break;
        case 2: _t->alignAngleChanged(); break;
        case 3: _t->lowestRangeChanged(); break;
        case 4: _t->highestRangeChanged(); break;
        case 5: _t->ValueChanged(); break;
        case 6: _t->arcWidthChanged(); break;
        case 7: _t->outerColorChanged(); break;
        case 8: _t->innerColorChanged(); break;
        case 9: _t->textColorChanged(); break;
        case 10: _t->backgroundColorChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (gauge::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&gauge::speedometerSizeChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (gauge::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&gauge::startAngleChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (gauge::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&gauge::alignAngleChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (gauge::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&gauge::lowestRangeChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (gauge::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&gauge::highestRangeChanged)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (gauge::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&gauge::ValueChanged)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (gauge::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&gauge::arcWidthChanged)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (gauge::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&gauge::outerColorChanged)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (gauge::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&gauge::innerColorChanged)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (gauge::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&gauge::textColorChanged)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (gauge::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&gauge::backgroundColorChanged)) {
                *result = 10;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<gauge *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< qreal*>(_v) = _t->getspeedometerSize(); break;
        case 1: *reinterpret_cast< qreal*>(_v) = _t->getStartAngle(); break;
        case 2: *reinterpret_cast< qreal*>(_v) = _t->getAlignAngle(); break;
        case 3: *reinterpret_cast< qreal*>(_v) = _t->getLowestRange(); break;
        case 4: *reinterpret_cast< qreal*>(_v) = _t->getHighestRange(); break;
        case 5: *reinterpret_cast< qreal*>(_v) = _t->getValue(); break;
        case 6: *reinterpret_cast< int*>(_v) = _t->getArcWidth(); break;
        case 7: *reinterpret_cast< QColor*>(_v) = _t->getOuterColor(); break;
        case 8: *reinterpret_cast< QColor*>(_v) = _t->getInnerColor(); break;
        case 9: *reinterpret_cast< QColor*>(_v) = _t->getTextColor(); break;
        case 10: *reinterpret_cast< QColor*>(_v) = _t->getBackgroundColor(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<gauge *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setSpeedometerSize(*reinterpret_cast< qreal*>(_v)); break;
        case 1: _t->setStartAngle(*reinterpret_cast< qreal*>(_v)); break;
        case 2: _t->setAlignAngle(*reinterpret_cast< qreal*>(_v)); break;
        case 3: _t->setLowestRange(*reinterpret_cast< qreal*>(_v)); break;
        case 4: _t->setHighestRange(*reinterpret_cast< qreal*>(_v)); break;
        case 5: _t->setValue(*reinterpret_cast< qreal*>(_v)); break;
        case 6: _t->setArcWidth(*reinterpret_cast< int*>(_v)); break;
        case 7: _t->setOuterColor(*reinterpret_cast< QColor*>(_v)); break;
        case 8: _t->setInnerColor(*reinterpret_cast< QColor*>(_v)); break;
        case 9: _t->setTextColor(*reinterpret_cast< QColor*>(_v)); break;
        case 10: _t->setBackgroundColor(*reinterpret_cast< QColor*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject gauge::staticMetaObject = { {
    &QQuickPaintedItem::staticMetaObject,
    qt_meta_stringdata_gauge.data,
    qt_meta_data_gauge,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *gauge::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *gauge::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_gauge.stringdata0))
        return static_cast<void*>(this);
    return QQuickPaintedItem::qt_metacast(_clname);
}

int gauge::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QQuickPaintedItem::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 11;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 11;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 11;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 11;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 11;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void gauge::speedometerSizeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void gauge::startAngleChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void gauge::alignAngleChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void gauge::lowestRangeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void gauge::highestRangeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void gauge::ValueChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void gauge::arcWidthChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void gauge::outerColorChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void gauge::innerColorChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void gauge::textColorChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void gauge::backgroundColorChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
