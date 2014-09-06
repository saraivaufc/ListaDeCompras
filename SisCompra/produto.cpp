#include "produto.h"

int Produto::CONTADOR_PRODUTOS = 0;

Produto::Produto() {
    id = CONTADOR_PRODUTOS++;
    this->nome = "sem nome";
    this->valorUnit = 0.0;
    quantidade = 1;
}

Produto::Produto(QString nome) {
    id = CONTADOR_PRODUTOS++;
    this->nome = nome.toLower();
    this->valorUnit = 0.0;
    quantidade = 1;
}

Produto::Produto(QString nome, float valor) {
    id = CONTADOR_PRODUTOS++;
    this->nome = nome.toLower();
    this->valorUnit = valor;
    quantidade = 1;
}

Produto::Produto(QString nome, float valor, int quant) {
    id = CONTADOR_PRODUTOS++;
    this->nome = nome.toLower();
    this->valorUnit = valor;
    quantidade = quant;
}

Produto::~Produto() {

}

int Produto::getId() {
    return id;
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
    return "Produto [" + QString::number(id) + ": " +\
            nome + ": " +\
            QString::number(quantidade) + " unidades: R$ " +\
            QString::number(valorUnit) + "]";
}

void Produto::setId(int id) {
    this->id = id;
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

void Produto::operator =(Produto p) {
    setId(p.getId());
    setNome(p.getNome());
    setQuantidade(p.getQuantidade());
    setValorUnit(p.getValorUnit());;
}

bool Produto::operator ==(Produto p) {
    return nome == p.getNome();
}

void Produto::operator ++(int) {
    this->quantidade++;
}
