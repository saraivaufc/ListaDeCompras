#include "gerenciadorderelatorios.h"
#include "dialogrelatorio.h"

QStandardItemModel* GerenciadorDeRelatorios::model = new QStandardItemModel();

void GerenciadorDeRelatorios::gerarRelatorio(GerenciadorDeRelatorios::TipoRelatorio tipoRelatorio, GerenciadorDeCompras *g, QWidget* parent) {

    QString label;

    switch(tipoRelatorio) {
    case GASTO_MES:
        gerarRelatorioGastoMes(g);
        label = "Relatório de gastos por mês";
        break;
    case GASTO_CLASSE:
        gerarRelatorioGastoClasse(g);
        label = "Relatório de gastos por classe de produto";
        break;
    case GASTO_CLASSE_MES:
        gerarRelatorioGastoClasseMes(g);
        label = "Relatório de gastos por classe de produto e mês";
        break;
    case GASTO_MAX:
        gerarRelatorioGastoMax(g);
        label = "Relatório de maiores gastos";
        break;
    }

    qDebug() << "...";
    DialogRelatorio d;
    qDebug() << "generate";

    d.setModal(true);
    d.setLabel(label);
    d.setHorizontalHeaderSize(40);
    d.setModel(model);

    d.show();
    d.exec();
}

void GerenciadorDeRelatorios::gerarRelatorioGastoMes(GerenciadorDeCompras* g) {
    QStringList list;

    list << "Jan"
         << "Fev"
         << "Mar"
         << "Abr"
         << "Mai"
         << "Jun"
         << "Jul"
         << "Ago"
         << "Set"
         << "Out"
         << "Nov"
         << "Dez";

    model->clear();
    model->setColumnCount(12);
    model->setHorizontalHeaderLabels(list);

    QList<QStandardItem*> itens;

    for(int i = 0; i < 12; i++) {
        QString s = QString::number(g->getGastosPorMes(i), 'f', 2);
        itens << new QStandardItem(s);
    }

    model->appendRow(itens);
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

