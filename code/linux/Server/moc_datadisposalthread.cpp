/****************************************************************************
** Meta object code from reading C++ file 'datadisposalthread.h'
**
** Created: Sun Apr 17 16:44:25 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "datadisposalthread.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'datadisposalthread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DataDisposalThread[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      20,   19,   19,   19, 0x05,
      41,   19,   19,   19, 0x05,
      63,   61,   19,   19, 0x05,
      89,   61,   19,   19, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_DataDisposalThread[] = {
    "DataDisposalThread\0\0updateCurConnCount()\0"
    "createRoom(QString)\0,\0quitRoom(QString,QString)\0"
    "joinRoom(QString,QString)\0"
};

const QMetaObject DataDisposalThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_DataDisposalThread,
      qt_meta_data_DataDisposalThread, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DataDisposalThread::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DataDisposalThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DataDisposalThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DataDisposalThread))
        return static_cast<void*>(const_cast< DataDisposalThread*>(this));
    return QThread::qt_metacast(_clname);
}

int DataDisposalThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: updateCurConnCount(); break;
        case 1: createRoom((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: quitRoom((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: joinRoom((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void DataDisposalThread::updateCurConnCount()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void DataDisposalThread::createRoom(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void DataDisposalThread::quitRoom(QString _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void DataDisposalThread::joinRoom(QString _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
