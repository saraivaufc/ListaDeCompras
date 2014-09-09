#include "controladordosistema.h"

ControladorDoSistema::ControladorDoSistema(QObject *parent) : QObject(parent) {
    interface = new MainWindow;
    interface->show();

    connect(interface, SIGNAL(addCompra(Compra*)),this,SLOT(addCompra(Compra*)));
    connect(interface, SIGNAL(close()), this, SLOT(salvarCompras()));
    connect(interface, SIGNAL(existeCompra(Compra*,bool*)), this, SLOT(existeCompra(Compra*,bool*)));
}
GerenciadorDeCompras *ControladorDoSistema::getGerenciadorCompras() {
    return &gerenciadorDeCompras;
}

void ControladorDoSistema::salvarCompras()
{
    qDebug() << "Salvando todas as compras...";
    GerenciadorDeArquivos::salvarCompra(gerenciadorDeCompras.getListaCompras());
}

void ControladorDoSistema::existeCompra(Compra *c, bool *a)
{
    if(gerenciadorDeCompras.contains(c)){
        qDebug() << "Error!, A lista já comtém esse titulo...";
        *a=true;
    }else{
        qDebug() << "sdajdajd";

        *a=false;
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
