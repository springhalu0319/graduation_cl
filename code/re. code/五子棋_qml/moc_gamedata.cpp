/****************************************************************************
** Meta object code from reading C++ file 'gamedata.h'
**
** Created: Wed Dec 8 21:23:25 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "gamedata.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gamedata.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GameData[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       5,   59, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x05,
      25,    9,    9,    9, 0x05,
      43,    9,    9,    9, 0x05,
      64,    9,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
      80,    9,    9,    9, 0x0a,
      98,   92,    9,    9, 0x0a,
     120,  114,    9,    9, 0x0a,
     130,    9,    9,    9, 0x0a,
     141,    9,    9,    9, 0x0a,

 // properties: name, type, flags
     158,  154, 0x02495103,
     172,  164, 0x0a495103,
     186,  181, 0x01495103,
     198,  181, 0x01495103,
     236,  205, 0x00095409,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,
       0,

       0        // eod
};

static const char qt_meta_stringdata_GameData[] = {
    "GameData\0\0movesChanged()\0gameTimeChanged()\0"
    "player1TurnChanged()\0gameOnChanged()\0"
    "resetGame()\0state\0pauseGame(bool)\0"
    "index\0flip(int)\0undoTile()\0updateTime()\0"
    "int\0moves\0QString\0gameTime\0bool\0"
    "player1Turn\0gameOn\0QDeclarativeListProperty<Tile>\0"
    "tiles\0"
};

const QMetaObject GameData::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_GameData,
      qt_meta_data_GameData, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GameData::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GameData::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GameData::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GameData))
        return static_cast<void*>(const_cast< GameData*>(this));
    return QObject::qt_metacast(_clname);
}

int GameData::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: movesChanged(); break;
        case 1: gameTimeChanged(); break;
        case 2: player1TurnChanged(); break;
        case 3: gameOnChanged(); break;
        case 4: resetGame(); break;
        case 5: pauseGame((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: flip((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: undoTile(); break;
        case 8: updateTime(); break;
        default: ;
        }
        _id -= 9;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = moves(); break;
        case 1: *reinterpret_cast< QString*>(_v) = gameTime(); break;
        case 2: *reinterpret_cast< bool*>(_v) = player1Turn(); break;
        case 3: *reinterpret_cast< bool*>(_v) = gameOn(); break;
        case 4: *reinterpret_cast< QDeclarativeListProperty<Tile>*>(_v) = tiles(); break;
        }
        _id -= 5;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setMoves(*reinterpret_cast< int*>(_v)); break;
        case 1: setGameTime(*reinterpret_cast< QString*>(_v)); break;
        case 2: setPlayer1Turn(*reinterpret_cast< bool*>(_v)); break;
        case 3: setGameOn(*reinterpret_cast< bool*>(_v)); break;
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
void GameData::movesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void GameData::gameTimeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void GameData::player1TurnChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void GameData::gameOnChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE
