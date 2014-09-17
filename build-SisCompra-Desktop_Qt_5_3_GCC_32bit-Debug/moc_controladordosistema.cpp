/****************************************************************************
** Meta object code from reading C++ file 'controladordosistema.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../SisCompra/controladordosistema.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'controladordosistema.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ControladorDoSistema_t {
    QByteArrayData data[20];
    char stringdata[185];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ControladorDoSistema_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ControladorDoSistema_t qt_meta_stringdata_ControladorDoSistema = {
    {
QT_MOC_LITERAL(0, 0, 20),
QT_MOC_LITERAL(1, 21, 9),
QT_MOC_LITERAL(2, 31, 0),
QT_MOC_LITERAL(3, 32, 7),
QT_MOC_LITERAL(4, 40, 1),
QT_MOC_LITERAL(5, 42, 10),
QT_MOC_LITERAL(6, 53, 8),
QT_MOC_LITERAL(7, 62, 1),
QT_MOC_LITERAL(8, 64, 13),
QT_MOC_LITERAL(9, 78, 12),
QT_MOC_LITERAL(10, 91, 5),
QT_MOC_LITERAL(11, 97, 1),
QT_MOC_LITERAL(12, 99, 13),
QT_MOC_LITERAL(13, 113, 6),
QT_MOC_LITERAL(14, 120, 12),
QT_MOC_LITERAL(15, 133, 20),
QT_MOC_LITERAL(16, 154, 4),
QT_MOC_LITERAL(17, 159, 11),
QT_MOC_LITERAL(18, 171, 8),
QT_MOC_LITERAL(19, 180, 4)
    },
    "ControladorDoSistema\0addCompra\0\0Compra*\0"
    "c\0addProduto\0Produto*\0p\0salvarCompras\0"
    "existeCompra\0bool*\0a\0existeProduto\0"
    "existe\0removeCompra\0removeComprasPorData\0"
    "data\0buscaCompra\0Compra**\0nome"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ControladorDoSistema[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x0a /* Public */,
       5,    2,   57,    2, 0x0a /* Public */,
       8,    0,   62,    2, 0x0a /* Public */,
       9,    2,   63,    2, 0x0a /* Public */,
      12,    3,   68,    2, 0x0a /* Public */,
      14,    1,   75,    2, 0x0a /* Public */,
      15,    1,   78,    2, 0x0a /* Public */,
      17,    3,   81,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 6,    4,    7,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 10,    4,   11,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 6, 0x80000000 | 10,    4,    7,   13,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::QString,   16,
    QMetaType::Void, 0x80000000 | 18, QMetaType::QString, QMetaType::QDate,    4,   19,   16,

       0        // eod
};

void ControladorDoSistema::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ControladorDoSistema *_t = static_cast<ControladorDoSistema *>(_o);
        switch (_id) {
        case 0: _t->addCompra((*reinterpret_cast< Compra*(*)>(_a[1]))); break;
        case 1: _t->addProduto((*reinterpret_cast< Compra*(*)>(_a[1])),(*reinterpret_cast< Produto*(*)>(_a[2]))); break;
        case 2: _t->salvarCompras(); break;
        case 3: _t->existeCompra((*reinterpret_cast< Compra*(*)>(_a[1])),(*reinterpret_cast< bool*(*)>(_a[2]))); break;
        case 4: _t->existeProduto((*reinterpret_cast< Compra*(*)>(_a[1])),(*reinterpret_cast< Produto*(*)>(_a[2])),(*reinterpret_cast< bool*(*)>(_a[3]))); break;
        case 5: _t->removeCompra((*reinterpret_cast< Compra*(*)>(_a[1]))); break;
        case 6: _t->removeComprasPorData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->buscaCompra((*reinterpret_cast< Compra**(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QDate(*)>(_a[3]))); break;
        default: ;
        }
    }
}

const QMetaObject ControladorDoSistema::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ControladorDoSistema.data,
      qt_meta_data_ControladorDoSistema,  qt_static_metacall, 0, 0}
};


const QMetaObject *ControladorDoSistema::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ControladorDoSistema::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ControladorDoSistema.stringdata))
        return static_cast<void*>(const_cast< ControladorDoSistema*>(this));
    return QObject::qt_metacast(_clname);
}

int ControladorDoSistema::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
