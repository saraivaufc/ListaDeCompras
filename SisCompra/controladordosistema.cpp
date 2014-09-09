#include "controladordosistema.h"

ControladorDoSistema::ControladorDoSistema(QObject *parent) : QObject(parent) {
    interface = new MainWindow;
    interface->show();

    connect(interface, SIGNAL(addCompra(Compra*)),this,SLOT(addCompra(Compra*)));
}

GerenciadorDeCompras *ControladorDoSistema::getGerenciadorCompras() {
    return &gerenciadorDeCompras;
}

void ControladorDoSistema::addCompra(Compra* c) {
    gerenciadorDeCompras.addCompra(c);

    //GerenciadorDeArquivos::salvarCompra(&c);
}
