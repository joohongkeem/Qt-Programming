/****************************************************************************
** Meta object code from reading C++ file 'qteditor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../qtEditor/qteditor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qteditor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QtEditor_t {
    QByteArrayData data[18];
    char stringdata0[169];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QtEditor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QtEditor_t qt_meta_stringdata_QtEditor = {
    {
QT_MOC_LITERAL(0, 0, 8), // "QtEditor"
QT_MOC_LITERAL(1, 9, 7), // "newFile"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 8), // "openFile"
QT_MOC_LITERAL(4, 27, 8), // "saveFile"
QT_MOC_LITERAL(5, 36, 10), // "saveasFile"
QT_MOC_LITERAL(6, 47, 9), // "printFile"
QT_MOC_LITERAL(7, 57, 9), // "alignText"
QT_MOC_LITERAL(8, 67, 8), // "slotEdit"
QT_MOC_LITERAL(9, 76, 10), // "slotWindow"
QT_MOC_LITERAL(10, 87, 9), // "slotAbout"
QT_MOC_LITERAL(11, 97, 8), // "slotFont"
QT_MOC_LITERAL(12, 106, 4), // "font"
QT_MOC_LITERAL(13, 111, 12), // "slotFontSize"
QT_MOC_LITERAL(14, 124, 4), // "size"
QT_MOC_LITERAL(15, 129, 14), // "slotFontWidget"
QT_MOC_LITERAL(16, 144, 12), // "slotSetColor"
QT_MOC_LITERAL(17, 157, 11) // "slotSetFont"

    },
    "QtEditor\0newFile\0\0openFile\0saveFile\0"
    "saveasFile\0printFile\0alignText\0slotEdit\0"
    "slotWindow\0slotAbout\0slotFont\0font\0"
    "slotFontSize\0size\0slotFontWidget\0"
    "slotSetColor\0slotSetFont"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QtEditor[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x0a /* Public */,
       3,    0,   85,    2, 0x0a /* Public */,
       4,    0,   86,    2, 0x0a /* Public */,
       5,    0,   87,    2, 0x0a /* Public */,
       6,    0,   88,    2, 0x0a /* Public */,
       7,    0,   89,    2, 0x0a /* Public */,
       8,    0,   90,    2, 0x0a /* Public */,
       9,    0,   91,    2, 0x0a /* Public */,
      10,    0,   92,    2, 0x0a /* Public */,
      11,    1,   93,    2, 0x0a /* Public */,
      13,    1,   96,    2, 0x0a /* Public */,
      15,    0,   99,    2, 0x0a /* Public */,
      16,    0,  100,    2, 0x0a /* Public */,
      17,    0,  101,    2, 0x0a /* Public */,

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
    QMetaType::Void, QMetaType::QFont,   12,
    QMetaType::Void, QMetaType::QReal,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QtEditor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QtEditor *_t = static_cast<QtEditor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newFile(); break;
        case 1: _t->openFile(); break;
        case 2: _t->saveFile(); break;
        case 3: _t->saveasFile(); break;
        case 4: _t->printFile(); break;
        case 5: _t->alignText(); break;
        case 6: _t->slotEdit(); break;
        case 7: _t->slotWindow(); break;
        case 8: _t->slotAbout(); break;
        case 9: _t->slotFont((*reinterpret_cast< QFont(*)>(_a[1]))); break;
        case 10: _t->slotFontSize((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 11: _t->slotFontWidget(); break;
        case 12: _t->slotSetColor(); break;
        case 13: _t->slotSetFont(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QtEditor::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_QtEditor.data,
      qt_meta_data_QtEditor,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QtEditor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtEditor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QtEditor.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int QtEditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
