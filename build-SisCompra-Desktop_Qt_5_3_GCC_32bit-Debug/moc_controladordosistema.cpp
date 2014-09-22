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
    QByteArrayData data[23];
    char stringdata[231];
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
QT_MOC_LITERAL(12, 99, 12),
QT_MOC_LITERAL(13, 112, 20),
QT_MOC_LITERAL(14, 133, 4),
QT_MOC_LITERAL(15, 138, 13),
QT_MOC_LITERAL(16, 152, 22),
QT_MOC_LITERAL(17, 175, 6),
QT_MOC_LITERAL(18, 182, 11),
QT_MOC_LITERAL(19, 194, 8),
QT_MOC_LITERAL(20, 203, 4),
QT_MOC_LITERAL(21, 208, 12),
QT_MOC_LITERAL(22, 221, 9)
    },
    "ControladorDoSistema\0addCompra\0\0Compra*\0"
    "c\0addProduto\0Produto*\0p\0salvarCompras\0"
    "existeCompra\0bool*\0a\0removeCompra\0"
    "removeComprasPorData\0data\0removeProduto\0"
    "removeProdutoPorClasse\0classe\0buscaCompra\0"
    "Compra**\0nome\0buscaProduto\0Produto**"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ControladorDoSistema[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x0a /* Public */,
       5,    2,   67,    2, 0x0a /* Public */,
       8,    0,   72,    2, 0x0a /* Public */,
       9,    2,   73,    2, 0x0a /* Public */,
      12,    1,   78,    2, 0x0a /* Public */,
      13,    1,   81,    2, 0x0a /* Public */,
      15,    2,   84,    2, 0x0a /* Public */,
      16,    1,   89,    2, 0x0a /* Public */,
      18,    3,   92,    2, 0x0a /* Public */,
      21,    4,   99,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 6,    4,    7,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 10,    4,   11,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 6,    4,    7,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void, 0x80000000 | 19, QMetaType::QString, QMetaType::QDate,    4,   20,   14,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 22, QMetaType::QString, QMetaType::QString,    4,    7,   20,   17,

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
        case 4: _t->removeCompra((*reinterpret_cast< Compra*(*)>(_a[1]))); break;
        case 5: _t->removeComprasPorData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->removeProduto((*reinterpret_cast< Compra*(*)>(_a[1])),(*reinterpret_cast< Produto*(*)>(_a[2]))); break;
        case 7: _t->removeProdutoPorClasse((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->buscaCompra((*reinterpret_cast< Compra**(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QDate(*)>(_a[3]))); break;
        case 9: _t->buscaProduto((*reinterpret_cast< Compra*(*)>(_a[1])),(*reinterpret_cast< Produto**(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
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
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
