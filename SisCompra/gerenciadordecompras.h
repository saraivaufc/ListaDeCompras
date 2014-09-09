#ifndef GERENCIADORDECOMPRAS_H
#define GERENCIADORDECOMPRAS_H

#include <QList>
#include "compra.h"
#include "dialogeditarcompra.h"
#include "dialogeditarproduto.h"
#include <QMessageBox>

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

    bool addProdutoCompra(Compra comp, Produto prod);
    bool removeProdutoCompra(int idCompra, int idProduto);

    void editarCompra(int idCompra);
    void editarProdutoCompra(int idCompra, int idProduto);
    QList<Compra *> getListaCompras();

    bool contains(Compra* c);
};

#endif // GERENCIADORDECOMPRAS_H
