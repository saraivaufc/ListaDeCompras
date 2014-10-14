#ifndef COMPRA_H
#define COMPRA_H

#include <QList>
#include <QDate>
#include "produto.h"
#include "Macros.h"

class Compra{
private:
    static int CONTADOR_COMPRAS;
    int id;
    QString titulo;
    QDate data;
    QList<Produto*> listaDeProdutos;

public:
    Compra();
    Compra(Compra *c);
    Compra(QString titulo);
    Compra(QString titulo, QDate data);

    bool addProduto(Produto* prod);
    bool removeProduto(Produto * p);
    Produto* getProduto(int id);
    QList<Produto*> getProdutos();

    int getID();
    QString getTitulo();
    QDate getData();
    int getQuantidadeProduto();
    int getQuantidadeTotal();
    float getValorTotal();
    float getValorClasse(QString classe);
    int getContadorCompra();

    void setTitulo(QString titulo);
    void setData(QDate data);

    bool operator == (Compra c);

    Compra * clone();
    QString toString();
};

#endif // COMPRA_H
