/****************************************************************************
** Meta object code from reading C++ file 'maingame2.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../TypeDestiny/maingame2.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'maingame2.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainGame2_t {
    QByteArrayData data[10];
    char stringdata[92];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainGame2_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainGame2_t qt_meta_stringdata_MainGame2 = {
    {
QT_MOC_LITERAL(0, 0, 9), // "MainGame2"
QT_MOC_LITERAL(1, 10, 15), // "onReturnPressed"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 8), // "userName"
QT_MOC_LITERAL(4, 36, 5), // "delay"
QT_MOC_LITERAL(5, 42, 5), // "msecs"
QT_MOC_LITERAL(6, 48, 17), // "displayBackground"
QT_MOC_LITERAL(7, 66, 9), // "startGame"
QT_MOC_LITERAL(8, 76, 9), // "fillChars"
QT_MOC_LITERAL(9, 86, 5) // "char*"

    },
    "MainGame2\0onReturnPressed\0\0userName\0"
    "delay\0msecs\0displayBackground\0startGame\0"
    "fillChars\0char*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainGame2[] = {

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
       1,    1,   39,    2, 0x0a /* Public */,
       4,    1,   42,    2, 0x0a /* Public */,
       6,    0,   45,    2, 0x0a /* Public */,
       7,    0,   46,    2, 0x0a /* Public */,
       8,    2,   47,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9, QMetaType::Int,    2,    2,

       0        // eod
};

void MainGame2::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainGame2 *_t = static_cast<MainGame2 *>(_o);
        switch (_id) {
        case 0: _t->onReturnPressed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->delay((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->displayBackground(); break;
        case 3: _t->startGame(); break;
        case 4: _t->fillChars((*reinterpret_cast< char*(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject MainGame2::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MainGame2.data,
      qt_meta_data_MainGame2,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainGame2::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainGame2::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainGame2.stringdata))
        return static_cast<void*>(const_cast< MainGame2*>(this));
    return QWidget::qt_metacast(_clname);
}

int MainGame2::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
