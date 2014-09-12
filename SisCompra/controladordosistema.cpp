#include "controladordosistema.h"

ControladorDoSistema::ControladorDoSistema(QObject *parent) : QObject(parent) {
    gerenciadorDeCompras = new GerenciadorDeCompras;

    interface = new MainWindow;
    interface->show();
    connect(interface, SIGNAL(addCompra(Compra*)),this,SLOT(addCompra(Compra*)));
    connect(interface, SIGNAL(addProduto(Compra*,Produto*)), this, SLOT(addProduto(Compra*,Produto*)));
    connect(interface, SIGNAL(close()), this, SLOT(salvarCompras()));
    connect(interface, SIGNAL(existeCompra(Compra*,bool*)), this, SLOT(existeCompra(Compra*,bool*)));
    connect(interface, SIGNAL(existeProduto(Compra*,Produto*,bool*)),this, SLOT(existeProduto(Compra*,Produto*,bool*)));
    connect(interface, SIGNAL(removeCompra(Compra*)), this, SLOT(removeCompra(Compra*)));
    connect(interface, SIGNAL(removeComprasPorData(QString)), this, SLOT(removeComprasPorData(QString)));
    connect(interface, SIGNAL(buscaCompra(Compra**,QString,QDate)), this, SLOT(buscaCompra(Compra**,QString,QDate)));

    interface->carregarCompras();
}
GerenciadorDeCompras *ControladorDoSistema::getGerenciadorCompras() {
    return gerenciadorDeCompras;
}

void ControladorDoSistema::addCompra(Compra *c)
{
    qDebug() << "AddCompra::Sinal Recebido...";
    if(gerenciadorDeCompras->addCompra(c)){
        qDebug() << "Quantidade de Cartas:" << gerenciadorDeCompras->getListaCompras().length();
    }else{
        qDebug()<<"Falha ao adicionar a compra";
    }
}

void ControladorDoSistema::addProduto(Compra *c, Produto *p)
{
    qDebug() << "AddProduto::Sinal Recebido...";
    foreach (Compra * i, gerenciadorDeCompras->getListaCompras()) {
        if(*i == *c){
            i->addProduto(p);
            qDebug() << "Produto Adicionado com Exito..";
            return;
        }
    }
    qDebug() << "Falha ao Adicionar o Produto";

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

void ControladorDoSistema::existeProduto(Compra * c, Produto *p, bool *existe)
{
    foreach (Compra *i, gerenciadorDeCompras->getListaCompras()) {
        if(*i == *c){
            foreach (Produto * k, i->getProdutos()) {
                if(*k == *p){
                    *existe=true;
                    qDebug() << "Produto já existe";
                    return;
                }
            }
        }
    }
    *existe=false;
    qDebug() << "Produto não existe...";
    return;
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

void ControladorDoSistema::buscaCompra(Compra **c, QString nome, QDate data)
{

    qDebug() << "Sinal Busca Compra Recebido";
    Compra k(nome, data);
    foreach (Compra * i , gerenciadorDeCompras->getListaCompras()) {
        if(*i == k){
            *c=i;
            return;
        }
    }
    c=NULL;
    qDebug() << "Compra não encontrada";

}
