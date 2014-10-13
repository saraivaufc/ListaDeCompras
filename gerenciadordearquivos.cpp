<<<<<<< HEAD
#include <iostream>
#include "gerenciadordearquivos.h"

using namespace std;

GerenciadorDeArquivos::GerenciadorDeArquivos() {
}

void GerenciadorDeArquivos::criarDir() {
    if(!QDir(DIR_JSON).exists()) {
        QDir().mkdir(DIR_JSON);
    }
}

QJsonObject GerenciadorDeArquivos::getJsonFrom(Compra *c) {
    QJsonObject compra;

    compra["titulo"] = c->getTitulo();
    compra["data"] = getJsonFrom(c->getData());

    QJsonArray produtos;
    QList<Produto*> listProdutos = c->getProdutos();
    foreach (Produto* p, listProdutos) {
        produtos.append(getJsonFrom(p));
    }

    compra["produtos"] = produtos;

    return compra;
}

QJsonObject GerenciadorDeArquivos::getJsonFrom(Produto *p) {
    QJsonObject prod;
    prod["nome"] = p->getNome();
    prod["quantidade"] = p->getQuantidade();
    prod["valor"] = p->getValorUnit();
    prod["classe"] = p->getClass();

    return prod;
}

QJsonObject GerenciadorDeArquivos::getJsonFrom(QDate d) {
    QJsonObject data;

    data["dia"] = d.day();
    data["mes"] = d.month();
    data["ano"] = d.year();

    return data;
}

void GerenciadorDeArquivos::fromJson(QJsonObject &j, Compra &c) {
    c.setTitulo(j["titulo"].toString());

    QDate date;
    QJsonObject dateObj = j["data"].toObject();
    fromJson(dateObj, date);
    c.setData(date);

    QJsonArray array = j["produtos"].toArray();

    foreach(QJsonValue value, array) {
        Produto* p = new Produto();
        QJsonObject obj = value.toObject();

        fromJson(obj, *p);
        c.addProduto(p);
    }
}

void GerenciadorDeArquivos::fromJson(QJsonObject &j, Produto &p) {
    p.setNome(j["nome"].toString());
    p.setQuantidade(j["quantidade"].toInt());
    p.setValorUnit(j["valor"].toDouble());
    p.setClasse(j["classe"].toString());
}

void GerenciadorDeArquivos::fromJson(QJsonObject &j, QDate &d) {
    d.setDate(
            j["ano"].toInt(),
            j["mes"].toInt(),
            j["dia"].toInt()
            );
}



void GerenciadorDeArquivos::salvarCompra(Compra *c) {
    criarDir();

    QJsonObject compra = getJsonFrom(c);
    QJsonDocument doc(compra);

    QFile saveFile(QString(DIR_JSON) + "/" + c->getData().toString("dd-MM-yy") + "_"+ c->getTitulo() + ".json");
    saveFile.open(QIODevice::WriteOnly);
    saveFile.write(doc.toJson());

    saveFile.close();
}

void GerenciadorDeArquivos::salvarCompra(QList<Compra *> compras) {
    foreach(Compra* c, compras)
        salvarCompra(c);
}

void GerenciadorDeArquivos::carregarCompra(QString fileName, Compra *c) {
    QFile file(QString(DIR_JSON) + "/" + fileName);

    if(!file.open(QIODevice::ReadOnly))
        cout << "ERRO!";

    QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
    QJsonObject obj = doc.object();
    fromJson(obj, *c);
}

QList<Compra *> GerenciadorDeArquivos::getAllCompras() {
    QList<Compra*> compras;
    QDir recoredDir(DIR_JSON);
    QStringList allFiles = recoredDir.entryList(QDir::Files);

    foreach (QString s, allFiles) {
        Compra* c = new Compra;
        carregarCompra(s, c);
        compras.append(c);
    }

    return compras;
}

void GerenciadorDeArquivos::removeCompra(Compra *c) {
    QFile::remove(QString(DIR_JSON) + "/" + c->getData().toString("dd-MM-yy") + "_"+ c->getTitulo() + ".json");
}

bool GerenciadorDeArquivos::existeCompra(Compra *c)
{
    QList<Compra * > compras = getAllCompras();
    if(compras.contains(c)){
        return true;
    }else{
        return false;
    }
}
=======
#include <iostream>
#include "gerenciadordearquivos.h"

