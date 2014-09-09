#include "gerenciadordecompras.h"

GerenciadorDeCompras::GerenciadorDeCompras() {
}

bool GerenciadorDeCompras::addCompra(Compra* comp) {
    if(!listaDeCompras.contains(comp)) {
        listaDeCompras.append(comp);
        return true;
    } else {
        return false;
    }
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
