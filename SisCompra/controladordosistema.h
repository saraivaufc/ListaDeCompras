#ifndef CONTROLADORDOSISTEMA_H
#define CONTROLADORDOSISTEMA_H

#include <QObject>
#include <QMessageBox>
#include <QDate>
#include <QDebug>

#include "gerenciadordearquivos.h"
#include "gerenciadordecompras.h"

#include "dialogadicionarcompra.h"
#include "dialogeditarcompra.h"
#include "dialogeditarproduto.h"

#include "mainwindow.h"

class ControladorDoSistema : public QObject
{
    Q_OBJECT
public:
    MainWindow * interface;

    explicit ControladorDoSistema(QObject *parent = 0);
    DialogAdicionarCompra dialogAddCompra;


private:
    GerenciadorDeCompras gerenciadorDeCompras;

public:
    GerenciadorDeCompras *getGerenciadorCompras();


public slots:
    void addCompra(void);

};

#endif // CONTROLADORDOSISTEMA_H