using namespace std;

GerenciadorDeArquivos::GerenciadorDeArquivos() {
}

void GerenciadorDeArquivos::criarDir() {
    if(!QDir(DIR_JSON).exists()) {
        QDir().mkdir(DIR_JSON);
    }
}

QJsonObject GerenciadorDeArquivos::getJsonFrom(Compra *c) {
    QJsonObject compra;

    compra["titulo"] = c->getTitulo();
    compra["data"] = getJsonFrom(c->getData());

    QJsonArray produtos;
    QList<Produto*> listProdutos = c->getProdutos();
    foreach (Produto* p, listProdutos) {
        produtos.append(getJsonFrom(p));
    }

    compra["produtos"] = produtos;

    return compra;
}

QJsonObject GerenciadorDeArquivos::getJsonFrom(Produto *p) {
    QJsonObject prod;
    prod["nome"] = p->getNome();
    prod["quantidade"] = p->getQuantidade();
    prod["valor"] = p->getValorUnit();
    prod["classe"] = p->getClass();

    return prod;
}

QJsonObject GerenciadorDeArquivos::getJsonFrom(QDate d) {
    QJsonObject data;

    data["dia"] = d.day();
    data["mes"] = d.month();
    data["ano"] = d.year();

    return data;
}

void GerenciadorDeArquivos::fromJson(QJsonObject &j, Compra &c) {
    c.setTitulo(j["titulo"].toString());

    QDate date;
    QJsonObject dateObj = j["data"].toObject();
    fromJson(dateObj, date);
    c.setData(date);

    QJsonArray array = j["produtos"].toArray();

    foreach(QJsonValue value, array) {
        Produto* p = new Produto();
        QJsonObject obj = value.toObject();

        fromJson(obj, *p);
        c.addProduto(p);
    }
}

void GerenciadorDeArquivos::fromJson(QJsonObject &j, Produto &p) {
    p.setNome(j["nome"].toString());
    p.setQuantidade(j["quantidade"].toInt());
    p.setValorUnit(j["valor"].toDouble());
    p.setClasse(j["classe"].toString());
}

void GerenciadorDeArquivos::fromJson(QJsonObject &j, QDate &d) {
    d.setDate(
            j["ano"].toInt(),
            j["mes"].toInt(),
            j["dia"].toInt()
            );
}



void GerenciadorDeArquivos::salvarCompra(Compra *c) {
    criarDir();

    QJsonObject compra = getJsonFrom(c);
    QJsonDocument doc(compra);

    QFile saveFile(QString(DIR_JSON) + "/" + c->getData().toString("dd-MM-yy") + "_"+ c->getTitulo() + ".json");
    saveFile.open(QIODevice::WriteOnly);
    saveFile.write(doc.toJson());

    saveFile.close();
}

void GerenciadorDeArquivos::salvarCompra(QList<Compra *> compras) {
    foreach(Compra* c, compras)
        salvarCompra(c);
}

void GerenciadorDeArquivos::carregarCompra(QString fileName, Compra *c) {
    QFile file(QString(DIR_JSON) + "/" + fileName);

    if(!file.open(QIODevice::ReadOnly))
        cout << "ERRO!";

    QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
    QJsonObject obj = doc.object();
    fromJson(obj, *c);
}

QList<Compra *> GerenciadorDeArquivos::getAllCompras() {
    QList<Compra*> compras;
    QDir recoredDir(DIR_JSON);
    QStringList allFiles = recoredDir.entryList(QDir::Files);

    foreach (QString s, allFiles) {
        Compra* c = new Compra;
        carregarCompra(s, c);
        compras.append(c);
    }

    return compras;
}

void GerenciadorDeArquivos::removeCompra(Compra *c) {
    QFile::remove(QString(DIR_JSON) + "/" + c->getData().toString("dd-MM-yy") + "_"+ c->getTitulo() + ".json");
}

bool GerenciadorDeArquivos::existeCompra(Compra *c)
{
    QList<Compra * > compras = getAllCompras();
    if(compras.contains(c)){
        return true;
    }else{
        return false;
    }
}
>>>>>>> 39f381eefdb8a8c2d1c947ccd6862df2067ef649
