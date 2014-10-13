<<<<<<< HEAD
#include <qdebug.h>
#include "compra.h"
#include "gerenciadordecompras.h"
int Compra::CONTADOR_COMPRAS = 0;

Compra::Compra() {
    id = CONTADOR_COMPRAS++;
    titulo = "";
    data = QDate::currentDate();
}

Compra::Compra(Compra *c)
{
    this->id = c->getID();
    this->titulo = c->getTitulo();
    this->data = c->getData();
    this->CONTADOR_COMPRAS = c->getContadorCompra();
    foreach (Produto p, c->getProdutos()) {
        this->listaDeProdutos.append(new Produto(&p));
    }
}

Compra::Compra(QString titulo) {
    id = CONTADOR_COMPRAS++;
    this->titulo = titulo;
    data = QDate::currentDate();
}

Compra::Compra(QString titulo, QDate data) {
    id = CONTADOR_COMPRAS++;
    this->titulo = titulo;
    this->data = data;
}

bool Compra::addProduto(Produto *prod) {
    foreach (Produto* p, listaDeProdutos) {
        if(*p == *prod) {
            (*p)++;
            return true;
        }
    }

    listaDeProdutos.append(prod);
    return true;
}

bool Compra::removeProduto(Produto *p)
{
    int counter = 0;
    foreach (Produto * i, listaDeProdutos) {
        if( *i == *p){
            listaDeProdutos.removeAt(counter);
            qDebug() << "Produto Removido";
            return true;
        }
        counter++;
    }
    qDebug() << "Falha ao remover Produto";
    return false;
}


Produto *Compra::getProduto(int id) {
    return listaDeProdutos.at(id);
}

QList<Produto *> Compra::getProdutos() {
    return listaDeProdutos;
}

int Compra::getID()
{
    return this->id;
}

QString Compra::getTitulo() {
    return titulo;
}

QDate Compra::getData() {
    return data;
}

float Compra::getValorTotal()
{
    float valor=0;
    foreach (Produto *p, listaDeProdutos) {
        valor+=p->getQuantidade()*p->getValorUnit();
    }
    return valor;
}

int Compra::getContadorCompra()
{
    return this->CONTADOR_COMPRAS;
}

void Compra::setTitulo(QString titulo) {
    this->titulo = titulo;
}

void Compra::setData(QDate data) {
    this->data = data;
}

bool Compra::operator == (Compra c) {
    return (data == c.getData() && titulo == c.getTitulo());
}

Compra * Compra::clone()
{
    return new Compra(this);
}

QString Compra::toString() {
    QString s = "";
    foreach (Produto* p, listaDeProdutos) {
        s += "\t" + p->toString() + "\n";
    }

    return "Compra [" + titulo + ": " +\
            QString::number(data.day()) + "/" +\
            QString::number(data.month()) + "/" +\
            QString::number(data.year()) + "] = {\n" + s + "}";
}
=======
#include <qdebug.h>
#include "compra.h"
#include "gerenciadordecompras.h"
int Compra::CONTADOR_COMPRAS = 0;

Compra::Compra() {
    id = CONTADOR_COMPRAS++;
    titulo = "";
    data = QDate::currentDate();
}

Compra::Compra(Compra *c)
{
    this->id = c->getID();
    this->titulo = c->getTitulo();
    this->data = c->getData();
    this->CONTADOR_COMPRAS = c->getContadorCompra();
    foreach (Produto p, c->getProdutos()) {
        this->listaDeProdutos.append(new Produto(&p));
    }
}

Compra::Compra(QString titulo) {
    id = CONTADOR_COMPRAS++;
    this->titulo = titulo;
    data = QDate::currentDate();
}

Compra::Compra(QString titulo, QDate data) {
    id = CONTADOR_COMPRAS++;
    this->titulo = titulo;
    this->data = data;
}

bool Compra::addProduto(Produto *prod) {
    foreach (Produto* p, listaDeProdutos) {
        if(*p == *prod) {
            (*p)++;
            return true;
        }
    }

    listaDeProdutos.append(prod);
    return true;
}

bool Compra::removeProduto(Produto *p)
{
    int counter = 0;
    foreach (Produto * i, listaDeProdutos) {
        if( *i == *p){
            listaDeProdutos.removeAt(counter);
            qDebug() << "Produto Removido";
            return true;
        }
        counter++;
    }
    qDebug() << "Falha ao remover Produto";
    return false;
}


Produto *Compra::getProduto(int id) {
    return listaDeProdutos.at(id);
}

QList<Produto *> Compra::getProdutos() {
    return listaDeProdutos;
}

int Compra::getID()
{
    return this->id;
}

QString Compra::getTitulo() {
    return titulo;
}

QDate Compra::getData() {
    return data;
}

float Compra::getValorTotal()
{
    float valor=0;
    foreach (Produto *p, listaDeProdutos) {
        valor+=p->getQuantidade()*p->getValorUnit();
    }
    return valor;
}

int Compra::getContadorCompra()
{
    return this->CONTADOR_COMPRAS;
}

void Compra::setTitulo(QString titulo) {
    this->titulo = titulo;
}

void Compra::setData(QDate data) {
    this->data = data;
}

bool Compra::operator == (Compra c) {
    return (data == c.getData() && titulo == c.getTitulo());
}

Compra * Compra::clone()
{
    return new Compra(this);
}

QString Compra::toString() {
    QString s = "";
    foreach (Produto* p, listaDeProdutos) {
        s += "\t" + p->toString() + "\n";
    }

    return "Compra [" + titulo + ": " +\
            QString::number(data.day()) + "/" +\
            QString::number(data.month()) + "/" +\
            QString::number(data.year()) + "] = {\n" + s + "}";
}
>>>>>>> 39f381eefdb8a8c2d1c947ccd6862df2067ef649
