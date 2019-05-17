/****************************************************************************
** Meta object code from reading C++ file 'oranela.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../oraface/oranela.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'oranela.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_oranela_t {
    QByteArrayData data[11];
    char stringdata0[90];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_oranela_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_oranela_t qt_meta_stringdata_oranela = {
    {
QT_MOC_LITERAL(0, 0, 7), // "oranela"
QT_MOC_LITERAL(1, 8, 11), // "iniciarProg"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 11), // "abrirImgPos"
QT_MOC_LITERAL(4, 33, 9), // "abrirAccx"
QT_MOC_LITERAL(5, 43, 9), // "abrirAccy"
QT_MOC_LITERAL(6, 53, 9), // "abrirVelx"
QT_MOC_LITERAL(7, 63, 9), // "abrirVely"
QT_MOC_LITERAL(8, 73, 6), // "posRel"
QT_MOC_LITERAL(9, 80, 4), // "posX"
QT_MOC_LITERAL(10, 85, 4) // "posY"

    },
    "oranela\0iniciarProg\0\0abrirImgPos\0"
    "abrirAccx\0abrirAccy\0abrirVelx\0abrirVely\0"
    "posRel\0posX\0posY"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_oranela[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x0a /* Public */,
       3,    0,   60,    2, 0x0a /* Public */,
       4,    0,   61,    2, 0x0a /* Public */,
       5,    0,   62,    2, 0x0a /* Public */,
       6,    0,   63,    2, 0x0a /* Public */,
       7,    0,   64,    2, 0x0a /* Public */,
       8,    0,   65,    2, 0x0a /* Public */,
       9,    0,   66,    2, 0x0a /* Public */,
      10,    0,   67,    2, 0x0a /* Public */,

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

       0        // eod
};

void oranela::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<oranela *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->iniciarProg(); break;
        case 1: _t->abrirImgPos(); break;
        case 2: _t->abrirAccx(); break;
        case 3: _t->abrirAccy(); break;
        case 4: _t->abrirVelx(); break;
        case 5: _t->abrirVely(); break;
        case 6: _t->posRel(); break;
        case 7: _t->posX(); break;
        case 8: _t->posY(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject oranela::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_oranela.data,
    qt_meta_data_oranela,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *oranela::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *oranela::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_oranela.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int oranela::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
