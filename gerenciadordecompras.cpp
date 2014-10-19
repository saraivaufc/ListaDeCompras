#include <QDebug>
#include "gerenciadordecompras.h"

GerenciadorDeCompras::GerenciadorDeCompras() {
    this->compraCorrente = new Compra(CONTACORRENTE, QDate::currentDate());
}

bool GerenciadorDeCompras::addCompra(Compra* comp) {
    foreach (Compra * p, this->listaDeCompras) {
        if(p->getTitulo() == comp->getTitulo()){
            p=comp->clone();
            GerenciadorDeArquivos::salvarCompra(comp);
            return true;
        }
    }
    listaDeCompras.append(comp);
    GerenciadorDeArquivos::salvarCompra(comp);
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
            GerenciadorDeArquivos::salvarCompra(&comp);
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
                    GerenciadorDeArquivos::salvarCompra(i);
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

void GerenciadorDeCompras::clearCompraCorrente()
{
    this->compraCorrente->clear();
}

bool GerenciadorDeCompras::contains(Compra *c) {
    foreach (Compra* c2, listaDeCompras) {
        if(*c2 == *c)
            return true;
    }

    return false;
}

double GerenciadorDeCompras::getGastosPorMes(int mes) {
    double total = 0.0;
    for(Compra c: listaDeCompras)
        if(c.getData().month() == mes)
            total += c.getValorTotal();

    return total;
}

double GerenciadorDeCompras::getGastosPorClasse(ClasseDeProduto classe) {
    double total = 0.0;
    for(Compra c: listaDeCompras)
        total += c.getValorClasse(classe);

    return total;
}

double GerenciadorDeCompras::getGastosPorClasseMes(ClasseDeProduto c, int mes)
{
    double total = 0.0;
    for(Compra compra : listaDeCompras){
        if(compra.getData().month() == mes){
            for(Produto p : compra.getProdutos()){
                if(p.getClass() == c){
                    total += p.getValorTotal();
                }
            }
        }
    }
    return total;
}

QList<int> GerenciadorDeCompras::getMesMaiorGasto()
{
    int mes = 1;
    for(int i=2 ; i<=12;i++){
        if(this->getGastosPorMes(i) >= this->getGastosPorMes(mes)){
            mes = i;
        }
    }
    QList<int> meses;
    for(int i=1 ; i<=12;i++){
        if(this->getGastosPorMes(i) == this->getGastosPorMes(mes)){
            meses.append(i);
        }
    }
    return meses;
}

QList<Compra *> GerenciadorDeCompras::getCompraMaiorGasto()
{
    double v=-1;
    for(Compra *c : this->getListaCompras()){
        if(c->getValorTotal() >= v){
            v=c->getValorTotal();
        }
    }

    QList<Compra*> compras;
    for(Compra *c : this->getListaCompras()){
        if(c->getValorTotal() == v){
            compras.append(c);
        }
    }
    return compras;
}

QList<ClasseDeProduto> GerenciadorDeCompras::getClasseMaiorGasto()
{
    int v=-1;
    if(this->getGastosPorClasse(LIMPESA) >= v ){
         v = this->getGastosPorClasse(LIMPESA);
    }
    if(this->getGastosPorClasse(COMIDA) >= v ){
         v = this->getGastosPorClasse(COMIDA);
    }
    if(this->getGastosPorClasse(UTENSILIOS) >= v ){
         v = this->getGastosPorClasse(UTENSILIOS);
    }

    QList<ClasseDeProduto> classe;

    if(this->getGastosPorClasse(LIMPESA) == v ){
        classe.append(LIMPESA);
    }
    if(this->getGastosPorClasse(COMIDA) == v ){
        classe.append(COMIDA);
    }
    if(this->getGastosPorClasse(UTENSILIOS) == v ){
        classe.append(UTENSILIOS);
    }
    return classe;

}





