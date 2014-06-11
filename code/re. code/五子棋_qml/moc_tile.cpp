/****************************************************************************
** Meta object code from reading C++ file 'tile.h'
**
** Created: Wed Dec 8 21:23:22 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "tile.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tile.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Tile[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       3,   29, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
       6,    5,    5,    5, 0x05,
      26,    5,    5,    5, 0x05,
      46,    5,    5,    5, 0x05,

 // properties: name, type, flags
      72,   67, 0x01495103,
      83,   67, 0x01495103,
      94,   67, 0x01495103,

 // properties: notify_signal_id
       0,
       1,
       2,

       0        // eod
};

static const char qt_meta_stringdata_Tile[] = {
    "Tile\0\0hasButton1Changed()\0hasButton2Changed()\0"
    "highlightedChanged()\0bool\0hasButton1\0"
    "hasButton2\0highlighted\0"
};

const QMetaObject Tile::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Tile,
      qt_meta_data_Tile, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Tile::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Tile::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Tile::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Tile))
        return static_cast<void*>(const_cast< Tile*>(this));
    return QObject::qt_metacast(_clname);
}

int Tile::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: hasButton1Changed(); break;
        case 1: hasButton2Changed(); break;
        case 2: highlightedChanged(); break;
        default: ;
        }
        _id -= 3;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = hasButton1(); break;
        case 1: *reinterpret_cast< bool*>(_v) = hasButton2(); break;
        case 2: *reinterpret_cast< bool*>(_v) = highlighted(); break;
        }
        _id -= 3;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setHasButton1(*reinterpret_cast< bool*>(_v)); break;
        case 1: setHasButton2(*reinterpret_cast< bool*>(_v)); break;
        case 2: setHighlighted(*reinterpret_cast< bool*>(_v)); break;
        }
        _id -= 3;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Tile::hasButton1Changed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Tile::hasButton2Changed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void Tile::highlightedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
