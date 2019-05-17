/****************************************************************************
** Meta object code from reading C++ file 'oranela.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../oranela.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'oranela.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_oranela[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x0a,
      23,    8,    8,    8, 0x0a,
      37,    8,    8,    8, 0x0a,
      49,    8,    8,    8, 0x0a,
      61,    8,    8,    8, 0x0a,
      73,    8,    8,    8, 0x0a,
      85,    8,    8,    8, 0x0a,
      94,    8,    8,    8, 0x0a,
     101,    8,    8,    8, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_oranela[] = {
    "oranela\0\0iniciarProg()\0abrirImgPos()\0"
    "abrirAccx()\0abrirAccy()\0abrirVelx()\0"
    "abrirVely()\0posRel()\0posX()\0posY()\0"
};

void oranela::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        oranela *_t = static_cast<oranela *>(_o);
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

const QMetaObjectExtraData oranela::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject oranela::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_oranela,
      qt_meta_data_oranela, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &oranela::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *oranela::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *oranela::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_oranela))
        return static_cast<void*>(const_cast< oranela*>(this));
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
    }
    return _id;
}
QT_END_MOC_NAMESPACE
