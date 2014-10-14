#include "gerenciadorderelatorios.h"
#include "dialogrelatorio.h"

QStandardItemModel GerenciadorDeRelatorios::model;

void GerenciadorDeRelatorios::gerarRelatorio(GerenciadorDeRelatorios::TipoRelatorio tipoRelatorio, GerenciadorDeCompras *g, QWidget* parent) {

    switch(tipoRelatorio) {
    case GASTO_MES:
        gerarRelatorioGastoMes(g);
        break;
    case GASTO_CLASSE:
        gerarRelatorioGastoClasse(g);
        break;
    case GASTO_CLASSE_MES:
        gerarRelatorioGastoClasseMes(g);
        break;
    case GASTO_MAX:
        gerarRelatorioGastoMax(g);
        break;
    }

    DialogRelatorio d(parent);
    d.setModel(&model);
    d.show();
    d.exec();
}

void GerenciadorDeRelatorios::gerarRelatorioGastoMes(GerenciadorDeCompras* g) {
    QStringList list;

    list << "Janeiro"
         << "Fevereiro"
         << "Março"
         << "Abril"
         << "Maio"
         << "Junho"
         << "Julho"
         << "Agosto"
         << "Setembro"
         << "Outubro"
         << "Novembro"
         << "Dezembro";

    model.setColumnCount(12);
    model.setHorizontalHeaderLabels(list);

    QList<QStandardItem*> itens;

    for(int i = 0; i < 12; i++)
        itens << new QStandardItem(QString::number(g->getGastosPorMes(i), 'g', 2));

    model.appendRow(itens);
}

void GerenciadorDeRelatorios::gerarRelatorioGastoClasse(GerenciadorDeCompras *)
{

}

void GerenciadorDeRelatorios::gerarRelatorioGastoClasseMes(GerenciadorDeCompras *)
{

}

void GerenciadorDeRelatorios::gerarRelatorioGastoMax(GerenciadorDeCompras *)
{

}

