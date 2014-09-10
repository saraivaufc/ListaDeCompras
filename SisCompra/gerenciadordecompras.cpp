#include <QDebug>
#include "gerenciadordecompras.h"

GerenciadorDeCompras::GerenciadorDeCompras() {
}

bool GerenciadorDeCompras::addCompra(Compra* comp) {
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
    qDebug() << "\n\n";
    foreach (Compra *i, listaDeCompras) {
        qDebug() << "Procurando Compra...";
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

bool GerenciadorDeCompras::removeProdutoCompra(int idCompra, int idProduto)
{
    foreach (Compra * c, this->listaDeCompras) {
        if(c->getID() == idCompra){
            int index = 0;
            foreach (Produto * p, c->getProdutos()) {
                if(p->getId() == idProduto){
                    c->getProdutos().removeAt(index);
                    return true;
                }
                index++;
            }
        }
    }
    return false;
}

void GerenciadorDeCompras::editarCompra(int idCompra)
{
    foreach (Compra * c, this->listaDeCompras) {
        if(c->getID() == idCompra){
            DialogEditarCompra editorCompra(c);
        }
    }
}

void GerenciadorDeCompras::editarProdutoCompra(int idCompra, int idProduto)
{
    foreach (Compra * c, this->listaDeCompras) {
        if(c->getID() == idCompra){
            foreach (Produto * p, c->getProdutos()) {
                if(p->getId() == idProduto){
                    DialogEditarProduto editorProduto(p);
                }
            }
        }
    }
}

QList<Compra *> GerenciadorDeCompras::getListaCompras()
{
    return listaDeCompras;
}

bool GerenciadorDeCompras::contains(Compra *c) {
    foreach (Compra* c2, listaDeCompras) {
        if(*c2 == *c)
            return true;
    }

    return false;
}
