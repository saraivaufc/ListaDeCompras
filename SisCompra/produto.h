#ifndef PRODUTO_H
#define PRODUTO_H

#include <QString>

class Produto{
private:

    QString nome;
    int quantidade;
    float valorUnit;
    QString classe;

public:
    Produto();
    Produto(QString nome);
    Produto(QString nome, float valor);
    Produto(QString nome, float valor, int qtd);
    Produto(QString nome, float valor, int qtd, QString classe);
    ~Produto();

    QString getNome();
    int getQuantidade();
    float getValorUnit();
    float getValorTotal();
    QString toString();
    QString getClass();

    void setNome(QString nome);
    void setQuantidade(int quant);
    void setValorUnit(float valor);
    void setClasse(QString classe);

    void operator =(Produto p);
    bool operator ==(Produto p);
    void operator ++(int);
    void operator --(int);
};

#endif // PRODUTO_H
