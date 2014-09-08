#include "controladordosistema.h"

ControladorDoSistema::ControladorDoSistema(QObject *parent) :
    QObject(parent)
{
    interface = new MainWindow;
    interface->show();

    connect(interface, SIGNAL(addCompra()),this,SLOT(addCompra()));
}

GerenciadorDeCompras *ControladorDoSistema::getGerenciadorCompras()
{
    return &gerenciadorDeCompras;
}

void ControladorDoSistema::addCompra(void)
{
    dialogAddCompra.limparTudo();
    dialogAddCompra.show();
    dialogAddCompra.exec();
    QString nomeCompra = dialogAddCompra.getNomeCompra();
    QDate dataCompra = dialogAddCompra.getDataCompra();
    Compra c(nomeCompra, dataCompra);
    gerenciadorDeCompras.addCompra(c);

    GerenciadorDeArquivos::salvarCompra(&c);
}
