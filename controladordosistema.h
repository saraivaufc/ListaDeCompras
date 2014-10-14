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
#include "dialogrelatorio.h"
#include "produto.h"


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
    void addCompra(Compra* c);
    void addProduto(Compra *c, Produto * p);
    void salvarCompras();
    void existeCompra(Compra *c,bool *a);

    void removeCompra(Compra * c);
    void removeComprasPorData(QString data);
    void removeProduto(Compra *c, Produto *p);
    void removeProdutoPorClasse(Compra *c,QString classe);

    void buscaCompra(Compra **c, QString nome, QDate data);
    void buscaCompraCorrente(Compra **c);
    void buscaProduto(Compra *c, Produto **p, QString nome, QString classe);

<<<<<<< HEAD
    /*
        Para gerenciador de relatorios
    */
    void gerarRelatorio(GerenciadorDeRelatorios::TipoRelatorio);
=======
    void clearCompraCorrente();
>>>>>>> c0b6b8da8c744406a519a5d119ac903150d7eaca
};

#endif // CONTROLADORDOSISTEMA_H
