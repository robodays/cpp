/****************************************************************************
** Meta object code from reading C++ file 'callermainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../callermainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'callermainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CallerMainWindow_t {
    const uint offsetsAndSize[26];
    char stringdata0[77];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_CallerMainWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_CallerMainWindow_t qt_meta_stringdata_CallerMainWindow = {
    {
QT_MOC_LITERAL(0, 16), // "CallerMainWindow"
QT_MOC_LITERAL(17, 4), // "add0"
QT_MOC_LITERAL(22, 0), // ""
QT_MOC_LITERAL(23, 4), // "add1"
QT_MOC_LITERAL(28, 4), // "add2"
QT_MOC_LITERAL(33, 4), // "add3"
QT_MOC_LITERAL(38, 4), // "add4"
QT_MOC_LITERAL(43, 4), // "add5"
QT_MOC_LITERAL(48, 4), // "add6"
QT_MOC_LITERAL(53, 4), // "add7"
QT_MOC_LITERAL(58, 4), // "add8"
QT_MOC_LITERAL(63, 4), // "add9"
QT_MOC_LITERAL(68, 8) // "makeCall"

    },
    "CallerMainWindow\0add0\0\0add1\0add2\0add3\0"
    "add4\0add5\0add6\0add7\0add8\0add9\0makeCall"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CallerMainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   80,    2, 0x0a,    1 /* Public */,
       3,    0,   81,    2, 0x0a,    2 /* Public */,
       4,    0,   82,    2, 0x0a,    3 /* Public */,
       5,    0,   83,    2, 0x0a,    4 /* Public */,
       6,    0,   84,    2, 0x0a,    5 /* Public */,
       7,    0,   85,    2, 0x0a,    6 /* Public */,
       8,    0,   86,    2, 0x0a,    7 /* Public */,
       9,    0,   87,    2, 0x0a,    8 /* Public */,
      10,    0,   88,    2, 0x0a,    9 /* Public */,
      11,    0,   89,    2, 0x0a,   10 /* Public */,
      12,    0,   90,    2, 0x0a,   11 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CallerMainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CallerMainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->add0(); break;
        case 1: _t->add1(); break;
        case 2: _t->add2(); break;
        case 3: _t->add3(); break;
        case 4: _t->add4(); break;
        case 5: _t->add5(); break;
        case 6: _t->add6(); break;
        case 7: _t->add7(); break;
        case 8: _t->add8(); break;
        case 9: _t->add9(); break;
        case 10: _t->makeCall(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject CallerMainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CallerMainWindow.offsetsAndSize,
    qt_meta_data_CallerMainWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_CallerMainWindow_t
, QtPrivate::TypeAndForceComplete<CallerMainWindow, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *CallerMainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CallerMainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CallerMainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int CallerMainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
