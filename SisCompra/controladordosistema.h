#ifndef COMTROLADORDOSISTEMA_H
#define COMTROLADORDOSISTEMA_H

#include "gerenciadordearquivos.h"
#include "gerenciadordecompras.h"
#include "mainwindow.h"
#include "dialogeditarproduto.h"
#include "dialogeditarcompra.h"

/*
 * Esta classe contem todos os métodos que serão acessados
 * apartir da interface, bem como seus principais o bjetos
 */

class ControladorDoSistema {
private:
    MainWindow* window;
    GerenciadorDeCompras gerenciadorDeCompras;

public:
    ControladorDoSistema();

    bool addCompra(Compra comp);
    bool removeCompra(int idCompra);

    bool addProdutoCompra(Compra comp, Produto prod);
    bool removeProdutoCompra(int idCompra, int idProduto);

    void editarCompra(int idCompra);
    void editarProdutoCompra(int idCompra, int idProduto);

    GerenciadorDeCompras getGerenciadorCompras();
};

#endif // COMTROLADORDOSISTEMA_H
