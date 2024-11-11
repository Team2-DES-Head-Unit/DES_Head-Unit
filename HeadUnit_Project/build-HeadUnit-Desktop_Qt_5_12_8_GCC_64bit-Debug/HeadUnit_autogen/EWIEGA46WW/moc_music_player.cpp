/****************************************************************************
** Meta object code from reading C++ file 'music_player.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../HeadUnit/music_player.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'music_player.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MusicPlayer_t {
    QByteArrayData data[27];
    char stringdata0[332];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MusicPlayer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MusicPlayer_t qt_meta_stringdata_MusicPlayer = {
    {
QT_MOC_LITERAL(0, 0, 11), // "MusicPlayer"
QT_MOC_LITERAL(1, 12, 20), // "musicProgressChanged"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 18), // "currentSongChanged"
QT_MOC_LITERAL(4, 53, 9), // "songTitle"
QT_MOC_LITERAL(5, 63, 12), // "nextSongInfo"
QT_MOC_LITERAL(6, 76, 5), // "title"
QT_MOC_LITERAL(7, 82, 6), // "artist"
QT_MOC_LITERAL(8, 89, 9), // "coverPath"
QT_MOC_LITERAL(9, 99, 14), // "updateProgress"
QT_MOC_LITERAL(10, 114, 9), // "getMusics"
QT_MOC_LITERAL(11, 124, 15), // "getCoverForSong"
QT_MOC_LITERAL(12, 140, 16), // "getArtistForSong"
QT_MOC_LITERAL(13, 157, 15), // "getTitleForSong"
QT_MOC_LITERAL(14, 173, 14), // "getPathForSong"
QT_MOC_LITERAL(15, 188, 18), // "getCurrentPlayList"
QT_MOC_LITERAL(16, 207, 8), // "setMusic"
QT_MOC_LITERAL(17, 216, 8), // "filePath"
QT_MOC_LITERAL(18, 225, 9), // "playMusic"
QT_MOC_LITERAL(19, 235, 10), // "pauseMusic"
QT_MOC_LITERAL(20, 246, 9), // "stopMusic"
QT_MOC_LITERAL(21, 256, 9), // "playState"
QT_MOC_LITERAL(22, 266, 14), // "music_duration"
QT_MOC_LITERAL(23, 281, 14), // "music_position"
QT_MOC_LITERAL(24, 296, 8), // "skipNext"
QT_MOC_LITERAL(25, 305, 12), // "skipPrevious"
QT_MOC_LITERAL(26, 318, 13) // "musicProgress"

    },
    "MusicPlayer\0musicProgressChanged\0\0"
    "currentSongChanged\0songTitle\0nextSongInfo\0"
    "title\0artist\0coverPath\0updateProgress\0"
    "getMusics\0getCoverForSong\0getArtistForSong\0"
    "getTitleForSong\0getPathForSong\0"
    "getCurrentPlayList\0setMusic\0filePath\0"
    "playMusic\0pauseMusic\0stopMusic\0playState\0"
    "music_duration\0music_position\0skipNext\0"
    "skipPrevious\0musicProgress"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MusicPlayer[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       1,  150, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  109,    2, 0x06 /* Public */,
       3,    1,  110,    2, 0x06 /* Public */,
       5,    3,  113,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,  120,    2, 0x08 /* Private */,

 // methods: name, argc, parameters, tag, flags
      10,    0,  121,    2, 0x02 /* Public */,
      11,    1,  122,    2, 0x02 /* Public */,
      12,    1,  125,    2, 0x02 /* Public */,
      13,    1,  128,    2, 0x02 /* Public */,
      14,    1,  131,    2, 0x02 /* Public */,
      15,    1,  134,    2, 0x02 /* Public */,
      16,    1,  137,    2, 0x02 /* Public */,
      18,    1,  140,    2, 0x02 /* Public */,
      19,    0,  143,    2, 0x02 /* Public */,
      20,    0,  144,    2, 0x02 /* Public */,
      21,    0,  145,    2, 0x02 /* Public */,
      22,    0,  146,    2, 0x02 /* Public */,
      23,    0,  147,    2, 0x02 /* Public */,
      24,    0,  148,    2, 0x02 /* Public */,
      25,    0,  149,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    6,    7,    8,

 // slots: parameters
    QMetaType::Void,

 // methods: parameters
    QMetaType::QStringList,
    QMetaType::QString, QMetaType::QString,    4,
    QMetaType::QString, QMetaType::QString,    4,
    QMetaType::QString, QMetaType::QString,    4,
    QMetaType::QString, QMetaType::QString,    4,
    QMetaType::QStringList, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
      26, QMetaType::QString, 0x00495001,

 // properties: notify_signal_id
       0,

       0        // eod
};

void MusicPlayer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MusicPlayer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->musicProgressChanged(); break;
        case 1: _t->currentSongChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->nextSongInfo((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 3: _t->updateProgress(); break;
        case 4: { QStringList _r = _t->getMusics();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 5: { QString _r = _t->getCoverForSong((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 6: { QString _r = _t->getArtistForSong((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 7: { QString _r = _t->getTitleForSong((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 8: { QString _r = _t->getPathForSong((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 9: { QStringList _r = _t->getCurrentPlayList((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 10: _t->setMusic((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: _t->playMusic((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 12: _t->pauseMusic(); break;
        case 13: _t->stopMusic(); break;
        case 14: { bool _r = _t->playState();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 15: { int _r = _t->music_duration();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 16: { int _r = _t->music_position();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 17: _t->skipNext(); break;
        case 18: _t->skipPrevious(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MusicPlayer::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MusicPlayer::musicProgressChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MusicPlayer::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MusicPlayer::currentSongChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MusicPlayer::*)(const QString & , const QString & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MusicPlayer::nextSongInfo)) {
                *result = 2;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<MusicPlayer *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->musicProgress(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject MusicPlayer::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_MusicPlayer.data,
    qt_meta_data_MusicPlayer,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MusicPlayer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MusicPlayer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MusicPlayer.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int MusicPlayer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 19;
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
void MusicPlayer::musicProgressChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MusicPlayer::currentSongChanged(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MusicPlayer::nextSongInfo(const QString & _t1, const QString & _t2, const QString & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
