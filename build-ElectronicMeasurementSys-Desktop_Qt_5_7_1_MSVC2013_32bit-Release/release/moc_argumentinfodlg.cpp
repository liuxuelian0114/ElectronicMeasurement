/****************************************************************************
** Meta object code from reading C++ file 'argumentinfodlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../argumentinfodlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'argumentinfodlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ArgumentInfoDlg_t {
    QByteArrayData data[12];
    char stringdata0[144];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ArgumentInfoDlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ArgumentInfoDlg_t qt_meta_stringdata_ArgumentInfoDlg = {
    {
QT_MOC_LITERAL(0, 0, 15), // "ArgumentInfoDlg"
QT_MOC_LITERAL(1, 16, 15), // "testArgsChanges"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 7), // "oldName"
QT_MOC_LITERAL(4, 41, 7), // "newName"
QT_MOC_LITERAL(5, 49, 15), // "settingTemplate"
QT_MOC_LITERAL(6, 65, 11), // "addTemplate"
QT_MOC_LITERAL(7, 77, 8), // "testName"
QT_MOC_LITERAL(8, 86, 14), // "deleteTemplate"
QT_MOC_LITERAL(9, 101, 23), // "onPushButtonSaveClicked"
QT_MOC_LITERAL(10, 125, 13), // "onTextChanged"
QT_MOC_LITERAL(11, 139, 4) // "text"

    },
    "ArgumentInfoDlg\0testArgsChanges\0\0"
    "oldName\0newName\0settingTemplate\0"
    "addTemplate\0testName\0deleteTemplate\0"
    "onPushButtonSaveClicked\0onTextChanged\0"
    "text"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ArgumentInfoDlg[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   44,    2, 0x06 /* Public */,
       5,    2,   49,    2, 0x06 /* Public */,
       6,    1,   54,    2, 0x06 /* Public */,
       8,    0,   57,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   58,    2, 0x0a /* Public */,
      10,    1,   59,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   11,

       0        // eod
};

void ArgumentInfoDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ArgumentInfoDlg *_t = static_cast<ArgumentInfoDlg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->testArgsChanges((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->settingTemplate((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->addTemplate((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->deleteTemplate(); break;
        case 4: _t->onPushButtonSaveClicked(); break;
        case 5: _t->onTextChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ArgumentInfoDlg::*_t)(QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ArgumentInfoDlg::testArgsChanges)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ArgumentInfoDlg::*_t)(QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ArgumentInfoDlg::settingTemplate)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (ArgumentInfoDlg::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ArgumentInfoDlg::addTemplate)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (ArgumentInfoDlg::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ArgumentInfoDlg::deleteTemplate)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject ArgumentInfoDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ArgumentInfoDlg.data,
      qt_meta_data_ArgumentInfoDlg,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ArgumentInfoDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ArgumentInfoDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ArgumentInfoDlg.stringdata0))
        return static_cast<void*>(const_cast< ArgumentInfoDlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int ArgumentInfoDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void ArgumentInfoDlg::testArgsChanges(QString _t1, QString _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ArgumentInfoDlg::settingTemplate(QString _t1, QString _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ArgumentInfoDlg::addTemplate(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ArgumentInfoDlg::deleteTemplate()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
