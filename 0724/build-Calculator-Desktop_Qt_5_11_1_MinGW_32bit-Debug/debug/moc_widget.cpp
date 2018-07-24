/****************************************************************************
** Meta object code from reading C++ file 'widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Calculator/widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Widget_t {
    QByteArrayData data[18];
    char stringdata0[151];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Widget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Widget_t qt_meta_stringdata_Widget = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Widget"
QT_MOC_LITERAL(1, 7, 8), // "slotZero"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 7), // "slotOne"
QT_MOC_LITERAL(4, 25, 7), // "slotTwo"
QT_MOC_LITERAL(5, 33, 9), // "slotThree"
QT_MOC_LITERAL(6, 43, 8), // "slotFour"
QT_MOC_LITERAL(7, 52, 8), // "slotFive"
QT_MOC_LITERAL(8, 61, 7), // "slotSix"
QT_MOC_LITERAL(9, 69, 9), // "slotSeven"
QT_MOC_LITERAL(10, 79, 9), // "slotEight"
QT_MOC_LITERAL(11, 89, 8), // "slotNine"
QT_MOC_LITERAL(12, 98, 7), // "slotAdd"
QT_MOC_LITERAL(13, 106, 7), // "slotSub"
QT_MOC_LITERAL(14, 114, 7), // "slotDiv"
QT_MOC_LITERAL(15, 122, 7), // "slotMul"
QT_MOC_LITERAL(16, 130, 9), // "slotClear"
QT_MOC_LITERAL(17, 140, 10) // "slotResult"

    },
    "Widget\0slotZero\0\0slotOne\0slotTwo\0"
    "slotThree\0slotFour\0slotFive\0slotSix\0"
    "slotSeven\0slotEight\0slotNine\0slotAdd\0"
    "slotSub\0slotDiv\0slotMul\0slotClear\0"
    "slotResult"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Widget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x0a /* Public */,
       3,    0,   95,    2, 0x0a /* Public */,
       4,    0,   96,    2, 0x0a /* Public */,
       5,    0,   97,    2, 0x0a /* Public */,
       6,    0,   98,    2, 0x0a /* Public */,
       7,    0,   99,    2, 0x0a /* Public */,
       8,    0,  100,    2, 0x0a /* Public */,
       9,    0,  101,    2, 0x0a /* Public */,
      10,    0,  102,    2, 0x0a /* Public */,
      11,    0,  103,    2, 0x0a /* Public */,
      12,    0,  104,    2, 0x0a /* Public */,
      13,    0,  105,    2, 0x0a /* Public */,
      14,    0,  106,    2, 0x0a /* Public */,
      15,    0,  107,    2, 0x0a /* Public */,
      16,    0,  108,    2, 0x0a /* Public */,
      17,    0,  109,    2, 0x0a /* Public */,

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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Widget *_t = static_cast<Widget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slotZero(); break;
        case 1: _t->slotOne(); break;
        case 2: _t->slotTwo(); break;
        case 3: _t->slotThree(); break;
        case 4: _t->slotFour(); break;
        case 5: _t->slotFive(); break;
        case 6: _t->slotSix(); break;
        case 7: _t->slotSeven(); break;
        case 8: _t->slotEight(); break;
        case 9: _t->slotNine(); break;
        case 10: _t->slotAdd(); break;
        case 11: _t->slotSub(); break;
        case 12: _t->slotDiv(); break;
        case 13: _t->slotMul(); break;
        case 14: _t->slotClear(); break;
        case 15: _t->slotResult(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Widget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Widget.data,
      qt_meta_data_Widget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Widget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
