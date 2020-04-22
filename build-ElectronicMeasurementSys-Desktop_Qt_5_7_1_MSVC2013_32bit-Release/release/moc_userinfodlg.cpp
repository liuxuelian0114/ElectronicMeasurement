/****************************************************************************
** Meta object code from reading C++ file 'userinfodlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../userinfodlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'userinfodlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_UserInfoDlg_t {
    QByteArrayData data[5];
    char stringdata0[57];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UserInfoDlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UserInfoDlg_t qt_meta_stringdata_UserInfoDlg = {
    {
QT_MOC_LITERAL(0, 0, 11), // "UserInfoDlg"
QT_MOC_LITERAL(1, 12, 15), // "userInfoChanged"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 5), // "infos"
QT_MOC_LITERAL(4, 35, 21) // "onPushButtonOkClicked"

    },
    "UserInfoDlg\0userInfoChanged\0\0infos\0"
    "onPushButtonOkClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UserInfoDlg[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   27,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QStringList,    3,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void UserInfoDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UserInfoDlg *_t = static_cast<UserInfoDlg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->userInfoChanged((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 1: _t->onPushButtonOkClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (UserInfoDlg::*_t)(QStringList );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UserInfoDlg::userInfoChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject UserInfoDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_UserInfoDlg.data,
      qt_meta_data_UserInfoDlg,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *UserInfoDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UserInfoDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_UserInfoDlg.stringdata0))
        return static_cast<void*>(const_cast< UserInfoDlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int UserInfoDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void UserInfoDlg::userInfoChanged(QStringList _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
