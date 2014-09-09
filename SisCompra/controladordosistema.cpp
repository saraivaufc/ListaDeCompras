#include "controladordosistema.h"

ControladorDoSistema::ControladorDoSistema(QObject *parent) : QObject(parent) {
    interface = new MainWindow;
    interface->show();

    connect(interface, SIGNAL(addCompra(Compra*)),this,SLOT(addCompra(Compra*)));
    connect(interface, SIGNAL(close()), this, SLOT(salvarCompras()));
    connect(interface, SIGNAL(inicializada()), this, SLOT(carregarCompras()));
}
GerenciadorDeCompras *ControladorDoSistema::getGerenciadorCompras() {
    return &gerenciadorDeCompras;
}

void ControladorDoSistema::salvarCompras()
{
    GerenciadorDeArquivos::salvarCompra(gerenciadorDeCompras.getListaCompras());
}

void ControladorDoSistema::carregarCompras()
{
    foreach (Compra * c, gerenciadorDeArquivos.getAllCompras()) {
        gerenciadorDeCompras.addCompra(c);
    }
}

void ControladorDoSistema::addCompra(Compra* c)
{
    if(gerenciadorDeCompras.addCompra(c)){
        qDebug()<<"Compra Adicionada Com Exito";
    }else{
        qDebug()<<"Falha ao adicionar a compra";
    };
}
