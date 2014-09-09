#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialogeditarcompra.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    gerenciadorArquivos = new GerenciadorDeArquivos;

    model = new QStandardItemModel(this);
    ui->treeViewCompras->setModel(model);
    loadCompras();

}

MainWindow::~MainWindow() {
    delete ui;
}

QList<QStandardItem *> MainWindow::compraToItemList(QString titulo, QDate data) {
    QList<QStandardItem*> res;
    res << new QStandardItem(titulo)
        << new QStandardItem(data.toString());
    return res;
}


void MainWindow::atualizarCompras() {

}

void MainWindow::on_adicionarCompra_clicked() {
    Compra* c = new Compra;
    DialogEditarCompra d(c);
    d.show();
    d.exec();

    //add compra na listView
    adicionarCompra(*c);

    //add compra no gerenciador de compras
    emit addCompra(c);
}

void MainWindow::adicionarCompra(Compra &c){
    if(c.getTitulo().isEmpty())
        return;

    QStandardItem * root = model->invisibleRootItem();
    QChar ch = c.getTitulo().toUpper()[0];
    for(int row=0; row < root->rowCount() ; row++){
        QStandardItem * item  = root->child(row, 0);
        if(item->text().toUpper()[0] == ch){
            item->appendRow(compraToItemList(c.getTitulo(), c.getData()));
            return;
        }
    }
    QStandardItem * item = new QStandardItem(ch);
    root->appendRow(item);
    item->appendRow(compraToItemList(c.getTitulo(), c.getData()));
}

void MainWindow::loadCompras()
{
    foreach (Compra * c, gerenciadorArquivos->getAllCompras()) {
        //controlador->getGerenciadorCompras()->addCompra(*c);
        //adicionarCompra(*c, false);
    }
}

void MainWindow::on_actionSair_triggered()
{
    exit(0);
}
