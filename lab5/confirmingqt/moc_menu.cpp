/****************************************************************************
** Meta object code from reading C++ file 'menu.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "menu.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'menu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_menu_t {
    QByteArrayData data[12];
    char stringdata0[97];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_menu_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_menu_t qt_meta_stringdata_menu = {
    {
QT_MOC_LITERAL(0, 0, 4), // "menu"
QT_MOC_LITERAL(1, 5, 10), // "next_equal"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 4), // "kind"
QT_MOC_LITERAL(4, 22, 29), // "vector<pair<string,string> >&"
QT_MOC_LITERAL(5, 52, 3), // "vec"
QT_MOC_LITERAL(6, 56, 12), // "next_inequal"
QT_MOC_LITERAL(7, 69, 8), // "finished"
QT_MOC_LITERAL(8, 78, 7), // "display"
QT_MOC_LITERAL(9, 86, 3), // "yes"
QT_MOC_LITERAL(10, 90, 2), // "no"
QT_MOC_LITERAL(11, 93, 3) // "fin"

    },
    "menu\0next_equal\0\0kind\0"
    "vector<pair<string,string> >&\0vec\0"
    "next_inequal\0finished\0display\0yes\0no\0"
    "fin"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_menu[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   49,    2, 0x06 /* Public */,
       6,    2,   54,    2, 0x06 /* Public */,
       7,    0,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    2,   60,    2, 0x0a /* Public */,
       9,    0,   65,    2, 0x0a /* Public */,
      10,    0,   66,    2, 0x0a /* Public */,
      11,    0,   67,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, 0x80000000 | 4,    3,    5,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 4,    3,    5,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, 0x80000000 | 4,    3,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void menu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<menu *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->next_equal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< vector<pair<string,string> >(*)>(_a[2]))); break;
        case 1: _t->next_inequal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< vector<pair<string,string> >(*)>(_a[2]))); break;
        case 2: _t->finished(); break;
        case 3: _t->display((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< vector<pair<string,string> >(*)>(_a[2]))); break;
        case 4: _t->yes(); break;
        case 5: _t->no(); break;
        case 6: _t->fin(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (menu::*)(int , vector<pair<string,string>> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&menu::next_equal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (menu::*)(int , vector<pair<string,string>> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&menu::next_inequal)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (menu::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&menu::finished)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject menu::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_menu.data,
    qt_meta_data_menu,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *menu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *menu::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_menu.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int menu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void menu::next_equal(int _t1, vector<pair<string,string>> & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void menu::next_inequal(int _t1, vector<pair<string,string>> & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void menu::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
