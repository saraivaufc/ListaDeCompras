#include <qdebug.h>
#include "compra.h"

int Compra::CONTADOR_COMPRAS = 0;

Compra::Compra() {
    id = CONTADOR_COMPRAS++;
    titulo = "sem título";
    data = QDate::currentDate();
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

bool Compra::removeProduto(int idProduto) {

}

Produto *Compra::getProduto(int id) {
    return listaDeProdutos.at(id);
}

QList<Produto *> Compra::getProdutos() {
    return listaDeProdutos;
}

QString Compra::getTitulo() {
    return titulo;
}

QDate Compra::getData() {
    return data;
}

void Compra::setTitulo(QString titulo) {
    this->titulo = titulo;
}

void Compra::setData(QDate data) {
    this->data = data;
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
