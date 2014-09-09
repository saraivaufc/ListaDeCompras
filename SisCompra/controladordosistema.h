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
public:
    MainWindow * interface;

    explicit ControladorDoSistema(QObject *parent = 0);
    GerenciadorDeCompras *getGerenciadorCompras();

private:
    GerenciadorDeCompras gerenciadorDeCompras;

public slots:
    void addCompra(Compra* c );

};

#endif // CONTROLADORDOSISTEMA_H
