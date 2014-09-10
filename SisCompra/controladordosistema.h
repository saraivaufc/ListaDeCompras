#ifndef CONTROLADORDOSISTEMA_H
#define CONTROLADORDOSISTEMA_H

#include <QObject>
#include <QMessageBox>
#include <QDate>
#include <QDebug>

#include "gerenciadordearquivos.h"
#include "gerenciadordecompras.h"

#include "dialogeditarcompra.h"
#include "dialogeditarproduto.h"

#include "mainwindow.h"

class ControladorDoSistema : public QObject {
    Q_OBJECT

private:
    GerenciadorDeCompras * gerenciadorDeCompras;


public:
    MainWindow * interface;

    explicit ControladorDoSistema(QObject *parent = 0);
    GerenciadorDeCompras *getGerenciadorCompras();


public slots:
    void addsCompra(Compra* c);
    void salvarCompras();
    void existeCompra(Compra *c,bool *a);
    void removeCompra(Compra * c);
    void removeComprasPorData(QString data);
};

#endif // CONTROLADORDOSISTEMA_H
