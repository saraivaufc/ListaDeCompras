#ifndef PRODUTO_H
#define PRODUTO_H

#include <QString>

class Produto{
private:
    static int CONTADOR_PRODUTOS;

    int id;
    QString nome;
    int quantidade;
    float valorUnit;

public:
    Produto();
    Produto(QString nome);
    Produto(QString nome, float valor);
    Produto(QString nome, float valor, int qtd);
    ~Produto();

    int getId();
    QString getNome();
    int getQuantidade();
    float getValorUnit();
    float getValorTotal();
    QString toString();

    void setNome(QString nome);
    void setQuantidade(int quant);
    void setValorUnit(float valor);

    bool operator ==(Produto p);
    void operator ++(int);
};

#endif // PRODUTO_H
