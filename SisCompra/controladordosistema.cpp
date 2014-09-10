#include "controladordosistema.h"

ControladorDoSistema::ControladorDoSistema(QObject *parent) : QObject(parent) {
    gerenciadorDeCompras = new GerenciadorDeCompras;

    interface = new MainWindow;
    interface->show();
    connect(interface, SIGNAL(addCompra(Compra*)),this,SLOT(addsCompra(Compra*)));
    connect(interface, SIGNAL(close()), this, SLOT(salvarCompras()));
    connect(interface, SIGNAL(existeCompra(Compra*,bool*)), this, SLOT(existeCompra(Compra*,bool*)));
    connect(interface, SIGNAL(removeCompra(Compra*)), this, SLOT(removeCompra(Compra*)));
    connect(interface, SIGNAL(removeComprasPorData(QString)), this, SLOT(removeComprasPorData(QString)));

    interface->carregarCompras();
}
GerenciadorDeCompras *ControladorDoSistema::getGerenciadorCompras() {
    return gerenciadorDeCompras;
}



void ControladorDoSistema::salvarCompras()
{
    qDebug() << "Salvando todas as compras...";
    GerenciadorDeArquivos::salvarCompra(gerenciadorDeCompras->getListaCompras());
}

void ControladorDoSistema::existeCompra(Compra *c, bool *a)
{
    qDebug()<< "Signal Existe recebido...";
    if(gerenciadorDeCompras->contains(c)){
        qDebug() << "Error!, A lista já comtém esse titulo...";
        *a=true;
    }else{
        qDebug() << "Pode ser adicionada...";
        *a=false;
    }

}

void ControladorDoSistema::removeCompra(Compra *c)
{
    gerenciadorDeCompras->removeCompra(c);
}

void ControladorDoSistema::removeComprasPorData(QString data)
{
    foreach (Compra * c, gerenciadorDeCompras->getListaCompras()) {
        if(c->getData().toString("dd/MM/yyyy") == data){
            removeCompra(c);
        }
    }
}


void ControladorDoSistema::addsCompra(Compra *c)
{
    qDebug() << "Sinal Recebido...";
    if(gerenciadorDeCompras->addCompra(c)){
        qDebug() << "Quantidade de Cartas:" << gerenciadorDeCompras->getListaCompras().length();
    }else{
        qDebug()<<"Falha ao adicionar a compra";
    };
}
