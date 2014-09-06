#include <iostream>
#include "controladordosistema.h"
#include <QApplication>

using namespace std;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    //ControladorDoSistema controlador;
    Compra c("Minha compra");
    c.addProduto(new Produto("felipe", 10.30, 1));
    c.addProduto(new Produto("felipe", 1.80, 1));

    Compra c2("Minha compra 2");
    c2.addProduto(new Produto("felipe", 10.30, 1));
    c2.addProduto(new Produto("bozitoo", 1.80, 1));

    GerenciadorDeArquivos::salvarCompra(&c);
    GerenciadorDeArquivos::salvarCompra(&c2);

    QList<Compra*> comp = GerenciadorDeArquivos::getAllCompras();
    cout << comp.at(0)->toString().toStdString() << endl;
    cout << comp.at(1)->toString().toStdString() << endl;

    exit(0);

    return a.exec();
}
