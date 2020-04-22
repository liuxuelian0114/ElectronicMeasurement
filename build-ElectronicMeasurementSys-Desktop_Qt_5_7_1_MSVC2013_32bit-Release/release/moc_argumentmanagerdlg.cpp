/****************************************************************************
** Meta object code from reading C++ file 'argumentmanagerdlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../argumentmanagerdlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'argumentmanagerdlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ArgumentManagerDlg_t {
    QByteArrayData data[10];
    char stringdata0[148];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ArgumentManagerDlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ArgumentManagerDlg_t qt_meta_stringdata_ArgumentManagerDlg = {
    {
QT_MOC_LITERAL(0, 0, 18), // "ArgumentManagerDlg"
QT_MOC_LITERAL(1, 19, 17), // "onSettingTemplate"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 7), // "oldName"
QT_MOC_LITERAL(4, 46, 7), // "newName"
QT_MOC_LITERAL(5, 54, 13), // "onAddTemplate"
QT_MOC_LITERAL(6, 68, 4), // "name"
QT_MOC_LITERAL(7, 73, 23), // "onPushButtonAddTemplate"
QT_MOC_LITERAL(8, 97, 23), // "onPushButtonSetTemplate"
QT_MOC_LITERAL(9, 121, 26) // "onPushButtonDaleteTemplate"

    },
    "ArgumentManagerDlg\0onSettingTemplate\0"
    "\0oldName\0newName\0onAddTemplate\0name\0"
    "onPushButtonAddTemplate\0onPushButtonSetTemplate\0"
    "onPushButtonDaleteTemplate"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ArgumentManagerDlg[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   39,    2, 0x08 /* Private */,
       5,    1,   44,    2, 0x08 /* Private */,
       7,    0,   47,    2, 0x08 /* Private */,
       8,    0,   48,    2, 0x08 /* Private */,
       9,    0,   49,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ArgumentManagerDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ArgumentManagerDlg *_t = static_cast<ArgumentManagerDlg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onSettingTemplate((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->onAddTemplate((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->onPushButtonAddTemplate(); break;
        case 3: _t->onPushButtonSetTemplate(); break;
        case 4: _t->onPushButtonDaleteTemplate(); break;
        default: ;
        }
    }
}

const QMetaObject ArgumentManagerDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ArgumentManagerDlg.data,
      qt_meta_data_ArgumentManagerDlg,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ArgumentManagerDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ArgumentManagerDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ArgumentManagerDlg.stringdata0))
        return static_cast<void*>(const_cast< ArgumentManagerDlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int ArgumentManagerDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
