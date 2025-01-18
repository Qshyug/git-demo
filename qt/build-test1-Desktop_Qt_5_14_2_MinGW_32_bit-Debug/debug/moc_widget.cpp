/****************************************************************************
** Meta object code from reading C++ file 'widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../test1/widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Widget_t {
    QByteArrayData data[19];
    char stringdata0[397];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Widget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Widget_t qt_meta_stringdata_Widget = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Widget"
QT_MOC_LITERAL(1, 7, 23), // "on_spinBox1_textChanged"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 4), // "arg1"
QT_MOC_LITERAL(4, 37, 23), // "on_comboBox_2_activated"
QT_MOC_LITERAL(5, 61, 23), // "on_comboBox_3_activated"
QT_MOC_LITERAL(6, 85, 21), // "on_comboBox_activated"
QT_MOC_LITERAL(7, 107, 26), // "on_spinBox1_4_valueChanged"
QT_MOC_LITERAL(8, 134, 26), // "on_spinBox1_3_valueChanged"
QT_MOC_LITERAL(9, 161, 23), // "on_comboBox_4_activated"
QT_MOC_LITERAL(10, 185, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(11, 207, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(12, 231, 23), // "on_pushButton_3_clicked"
QT_MOC_LITERAL(13, 255, 23), // "on_pushButton_4_clicked"
QT_MOC_LITERAL(14, 279, 23), // "on_comboBox_5_activated"
QT_MOC_LITERAL(15, 303, 25), // "on_spinBox1_5_textChanged"
QT_MOC_LITERAL(16, 329, 26), // "on_spinBox1_6_valueChanged"
QT_MOC_LITERAL(17, 356, 20), // "on_auto_link_clicked"
QT_MOC_LITERAL(18, 377, 19) // "on_man_link_clicked"

    },
    "Widget\0on_spinBox1_textChanged\0\0arg1\0"
    "on_comboBox_2_activated\0on_comboBox_3_activated\0"
    "on_comboBox_activated\0on_spinBox1_4_valueChanged\0"
    "on_spinBox1_3_valueChanged\0"
    "on_comboBox_4_activated\0on_pushButton_clicked\0"
    "on_pushButton_2_clicked\0on_pushButton_3_clicked\0"
    "on_pushButton_4_clicked\0on_comboBox_5_activated\0"
    "on_spinBox1_5_textChanged\0"
    "on_spinBox1_6_valueChanged\0"
    "on_auto_link_clicked\0on_man_link_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Widget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   94,    2, 0x08 /* Private */,
       4,    1,   97,    2, 0x08 /* Private */,
       5,    1,  100,    2, 0x08 /* Private */,
       6,    1,  103,    2, 0x08 /* Private */,
       7,    1,  106,    2, 0x08 /* Private */,
       8,    1,  109,    2, 0x08 /* Private */,
       9,    1,  112,    2, 0x08 /* Private */,
      10,    0,  115,    2, 0x08 /* Private */,
      11,    0,  116,    2, 0x08 /* Private */,
      12,    0,  117,    2, 0x08 /* Private */,
      13,    0,  118,    2, 0x08 /* Private */,
      14,    1,  119,    2, 0x08 /* Private */,
      15,    1,  122,    2, 0x08 /* Private */,
      16,    1,  125,    2, 0x08 /* Private */,
      17,    0,  128,    2, 0x08 /* Private */,
      18,    0,  129,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Widget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_spinBox1_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->on_comboBox_2_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->on_comboBox_3_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->on_comboBox_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->on_spinBox1_4_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_spinBox1_3_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_comboBox_4_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->on_pushButton_clicked(); break;
        case 8: _t->on_pushButton_2_clicked(); break;
        case 9: _t->on_pushButton_3_clicked(); break;
        case 10: _t->on_pushButton_4_clicked(); break;
        case 11: _t->on_comboBox_5_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 12: _t->on_spinBox1_5_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 13: _t->on_spinBox1_6_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->on_auto_link_clicked(); break;
//        case 15: _t->on_man_link_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Widget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Widget.data,
    qt_meta_data_Widget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


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
