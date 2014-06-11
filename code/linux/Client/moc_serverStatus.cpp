/****************************************************************************
** Meta object code from reading C++ file 'serverStatus.h'
**
** Created: Sun Apr 17 16:45:15 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "serverStatus.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serverStatus.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ServerStatus[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
      30,   13,   13,   13, 0x08,
      94,   13,   13,   13, 0x08,
     107,   13,   13,   13, 0x08,
     136,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ServerStatus[] = {
    "ServerStatus\0\0disconnection()\0"
    "on_clientStatus_client_TBW_itemDoubleClicked(QTableWidgetItem*)\0"
    "getNewData()\0on_quit_client_BTN_clicked()\0"
    "on_create_client_BTN_clicked()\0"
};

const QMetaObject ServerStatus::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ServerStatus,
      qt_meta_data_ServerStatus, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ServerStatus::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ServerStatus::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ServerStatus::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ServerStatus))
        return static_cast<void*>(const_cast< ServerStatus*>(this));
    return QDialog::qt_metacast(_clname);
}

int ServerStatus::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: disconnection(); break;
        case 1: on_clientStatus_client_TBW_itemDoubleClicked((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 2: getNewData(); break;
        case 3: on_quit_client_BTN_clicked(); break;
        case 4: on_create_client_BTN_clicked(); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void ServerStatus::disconnection()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
