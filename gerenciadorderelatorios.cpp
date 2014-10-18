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

    for(int i = 1; i <= 12; i++) {
        QString s = QString::number(g->getGastosPorMes(i), 'f', 2);
        itens << new QStandardItem(s);
    }

    model->appendRow(itens);
}

void GerenciadorDeRelatorios::gerarRelatorioGastoClasse(GerenciadorDeCompras *g)
{
    QStringList list;

    list << "LIMPEZA"
         << "COMIDA"
         << "UTENSILIOS";

    model->clear();
    model->setColumnCount(3);
    model->setHorizontalHeaderLabels(list);

    QList<QStandardItem*> itens;

    QString s = QString::number(g->getGastosPorClasse(LIMPESA));
    itens << new QStandardItem(s);
    s = QString::number(g->getGastosPorClasse(COMIDA));
    itens << new QStandardItem(s);
    s = QString::number(g->getGastosPorClasse(UTENSILIOS));
    itens << new QStandardItem(s);
    model->appendRow(itens);

}

void GerenciadorDeRelatorios::gerarRelatorioGastoClasseMes(GerenciadorDeCompras *g)
{
    QStringList list1, list2;

    list1 << "Jan"
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

    list2 << "LIMPEZA"
         << "COMIDA"
         << "UTENSILIOS";


    model->clear();
    model->setColumnCount(12);
    model->setRowCount(list2.size());
    model->setHorizontalHeaderLabels(list1);
    model->setVerticalHeaderLabels(list2);

    for(int k=1 ; k <= list2.size(); k++ ){
        for(int i=1 ; i <= list1.size() ; i++){
            QString s = QString::number( g->getGastosPorClasseMes((ClasseDeProduto)k,i ) );
            model->setItem(k-1,i-1, new QStandardItem(s));
        }
    }

}

void GerenciadorDeRelatorios::gerarRelatorioGastoMax(GerenciadorDeCompras *g)
{
    QStringList list;

    list << "Mês de Maior Gasto"
         << "Compra de Maior Gasto"
         << "Classe de Produto de Maior Gasto";


    model->clear();
    model->setRowCount(list.size());
    model->setVerticalHeaderLabels(list);


    for(int i : g->getMesMaiorGasto()){
        model->setItem(0,i-1, new QStandardItem(QDate::shortMonthName(i)));
    }

    int index=0;
    for(Compra *c : g->getCompraMaiorGasto()){
        model->setItem(1,index, new QStandardItem(c->getTitulo()));
        index++;
    }
    index=0;
    for(ClasseDeProduto c : g->getClasseMaiorGasto()){
        model->setItem(2,index,new QStandardItem(classeToString(c)));
        index++;
    }

}
