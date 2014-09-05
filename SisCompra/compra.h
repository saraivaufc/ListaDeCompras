#ifndef COMPRA_H
#define COMPRA_H

#include <QList>
#include <QDate>
#include "produto.h"
#include "Macros.h"

class Compra {
private:
    static int CONTADOR_COMPRAS;

    int id;
    QString titulo;
    QDate data;
    QList<Produto*> listaDeProdutos;

public:
    Compra();
    Compra(QString titulo);

    bool addProduto(Produto* prod);
    bool removeProduto(int idProduto);
    Produto* getProduto();

    int getQuantidadeProduto();
    int getQuantidadeTotal();
    float getValorTotal();
    float getValorClasse(ClasseDeProduto classe);

    void setTitulo(QString titulo);
    void setData(QDate data);
};

#endif // COMPRA_H
