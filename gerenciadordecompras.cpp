#include <QDebug>
#include "gerenciadordecompras.h"

GerenciadorDeCompras::GerenciadorDeCompras() {
    this->compraCorrente = new Compra(CONTACORRENTE, QDate::currentDate());
}

bool GerenciadorDeCompras::addCompra(Compra* comp) {
    foreach (Compra * p, this->listaDeCompras) {
        if(p->getTitulo() == comp->getTitulo()){
            p=comp->clone();
            return true;
        }
    }
    listaDeCompras.append(comp);
    return true;
}

bool GerenciadorDeCompras::removeCompra(QString tituloCompra)
{
    int index=0;
    foreach (Compra * c,this->listaDeCompras) {
        if (c->getTitulo() == tituloCompra){
            this->listaDeCompras.removeAt(index);
            return true;
        }
        index++;
    }
    return false;
}

bool GerenciadorDeCompras::removeCompra(Compra *c)
{
    int index=0;
    foreach (Compra *i, listaDeCompras) {
        if(*c == *i){
            listaDeCompras.removeAt(index);
            GerenciadorDeArquivos::removeCompra(c);
            qDebug() << "Compra removia com succeso";
            return true;
        }
        index++;
    }
    qDebug("Compra não achada!!!");
    return false;
}

bool GerenciadorDeCompras::addProdutoCompra(Compra comp, Produto prod)
{
    foreach (Compra * c, this->listaDeCompras) {
        if (c->getTitulo() == comp.getTitulo()){
            c->addProduto(&prod);
            return true;
        }
    }
    return false;
}

bool GerenciadorDeCompras::removeProdutoCompra(Compra *c, Produto *p)
{
    foreach (Compra * i, listaDeCompras) {
        if(*i == *c){
            int counter=0;
            foreach (Produto *k, i->getProdutos()) {
                if(*k == *p){
                    i->getProdutos().removeAt(counter);
                    qDebug() << "Produto Removido Com Exito!!!";
                    return true;
                }
                counter++;
            }
        }
    }
    qDebug() << "Produto Não Encontrado!!!";
    return false;
}

Compra *GerenciadorDeCompras::buscaCompra(Compra *c)
{
    foreach (Compra *i , listaDeCompras) {
        if(*i == *c){
            return i;
        }
    }
    return NULL;
}

Produto *GerenciadorDeCompras::buscaProduto(Compra *c, Produto *p)
{
    foreach (Compra * i, listaDeCompras) {
        if(*i == *c){
            foreach (Produto *k, c->getProdutos()) {
                if(*k == *p){
                    return k;
                }
            }
        }
    }
    return NULL;
}



void GerenciadorDeCompras::editarCompra(Compra * c)
{
    Compra * i = buscaCompra(c);
    DialogEditarCompra editorCompra(i);
    editorCompra.show();
    editorCompra.exec();
}

void GerenciadorDeCompras::editarProdutoCompra(Compra *c, Produto *p)
{
    Compra * i = buscaCompra(c);
    Produto * k = buscaProduto(c, p);
    DialogEditarProduto editorProduto(k);
    editorProduto.show();
    editorProduto.exec();
}

Compra * GerenciadorDeCompras::getCompraCorrente()
{
    return this->compraCorrente;
}


QList<Compra *> GerenciadorDeCompras::getListaCompras()
{
    return listaDeCompras;
}

void GerenciadorDeCompras::setCompraCorrente(Compra *c)
{
    this->compraCorrente = c;
}

bool GerenciadorDeCompras::contains(Compra *c) {
    foreach (Compra* c2, listaDeCompras) {
        if(*c2 == *c)
            return true;
    }

    return false;
}
