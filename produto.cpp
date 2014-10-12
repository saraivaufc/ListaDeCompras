#include "produto.h"

Produto::Produto() {
    this->nome = "";
    this->valorUnit = 0.0;
    quantidade = 1;
}

Produto::Produto(Produto *p)
{
    this->nome=p->getNome();
    this->valorUnit=p->getValorUnit();
    this->quantidade=p->getQuantidade();
    this->classe=p->getClass();
}

Produto::Produto(QString nome) {
    this->nome = nome;
    this->valorUnit = 0.0;
    quantidade = 1;
}

Produto::Produto(QString nome, float valor) {
    this->nome = nome;
    this->valorUnit = valor;
    quantidade = 1;
}

Produto::Produto(QString nome, float valor, int quant) {
    this->nome = nome;
    this->valorUnit = valor;
    quantidade = quant;
}

Produto::Produto(QString nome, QString classe)
{
    this->nome = nome;
    this->classe = classe;
}


Produto::Produto(QString nome, QString classe , float valor, int quant) {
    this->nome = nome;
    this->valorUnit = valor;
    this->quantidade = quant;
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

Produto *Produto::clone()
{
    return new Produto(this);
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
