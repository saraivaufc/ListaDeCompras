#ifndef PRODUTO_H
#define PRODUTO_H

#include <QString>
#include "Macros.h"

class Produto{
private:

    QString nome;
    int quantidade;
    float valorUnit;
    ClasseDeProduto classe;

public:
    Produto();
    Produto(Produto * p);
    Produto(QString nome);
    Produto(QString nome, float valor);
    Produto(QString nome, float valor, int qtd);
    Produto(QString nome,ClasseDeProduto classe);
    Produto(QString nome,ClasseDeProduto classe, float valor, int qtd);
    ~Produto();

    //sets
    void setNome(QString nome);
    void setQuantidade(int quant);
    void setValorUnit(float valor);
    void setClasse(ClasseDeProduto classe);

    //gets
    QString getNome();
    int getQuantidade();
    float getValorUnit();
    float getValorTotal();
    QString toString();
    ClasseDeProduto getClass();

    Produto *clone();

    //operators
    void operator =(Produto p);
    bool operator ==(Produto p);
    void operator ++(int);
    void operator --(int);
};

#endif // PRODUTO_H
