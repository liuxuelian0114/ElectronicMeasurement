/****************************************************************************
** Meta object code from reading C++ file 'configcmdpacket.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../configcmdpacket.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'configcmdpacket.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ConfigCmdPacket_t {
    QByteArrayData data[26];
    char stringdata0[341];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ConfigCmdPacket_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ConfigCmdPacket_t qt_meta_stringdata_ConfigCmdPacket = {
    {
QT_MOC_LITERAL(0, 0, 15), // "ConfigCmdPacket"
QT_MOC_LITERAL(1, 16, 12), // "onCmdChanged"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 5), // "state"
QT_MOC_LITERAL(4, 36, 9), // "checkArgs"
QT_MOC_LITERAL(5, 46, 7), // "cmdArgs"
QT_MOC_LITERAL(6, 54, 11), // "onRFStarted"
QT_MOC_LITERAL(7, 66, 5), // "start"
QT_MOC_LITERAL(8, 72, 3), // "end"
QT_MOC_LITERAL(9, 76, 5), // "power"
QT_MOC_LITERAL(10, 82, 11), // "onRFStopped"
QT_MOC_LITERAL(11, 94, 12), // "onRFSelfTest"
QT_MOC_LITERAL(12, 107, 9), // "onRFReset"
QT_MOC_LITERAL(13, 117, 10), // "onRFAdjust"
QT_MOC_LITERAL(14, 128, 15), // "onServoContinue"
QT_MOC_LITERAL(15, 144, 4), // "list"
QT_MOC_LITERAL(16, 149, 22), // "onServoContinueTimeout"
QT_MOC_LITERAL(17, 172, 18), // "onServoDisContinue"
QT_MOC_LITERAL(18, 191, 16), // "onServoReturnRun"
QT_MOC_LITERAL(19, 208, 23), // "onServoReturnRunTimeOut"
QT_MOC_LITERAL(20, 232, 15), // "onServoPauseRun"
QT_MOC_LITERAL(21, 248, 17), // "onServoUnPauseRun"
QT_MOC_LITERAL(22, 266, 14), // "onServoStopRun"
QT_MOC_LITERAL(23, 281, 21), // "onServoStopRunTimeOut"
QT_MOC_LITERAL(24, 303, 17), // "onRFNormalCollect"
QT_MOC_LITERAL(25, 321, 19) // "onRFEnvelopeCollect"

    },
    "ConfigCmdPacket\0onCmdChanged\0\0state\0"
    "checkArgs\0cmdArgs\0onRFStarted\0start\0"
    "end\0power\0onRFStopped\0onRFSelfTest\0"
    "onRFReset\0onRFAdjust\0onServoContinue\0"
    "list\0onServoContinueTimeout\0"
    "onServoDisContinue\0onServoReturnRun\0"
    "onServoReturnRunTimeOut\0onServoPauseRun\0"
    "onServoUnPauseRun\0onServoStopRun\0"
    "onServoStopRunTimeOut\0onRFNormalCollect\0"
    "onRFEnvelopeCollect"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ConfigCmdPacket[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    3,   99,    2, 0x0a /* Public */,
       6,    3,  106,    2, 0x0a /* Public */,
      10,    0,  113,    2, 0x0a /* Public */,
      11,    1,  114,    2, 0x0a /* Public */,
      12,    1,  117,    2, 0x0a /* Public */,
      13,    1,  120,    2, 0x0a /* Public */,
      14,    1,  123,    2, 0x0a /* Public */,
      16,    0,  126,    2, 0x0a /* Public */,
      17,    1,  127,    2, 0x0a /* Public */,
      18,    1,  130,    2, 0x0a /* Public */,
      19,    0,  133,    2, 0x0a /* Public */,
      20,    0,  134,    2, 0x0a /* Public */,
      21,    0,  135,    2, 0x0a /* Public */,
      22,    0,  136,    2, 0x0a /* Public */,
      23,    0,  137,    2, 0x0a /* Public */,
      24,    0,  138,    2, 0x0a /* Public */,
      25,    0,  139,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool, QMetaType::QStringList, QMetaType::QStringList,    3,    4,    5,
    QMetaType::Void, QMetaType::UShort, QMetaType::UShort, QMetaType::UShort,    7,    8,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UShort,    3,
    QMetaType::Void, QMetaType::UShort,    3,
    QMetaType::Void, QMetaType::UShort,    3,
    QMetaType::Void, QMetaType::QStringList,   15,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QStringList,   15,
    QMetaType::Void, QMetaType::QStringList,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ConfigCmdPacket::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ConfigCmdPacket *_t = static_cast<ConfigCmdPacket *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onCmdChanged((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< const QStringList(*)>(_a[2])),(*reinterpret_cast< const QStringList(*)>(_a[3]))); break;
        case 1: _t->onRFStarted((*reinterpret_cast< ushort(*)>(_a[1])),(*reinterpret_cast< ushort(*)>(_a[2])),(*reinterpret_cast< ushort(*)>(_a[3]))); break;
        case 2: _t->onRFStopped(); break;
        case 3: _t->onRFSelfTest((*reinterpret_cast< ushort(*)>(_a[1]))); break;
        case 4: _t->onRFReset((*reinterpret_cast< ushort(*)>(_a[1]))); break;
        case 5: _t->onRFAdjust((*reinterpret_cast< ushort(*)>(_a[1]))); break;
        case 6: _t->onServoContinue((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 7: _t->onServoContinueTimeout(); break;
        case 8: _t->onServoDisContinue((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 9: _t->onServoReturnRun((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 10: _t->onServoReturnRunTimeOut(); break;
        case 11: _t->onServoPauseRun(); break;
        case 12: _t->onServoUnPauseRun(); break;
        case 13: _t->onServoStopRun(); break;
        case 14: _t->onServoStopRunTimeOut(); break;
        case 15: _t->onRFNormalCollect(); break;
        case 16: _t->onRFEnvelopeCollect(); break;
        default: ;
        }
    }
}

const QMetaObject ConfigCmdPacket::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ConfigCmdPacket.data,
      qt_meta_data_ConfigCmdPacket,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ConfigCmdPacket::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ConfigCmdPacket::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ConfigCmdPacket.stringdata0))
        return static_cast<void*>(const_cast< ConfigCmdPacket*>(this));
    return QObject::qt_metacast(_clname);
}

int ConfigCmdPacket::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
