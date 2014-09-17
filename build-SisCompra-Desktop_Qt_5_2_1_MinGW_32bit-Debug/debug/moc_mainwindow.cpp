/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../SisCompra/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[29];
    char stringdata[379];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_MainWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 9),
QT_MOC_LITERAL(2, 21, 0),
QT_MOC_LITERAL(3, 22, 7),
QT_MOC_LITERAL(4, 30, 1),
QT_MOC_LITERAL(5, 32, 10),
QT_MOC_LITERAL(6, 43, 8),
QT_MOC_LITERAL(7, 52, 1),
QT_MOC_LITERAL(8, 54, 5),
QT_MOC_LITERAL(9, 60, 12),
QT_MOC_LITERAL(10, 73, 12),
QT_MOC_LITERAL(11, 86, 5),
QT_MOC_LITERAL(12, 92, 6),
QT_MOC_LITERAL(13, 99, 13),
QT_MOC_LITERAL(14, 113, 12),
QT_MOC_LITERAL(15, 126, 20),
QT_MOC_LITERAL(16, 147, 4),
QT_MOC_LITERAL(17, 152, 11),
QT_MOC_LITERAL(18, 164, 8),
QT_MOC_LITERAL(19, 173, 4),
QT_MOC_LITERAL(20, 178, 16),
QT_MOC_LITERAL(21, 195, 23),
QT_MOC_LITERAL(22, 219, 22),
QT_MOC_LITERAL(23, 242, 23),
QT_MOC_LITERAL(24, 266, 24),
QT_MOC_LITERAL(25, 291, 26),
QT_MOC_LITERAL(26, 318, 5),
QT_MOC_LITERAL(27, 324, 25),
QT_MOC_LITERAL(28, 350, 27)
    },
    "MainWindow\0addCompra\0\0Compra*\0c\0"
    "addProduto\0Produto*\0p\0close\0inicializada\0"
    "existeCompra\0bool*\0existe\0existeProduto\0"
    "removeCompra\0removeComprasPorData\0"
    "data\0buscaCompra\0Compra**\0nome\0"
    "atualizarCompras\0on_actionSair_triggered\0"
    "on_actionAdd_triggered\0treeViewCompras_clicked\0"
    "treeViewProdutos_clicked\0"
    "on_treeViewCompras_clicked\0index\0"
    "on_actionRemove_triggered\0"
    "on_treeViewProdutos_clicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   99,    2, 0x06,
       5,    2,  102,    2, 0x06,
       8,    0,  107,    2, 0x06,
       9,    0,  108,    2, 0x06,
      10,    2,  109,    2, 0x06,
      13,    3,  114,    2, 0x06,
      14,    1,  121,    2, 0x06,
      15,    1,  124,    2, 0x06,
      17,    3,  127,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
      20,    0,  134,    2, 0x0a,
      21,    0,  135,    2, 0x0a,
      22,    0,  136,    2, 0x0a,
      23,    0,  137,    2, 0x0a,
      24,    0,  138,    2, 0x0a,
      25,    1,  139,    2, 0x0a,
      27,    0,  142,    2, 0x0a,
      28,    1,  143,    2, 0x08,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 6,    4,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 11,    4,   12,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 6, 0x80000000 | 11,    4,    7,   12,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::QString,   16,
    QMetaType::Void, 0x80000000 | 18, QMetaType::QString, QMetaType::QDate,    4,   19,   16,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,   26,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,   26,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->addCompra((*reinterpret_cast< Compra*(*)>(_a[1]))); break;
        case 1: _t->addProduto((*reinterpret_cast< Compra*(*)>(_a[1])),(*reinterpret_cast< Produto*(*)>(_a[2]))); break;
        case 2: _t->close(); break;
        case 3: _t->inicializada(); break;
        case 4: _t->existeCompra((*reinterpret_cast< Compra*(*)>(_a[1])),(*reinterpret_cast< bool*(*)>(_a[2]))); break;
        case 5: _t->existeProduto((*reinterpret_cast< Compra*(*)>(_a[1])),(*reinterpret_cast< Produto*(*)>(_a[2])),(*reinterpret_cast< bool*(*)>(_a[3]))); break;
        case 6: _t->removeCompra((*reinterpret_cast< Compra*(*)>(_a[1]))); break;
        case 7: _t->removeComprasPorData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->buscaCompra((*reinterpret_cast< Compra**(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QDate(*)>(_a[3]))); break;
        case 9: _t->atualizarCompras(); break;
        case 10: _t->on_actionSair_triggered(); break;
        case 11: _t->on_actionAdd_triggered(); break;
        case 12: _t->treeViewCompras_clicked(); break;
        case 13: _t->treeViewProdutos_clicked(); break;
        case 14: _t->on_treeViewCompras_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 15: _t->on_actionRemove_triggered(); break;
        case 16: _t->on_treeViewProdutos_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainWindow::*_t)(Compra * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::addCompra)) {
                *result = 0;
            }
        }
        {
            typedef void (MainWindow::*_t)(Compra * , Produto * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::addProduto)) {
                *result = 1;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::close)) {
                *result = 2;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::inicializada)) {
                *result = 3;
            }
        }
        {
            typedef void (MainWindow::*_t)(Compra * , bool * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::existeCompra)) {
                *result = 4;
            }
        }
        {
            typedef void (MainWindow::*_t)(Compra * , Produto * , bool * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::existeProduto)) {
                *result = 5;
            }
        }
        {
            typedef void (MainWindow::*_t)(Compra * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::removeCompra)) {
                *result = 6;
            }
        }
        {
            typedef void (MainWindow::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::removeComprasPorData)) {
                *result = 7;
            }
        }
        {
            typedef void (MainWindow::*_t)(Compra * * , QString , QDate );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::buscaCompra)) {
                *result = 8;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::addCompra(Compra * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::addProduto(Compra * _t1, Produto * _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainWindow::close()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void MainWindow::inicializada()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void MainWindow::existeCompra(Compra * _t1, bool * _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MainWindow::existeProduto(Compra * _t1, Produto * _t2, bool * _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void MainWindow::removeCompra(Compra * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void MainWindow::removeComprasPorData(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void MainWindow::buscaCompra(Compra * * _t1, QString _t2, QDate _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}
QT_END_MOC_NAMESPACE
