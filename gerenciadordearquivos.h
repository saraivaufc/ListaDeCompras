<<<<<<< HEAD
#ifndef GERENCIADORDEARQUIVOS_H
#define GERENCIADORDEARQUIVOS_H

#include <QFile>
#include <QDir>
#include <QList>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include "compra.h"
#include "Macros.h"

class GerenciadorDeArquivos {
public:
    GerenciadorDeArquivos();

    static void salvarCompra(Compra *c);
    static void salvarCompra(QList<Compra*>);

    static void carregarCompra(QString fileName, Compra* c);
    static QList<Compra*> getAllCompras();

    static void removeCompra(Compra* c);
    static bool existeCompra(Compra * c);

private:
    static void criarDir();
    static QJsonObject getJsonFrom(Compra* c);
    static QJsonObject getJsonFrom(Produto* p);
    static QJsonObject getJsonFrom(QDate p);

    static void fromJson(QJsonObject& j, Compra& c);
    static void fromJson(QJsonObject& j, Produto& p);
    static void fromJson(QJsonObject& j, QDate& d);

};

#endif // GERENCIADORDEARQUIVOS_H
=======
#ifndef GERENCIADORDEARQUIVOS_H
#define GERENCIADORDEARQUIVOS_H

#include <QFile>
#include <QDir>
#include <QList>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include "compra.h"
#include "Macros.h"

class GerenciadorDeArquivos {
public:
    GerenciadorDeArquivos();

    static void salvarCompra(Compra *c);
    static void salvarCompra(QList<Compra*>);

    static void carregarCompra(QString fileName, Compra* c);
    static QList<Compra*> getAllCompras();

    static void removeCompra(Compra* c);
    static bool existeCompra(Compra * c);

private:
    static void criarDir();
    static QJsonObject getJsonFrom(Compra* c);
    static QJsonObject getJsonFrom(Produto* p);
    static QJsonObject getJsonFrom(QDate p);

    static void fromJson(QJsonObject& j, Compra& c);
    static void fromJson(QJsonObject& j, Produto& p);
    static void fromJson(QJsonObject& j, QDate& d);

};

#endif // GERENCIADORDEARQUIVOS_H
>>>>>>> 39f381eefdb8a8c2d1c947ccd6862df2067ef649
