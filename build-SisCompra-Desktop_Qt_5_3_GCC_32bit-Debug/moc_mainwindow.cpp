/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../SisCompra/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[21];
    char stringdata[288];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 9),
QT_MOC_LITERAL(2, 21, 0),
QT_MOC_LITERAL(3, 22, 7),
QT_MOC_LITERAL(4, 30, 1),
QT_MOC_LITERAL(5, 32, 5),
QT_MOC_LITERAL(6, 38, 12),
QT_MOC_LITERAL(7, 51, 12),
QT_MOC_LITERAL(8, 64, 5),
QT_MOC_LITERAL(9, 70, 6),
QT_MOC_LITERAL(10, 77, 12),
QT_MOC_LITERAL(11, 90, 20),
QT_MOC_LITERAL(12, 111, 4),
QT_MOC_LITERAL(13, 116, 16),
QT_MOC_LITERAL(14, 133, 23),
QT_MOC_LITERAL(15, 157, 22),
QT_MOC_LITERAL(16, 180, 23),
QT_MOC_LITERAL(17, 204, 24),
QT_MOC_LITERAL(18, 229, 26),
QT_MOC_LITERAL(19, 256, 5),
QT_MOC_LITERAL(20, 262, 25)
    },
    "MainWindow\0addCompra\0\0Compra*\0c\0close\0"
    "inicializada\0existeCompra\0bool*\0existe\0"
    "removeCompra\0removeComprasPorData\0"
    "data\0atualizarCompras\0on_actionSair_triggered\0"
    "on_actionAdd_triggered\0treeViewCompras_clicked\0"
    "treeViewProdutos_clicked\0"
    "on_treeViewCompras_clicked\0index\0"
    "on_actionRemove_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06 /* Public */,
       5,    0,   82,    2, 0x06 /* Public */,
       6,    0,   83,    2, 0x06 /* Public */,
       7,    2,   84,    2, 0x06 /* Public */,
      10,    1,   89,    2, 0x06 /* Public */,
      11,    1,   92,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    0,   95,    2, 0x0a /* Public */,
      14,    0,   96,    2, 0x08 /* Private */,
      15,    0,   97,    2, 0x08 /* Private */,
      16,    0,   98,    2, 0x08 /* Private */,
      17,    0,   99,    2, 0x08 /* Private */,
      18,    1,  100,    2, 0x08 /* Private */,
      20,    0,  103,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 8,    4,    9,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::QString,   12,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,   19,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->addCompra((*reinterpret_cast< Compra*(*)>(_a[1]))); break;
        case 1: _t->close(); break;
        case 2: _t->inicializada(); break;
        case 3: _t->existeCompra((*reinterpret_cast< Compra*(*)>(_a[1])),(*reinterpret_cast< bool*(*)>(_a[2]))); break;
        case 4: _t->removeCompra((*reinterpret_cast< Compra*(*)>(_a[1]))); break;
        case 5: _t->removeComprasPorData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->atualizarCompras(); break;
        case 7: _t->on_actionSair_triggered(); break;
        case 8: _t->on_actionAdd_triggered(); break;
        case 9: _t->treeViewCompras_clicked(); break;
        case 10: _t->treeViewProdutos_clicked(); break;
        case 11: _t->on_treeViewCompras_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 12: _t->on_actionRemove_triggered(); break;
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
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::close)) {
                *result = 1;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::inicializada)) {
                *result = 2;
            }
        }
        {
            typedef void (MainWindow::*_t)(Compra * , bool * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::existeCompra)) {
                *result = 3;
            }
        }
        {
            typedef void (MainWindow::*_t)(Compra * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::removeCompra)) {
                *result = 4;
            }
        }
        {
            typedef void (MainWindow::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::removeComprasPorData)) {
                *result = 5;
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
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
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
void MainWindow::close()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void MainWindow::inicializada()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void MainWindow::existeCompra(Compra * _t1, bool * _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MainWindow::removeCompra(Compra * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MainWindow::removeComprasPorData(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_END_MOC_NAMESPACE
