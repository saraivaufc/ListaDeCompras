#include "controladordosistema.h"
#include <QTimer>

ControladorDoSistema::ControladorDoSistema(QObject *parent) : QObject(parent) {
    gerenciadorDeCompras = new GerenciadorDeCompras;

    interface = new MainWindow;
    interface->show();

    QTimer* timer = new QTimer(interface);
    connect(timer, SIGNAL(timeout()), interface, SLOT(updateSize()));
    timer->start(10);

    connect(interface, SIGNAL(addCompra(Compra*)),this,SLOT(addCompra(Compra*)));
    connect(interface, SIGNAL(addProduto(Compra*,Produto*)), this, SLOT(addProduto(Compra*,Produto*)));
    connect(interface, SIGNAL(existeCompra(Compra*,bool*)), this, SLOT(existeCompra(Compra*,bool*)));
    connect(interface, SIGNAL(removeCompra(Compra*)), this, SLOT(removeCompra(Compra*)));
    connect(interface, SIGNAL(removeComprasPorData(QString)), this, SLOT(removeComprasPorData(QString)));
    connect(interface, SIGNAL(removeProduto(Compra*,Produto*)), this, SLOT(removeProduto(Compra*,Produto*)));
    connect(interface, SIGNAL(removeProdutoPorClasse(Compra*,ClasseDeProduto)), this, SLOT(removeProdutoPorClasse(Compra *,ClasseDeProduto)));
    connect(interface, SIGNAL(buscaCompra(Compra**,QString,QDate)), this, SLOT(buscaCompra(Compra**,QString,QDate)));
    connect(interface, SIGNAL(buscaCompraCorrente(Compra**)), this, SLOT(buscaCompraCorrente(Compra**)));
    connect(interface, SIGNAL(buscaProduto(Compra*,Produto**,QString,ClasseDeProduto)), this, SLOT(buscaProduto(Compra*,Produto**,QString,ClasseDeProduto)));
    connect(interface, SIGNAL(clearCompraCorrente()), this, SLOT(clearCompraCorrente()));

    /*
     * para gerenciador de relatorios
    */
    connect(interface, SIGNAL(gerarRelatorio(GerenciadorDeRelatorios::TipoRelatorio)),
            this, SLOT(gerarRelatorio(GerenciadorDeRelatorios::TipoRelatorio)));

    interface->adicionarCompraCorrente(gerenciadorDeCompras->getCompraCorrente());
    interface->carregarCompras();
}
GerenciadorDeCompras *ControladorDoSistema::getGerenciadorCompras() {
    return gerenciadorDeCompras;
}

void ControladorDoSistema::addCompra(Compra *c)
{
    if(c->getTitulo() == COMPRACORRENTE){
        gerenciadorDeCompras->setCompraCorrente(c);
        qDebug() << "Compra Adicionada com Sucesso.";
    }else if(gerenciadorDeCompras->addCompra(c)){
        qDebug() << "Compra Adicionada com Sucesso.";
    }else{
        qDebug()<<"Falha ao adicionar a compra.";
    }
}

void ControladorDoSistema::addProduto(Compra *c, Produto *p)
{
    if(c->getTitulo() == COMPRACORRENTE){
        gerenciadorDeCompras->getCompraCorrente()->addProduto(p);
        qDebug() << "Produto Adicionado com Exito..";
        return;
    }else{
        foreach (Compra * i, gerenciadorDeCompras->getListaCompras()) {
            if(*i == *c){
                i->addProduto(p);
                GerenciadorDeArquivos::salvarCompra(i);
                qDebug() << "Produto Adicionado com Exito..";
                return;
            }
        }
    }
    qDebug() << "Falha ao Adicionar o Produto";

}

void ControladorDoSistema::existeCompra(Compra *c, bool *a)
{
    if(gerenciadorDeCompras->contains(c)){
        qDebug() << "Error!, A lista já contém esse titulo.";
        *a=true;
    }else{
        *a=false;
    }

}

void ControladorDoSistema::removeCompra(Compra *c)
{
    if(!(c->getTitulo() == COMPRACORRENTE)){
        gerenciadorDeCompras->removeCompra(c);
    }
}

void ControladorDoSistema::removeComprasPorData(QString data)
{
    if(this->gerenciadorDeCompras->getCompraCorrente()->getData() == QDate::fromString(data,  "dd/MM/yyyy")){
        this->gerenciadorDeCompras->getCompraCorrente()->clear();
    }
    foreach (Compra * c, gerenciadorDeCompras->getListaCompras()) {
        if(c->getData() == QDate::fromString(data, "dd/MM/yyyy")){
            removeCompra(c);

        }
    }
}

void ControladorDoSistema::removeProduto(Compra *c, Produto *p)
{
    Compra **a;
    Compra *b;
    a=&b;
    if(c->getTitulo() == COMPRACORRENTE){
        buscaCompraCorrente(a);
    }else{
        buscaCompra(a, c->getTitulo(), c->getData());
    }
    if(b->removeProduto(p)){
        qDebug() << "Consegui Remover da Compra: " + c->toString() + " O Produto: " + p->toString();
    }else{
        qDebug() << "Fui remover mas não emcontrei";
    }
}

void ControladorDoSistema::removeProdutoPorClasse(Compra *c,ClasseDeProduto classe)
{
     foreach (Produto * p, c->getProdutos()) {
         if(p->getClass() == classe){
             removeProduto(c,p);
         }
     }
}

void ControladorDoSistema::buscaCompra(Compra **c, QString nome, QDate data)
{
    Compra k(nome, data);
    foreach (Compra * i , gerenciadorDeCompras->getListaCompras()) {
        if(*i == k){
            *c=i;
            return;
        }
    }
    c=NULL;

}

void ControladorDoSistema::buscaCompraCorrente(Compra **c) {
    *c=this->getGerenciadorCompras()->getCompraCorrente();
}

void ControladorDoSistema::buscaProduto(Compra *c, Produto **p, QString nome, ClasseDeProduto classe) {
    Produto * produto= new Produto(nome, classe);

    foreach (Produto * i, c->getProdutos()) {
        if( *i == *produto){
            *p=i;
            return;
        }
    }
}

void ControladorDoSistema::gerarRelatorio(GerenciadorDeRelatorios::TipoRelatorio tipo) {
    GerenciadorDeRelatorios::gerarRelatorio(tipo, gerenciadorDeCompras, interface);
}

void ControladorDoSistema::clearCompraCorrente() {
    gerenciadorDeCompras->clearCompraCorrente();
}
