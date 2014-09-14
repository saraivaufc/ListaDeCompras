#include "controladordosistema.h"

ControladorDoSistema::ControladorDoSistema(QObject *parent) : QObject(parent) {
    gerenciadorDeCompras = new GerenciadorDeCompras;

    interface = new MainWindow;
    interface->show();
    connect(interface, SIGNAL(addCompra(Compra*)),this,SLOT(addCompra(Compra*)));
    connect(interface, SIGNAL(addProduto(Compra*,Produto*)), this, SLOT(addProduto(Compra*,Produto*)));
    connect(interface, SIGNAL(close()), this, SLOT(salvarCompras()));
    connect(interface, SIGNAL(existeCompra(Compra*,bool*)), this, SLOT(existeCompra(Compra*,bool*)));
    connect(interface, SIGNAL(removeCompra(Compra*)), this, SLOT(removeCompra(Compra*)));
    connect(interface, SIGNAL(removeComprasPorData(QString)), this, SLOT(removeComprasPorData(QString)));
    connect(interface, SIGNAL(removeProduto(Compra*,Produto*)), this, SLOT(removeProduto(Compra*,Produto*)));
    connect(interface, SIGNAL(removeProdutoPorClasse(QString)), this, SLOT(removeProdutoPorClasse(QString)));
    connect(interface, SIGNAL(buscaCompra(Compra**,QString,QDate)), this, SLOT(buscaCompra(Compra**,QString,QDate)));
    connect(interface, SIGNAL(buscaProduto(Compra*,Produto**,QString,QString)), this, SLOT(buscaProduto(Compra*,Produto**,QString,QString)));
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

void ControladorDoSistema::removeCompra(Compra *c)
{
    gerenciadorDeCompras->removeCompra(c);
}

void ControladorDoSistema::removeComprasPorData(QString data)
{
    foreach (Compra * c, gerenciadorDeCompras->getListaCompras()) {
        qDebug() << c->getData().toString() << " + " << data;
        if(c->getData() == QDate::fromString(data, "dd/MM/yyyy")){
            removeCompra(c);

        }
    }
}

void ControladorDoSistema::removeProduto(Compra *c, Produto *p)
{
    qDebug()<< "Remover Produto recebido";
    Compra **a;
    Compra *b;
    a=&b;
    buscaCompra(a, c->getTitulo(), c->getData());
    if(b->removeProduto(p)){
        qDebug() << "Consegui Remover";
    }else{
        qDebug() << "Fui remover mas não emcontrei";
    }
}

void ControladorDoSistema::removeProdutoPorClasse(QString classe)
{
    foreach (Compra * c, gerenciadorDeCompras->getListaCompras()) {
        foreach (Produto * p, c->getProdutos()) {
            if(p->getClass().toUpper() == classe.toUpper()){
                    removeProduto(c,p);
            }
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

void ControladorDoSistema::buscaProduto(Compra *c, Produto **p, QString nome, QString classe)
{
    Produto * produto= new Produto(nome, classe);

    foreach (Produto * i, c->getProdutos()) {
        if( *i == *produto){
            qDebug() << "Produto achado...";
            *p=produto;
            return;
        }
    }
    qDebug() << "Não achei o produto";
}
