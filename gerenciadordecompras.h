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
    QList<Compra *> getListaCompras();

    bool contains(Compra* c);
};

#endif // GERENCIADORDECOMPRAS_H