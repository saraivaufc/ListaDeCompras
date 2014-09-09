#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    model = new QStandardItemModel(this);
    ui->treeViewCompras->setModel(model);
    emit inicializada();
    carregarCompras();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    emit close();
}

QList<QStandardItem *> MainWindow::compraToItemList(  QString titulo,
                                                     QDate data)
{
    QList<QStandardItem*> res;
    res << new QStandardItem(titulo)
        << new QStandardItem(data.toString());
    return res;
}


//adicionar nova compra
void MainWindow::on_adicionarCompra_clicked()
{
    Compra * c = new Compra;
    DialogEditarCompra editarcompra(c);
    editarcompra.show();
    editarcompra.exec();
    emit addCompra(c);
    adicionarCompra(c);
}


void MainWindow::atualizarCompras()
{

}


void MainWindow::adicionarCompra(Compra *c)
{
    if(c->getTitulo().isEmpty())
        return;

    QStandardItem * root = model->invisibleRootItem();
    QString ch = c->getData().toString("dd/MM/yyyy").toUpper();
    for(int row=0; row < root->rowCount() ; row++){
        QStandardItem * item  = root->child(row, 0);
        if(item->text().toUpper() == ch){
            item->appendRow(compraToItemList(c->getTitulo(), c->getData()));
            return;
        }
    }
    QStandardItem * item = new QStandardItem(ch);
    root->appendRow(item);
    item->appendRow(compraToItemList(c->getTitulo(), c->getData()));
}

void MainWindow::carregarCompras()
{
    foreach (Compra * c, GerenciadorDeArquivos::getAllCompras()) {
        adicionarCompra(c);
    }
}

void MainWindow::on_actionSair_triggered()
{
    exit(0);
}
