/****************************************************************************
** Meta object code from reading C++ file 'gameStatus.h'
**
** Created: Sun Apr 17 16:45:16 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "gameStatus.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gameStatus.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GameStatus[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      41,   11,   11,   11, 0x08,
      70,   11,   11,   11, 0x08,
      99,   11,   11,   11, 0x08,
     128,   11,   11,   11, 0x08,
     162,   11,   11,   11, 0x08,
     185,   11,   11,   11, 0x08,
     208,   11,   11,   11, 0x08,
     221,   11,   11,   11, 0x08,
     238,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_GameStatus[] = {
    "GameStatus\0\0on_lose_client_BTN_clicked()\0"
    "on_undo_client_BTN_clicked()\0"
    "on_send_client_BTN_clicked()\0"
    "on_quit_client_BTN_clicked()\0"
    "on_gameReady_client_BTN_clicked()\0"
    "getNewDataFromServer()\0getNewDataFromClient()\0"
    "getNewConn()\0connSuccessful()\0"
    "connFailed()\0"
};

const QMetaObject GameStatus::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_GameStatus,
      qt_meta_data_GameStatus, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GameStatus::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GameStatus::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GameStatus::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GameStatus))
        return static_cast<void*>(const_cast< GameStatus*>(this));
    return QDialog::qt_metacast(_clname);
}

int GameStatus::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_lose_client_BTN_clicked(); break;
        case 1: on_undo_client_BTN_clicked(); break;
        case 2: on_send_client_BTN_clicked(); break;
        case 3: on_quit_client_BTN_clicked(); break;
        case 4: on_gameReady_client_BTN_clicked(); break;
        case 5: getNewDataFromServer(); break;
        case 6: getNewDataFromClient(); break;
        case 7: getNewConn(); break;
        case 8: connSuccessful(); break;
        case 9: connFailed(); break;
        default: ;
        }
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
