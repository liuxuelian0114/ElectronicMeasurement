/****************************************************************************
** Meta object code from reading C++ file 'ReceivePulseData.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../pulse/ReceivePulseData.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ReceivePulseData.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ReceivePulseData_t {
    QByteArrayData data[6];
    char stringdata0[77];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ReceivePulseData_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ReceivePulseData_t qt_meta_stringdata_ReceivePulseData = {
    {
QT_MOC_LITERAL(0, 0, 16), // "ReceivePulseData"
QT_MOC_LITERAL(1, 17, 17), // "pulseImageUpdated"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 7), // "QImage*"
QT_MOC_LITERAL(4, 44, 15), // "onNewConnection"
QT_MOC_LITERAL(5, 60, 16) // "onPulseReadyRead"

    },
    "ReceivePulseData\0pulseImageUpdated\0\0"
    "QImage*\0onNewConnection\0onPulseReadyRead"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ReceivePulseData[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   36,    2, 0x0a /* Public */,
       5,    0,   37,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int, QMetaType::Int,    2,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ReceivePulseData::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ReceivePulseData *_t = static_cast<ReceivePulseData *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->pulseImageUpdated((*reinterpret_cast< QImage*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: _t->onNewConnection(); break;
        case 2: _t->onPulseReadyRead(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ReceivePulseData::*_t)(QImage * , int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ReceivePulseData::pulseImageUpdated)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject ReceivePulseData::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ReceivePulseData.data,
      qt_meta_data_ReceivePulseData,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ReceivePulseData::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ReceivePulseData::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ReceivePulseData.stringdata0))
        return static_cast<void*>(const_cast< ReceivePulseData*>(this));
    return QObject::qt_metacast(_clname);
}

int ReceivePulseData::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void ReceivePulseData::pulseImageUpdated(QImage * _t1, int _t2, int _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
