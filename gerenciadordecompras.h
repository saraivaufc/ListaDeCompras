<<<<<<< HEAD
#ifndef GERENCIADORDECOMPRAS_H
#define GERENCIADORDECOMPRAS_H

#include <QList>
#include "compra.h"
#include "dialogeditarcompra.h"
#include "dialogeditarproduto.h"
#include <QMessageBox>
#include "gerenciadordearquivos.h"

/*
 * Classe responsável por gerenciar a lista de compras
 *
 */

class GerenciadorDeCompras {
private:
    QList<Compra*> listaDeCompras;
    Compra *compraCorrente;

public:
    GerenciadorDeCompras();

    bool addCompra(Compra* comp);
    bool removeCompra(QString tituloCompra);
    bool removeCompra(Compra * c);

    bool addProdutoCompra(Compra comp, Produto prod);
    bool removeProdutoCompra(Compra *c, Produto * p);

    Compra *buscaCompra(Compra *c);
    Produto *buscaProduto(Compra * c, Produto *p);

    void editarCompra(Compra * c);
    void editarProdutoCompra(Compra * c, Produto * p);

    Compra * getCompraCorrente();
    QList<Compra *> getListaCompras();

    void setCompraCorrente(Compra *c);

    bool contains(Compra* c);
};

#endif // GERENCIADORDECOMPRAS_H
=======
#ifndef GERENCIADORDECOMPRAS_H
#define GERENCIADORDECOMPRAS_H

#include <QList>
#include "compra.h"
#include "dialogeditarcompra.h"
#include "dialogeditarproduto.h"
#include <QMessageBox>
#include "gerenciadordearquivos.h"

/*
 * Classe responsável por gerenciar a lista de compras
 *
 */

class GerenciadorDeCompras {
private:
    QList<Compra*> listaDeCompras;
    Compra *compraCorrente;

public:
    GerenciadorDeCompras();

    bool addCompra(Compra* comp);
    bool removeCompra(QString tituloCompra);
    bool removeCompra(Compra * c);

    bool addProdutoCompra(Compra comp, Produto prod);
    bool removeProdutoCompra(Compra *c, Produto * p);

    Compra *buscaCompra(Compra *c);
    Produto *buscaProduto(Compra * c, Produto *p);

    void editarCompra(Compra * c);
    void editarProdutoCompra(Compra * c, Produto * p);

    Compra * getCompraCorrente();
    QList<Compra *> getListaCompras();

    void setCompraCorrente(Compra *c);

    bool contains(Compra* c);
};

#endif // GERENCIADORDECOMPRAS_H
>>>>>>> 39f381eefdb8a8c2d1c947ccd6862df2067ef649
