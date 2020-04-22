/****************************************************************************
** Meta object code from reading C++ file 'recvuppacket.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../recvuppacket.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'recvuppacket.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_RecvUpPacket_t {
    QByteArrayData data[16];
    char stringdata0[151];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RecvUpPacket_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RecvUpPacket_t qt_meta_stringdata_RecvUpPacket = {
    {
QT_MOC_LITERAL(0, 0, 12), // "RecvUpPacket"
QT_MOC_LITERAL(1, 13, 11), // "dataChanged"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 4), // "data"
QT_MOC_LITERAL(4, 31, 14), // "RFStateChanged"
QT_MOC_LITERAL(5, 46, 5), // "rAddr"
QT_MOC_LITERAL(6, 52, 17), // "servoStateChanged"
QT_MOC_LITERAL(7, 70, 5), // "state"
QT_MOC_LITERAL(8, 76, 16), // "servoCoorChanged"
QT_MOC_LITERAL(9, 93, 1), // "x"
QT_MOC_LITERAL(10, 95, 1), // "y"
QT_MOC_LITERAL(11, 97, 16), // "servoTimeChanged"
QT_MOC_LITERAL(12, 114, 4), // "time"
QT_MOC_LITERAL(13, 119, 16), // "onStartParseData"
QT_MOC_LITERAL(14, 136, 2), // "ok"
QT_MOC_LITERAL(15, 139, 11) // "onReadyRead"

    },
    "RecvUpPacket\0dataChanged\0\0data\0"
    "RFStateChanged\0rAddr\0servoStateChanged\0"
    "state\0servoCoorChanged\0x\0y\0servoTimeChanged\0"
    "time\0onStartParseData\0ok\0onReadyRead"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RecvUpPacket[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       4,    2,   52,    2, 0x06 /* Public */,
       6,    1,   57,    2, 0x06 /* Public */,
       8,    2,   60,    2, 0x06 /* Public */,
      11,    1,   65,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    1,   68,    2, 0x0a /* Public */,
      15,    0,   71,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray,    3,
    QMetaType::Void, QMetaType::UChar, QMetaType::UShort,    5,    3,
    QMetaType::Void, QMetaType::UShort,    7,
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt,    9,   10,
    QMetaType::Void, QMetaType::UInt,   12,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,   14,
    QMetaType::Void,

       0        // eod
};

void RecvUpPacket::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RecvUpPacket *_t = static_cast<RecvUpPacket *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->dataChanged((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 1: _t->RFStateChanged((*reinterpret_cast< uchar(*)>(_a[1])),(*reinterpret_cast< ushort(*)>(_a[2]))); break;
        case 2: _t->servoStateChanged((*reinterpret_cast< ushort(*)>(_a[1]))); break;
        case 3: _t->servoCoorChanged((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2]))); break;
        case 4: _t->servoTimeChanged((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 5: _t->onStartParseData((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->onReadyRead(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (RecvUpPacket::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RecvUpPacket::dataChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (RecvUpPacket::*_t)(uchar , ushort );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RecvUpPacket::RFStateChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (RecvUpPacket::*_t)(ushort );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RecvUpPacket::servoStateChanged)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (RecvUpPacket::*_t)(unsigned int , unsigned int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RecvUpPacket::servoCoorChanged)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (RecvUpPacket::*_t)(uint );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RecvUpPacket::servoTimeChanged)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject RecvUpPacket::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_RecvUpPacket.data,
      qt_meta_data_RecvUpPacket,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *RecvUpPacket::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RecvUpPacket::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_RecvUpPacket.stringdata0))
        return static_cast<void*>(const_cast< RecvUpPacket*>(this));
    return QObject::qt_metacast(_clname);
}

int RecvUpPacket::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void RecvUpPacket::dataChanged(QByteArray _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void RecvUpPacket::RFStateChanged(uchar _t1, ushort _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void RecvUpPacket::servoStateChanged(ushort _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void RecvUpPacket::servoCoorChanged(unsigned int _t1, unsigned int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void RecvUpPacket::servoTimeChanged(uint _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
