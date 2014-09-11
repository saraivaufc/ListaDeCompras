#include "produto.h"

Produto::Produto() {
    this->nome = "sem nome";
    this->valorUnit = 0.0;
    quantidade = 1;
}

Produto::Produto(QString nome) {
    this->nome = nome.toLower();
    this->valorUnit = 0.0;
    quantidade = 1;
}

Produto::Produto(QString nome, float valor) {
    this->nome = nome.toLower();
    this->valorUnit = valor;
    quantidade = 1;
}

Produto::Produto(QString nome, float valor, int quant) {
    this->nome = nome.toLower();
    this->valorUnit = valor;
    quantidade = quant;
}


Produto::Produto(QString nome, float valor, int quant, QString classe) {
    this->nome = nome.toLower();
    this->valorUnit = valor;
    quantidade = quant;
    this->classe = classe;
}


Produto::~Produto() {

}

QString Produto::getNome() {
    return nome;
}

int Produto::getQuantidade() {
    return quantidade;
}

float Produto::getValorUnit() {
    return valorUnit;
}

float Produto::getValorTotal() {
    return quantidade*valorUnit;
}

QString Produto::toString() {
    return "Produto [" + nome + ": " +\
            QString::number(quantidade) + " unidades: R$ " +\
            QString::number(valorUnit) +\
            this->classe + "]";
}

QString Produto::getClass()
{
    return this->classe;
}


void Produto::setNome(QString nome) {
    this->nome = nome;
}

void Produto::setQuantidade(int quant) {
    quantidade = quant;
}

void Produto::setValorUnit(float valor) {
    valorUnit = valor;
}

void Produto::setClasse(QString classe)
{
    this->classe = classe;
}

void Produto::operator =(Produto p) {
    setNome(p.getNome());
    setQuantidade(p.getQuantidade());
    setValorUnit(p.getValorUnit());
    setClasse(p.getClass());
}

bool Produto::operator ==(Produto p) {
    return nome == p.getNome() && classe == p.getClass();
}

void Produto::operator ++(int) {
    this->quantidade++;
}

void Produto::operator --(int)
{
    this->quantidade--;
}
