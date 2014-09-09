#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    model = new QStandardItemModel(this);
    ui->treeViewCompras->setModel(model);
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
    DialogEditarCompra * editarcompra= new DialogEditarCompra(c);
    editarcompra->show();
    editarcompra->exec();
    if(editarcompra->acepted){
        adicionarCompra(c);
    }

}


void MainWindow::atualizarCompras()
{
}


void MainWindow::adicionarCompra(Compra *c)
{
    bool a;
    emit existeCompra(c, &a);
    if(a){
        QMessageBox mss;
        mss.setText("Já existe uma Compra Com esse Titulo nesta Data!!!");
        mss.show();
        mss.exec();
        return;
    }
    QStandardItem * root = model->invisibleRootItem();
    QString ch = c->getData().toString("dd/MM/yyyy").toUpper();
    for(int row=0; row < root->rowCount() ; row++){
        QStandardItem * item  = root->child(row, 0);
        item->setEditable(false);
        if(item->text().toUpper() == ch){
            item->appendRow(compraToItemList(c->getTitulo(), c->getData()));
            emit addCompra(c);
            return;
        }
    }
    QStandardItem * item = new QStandardItem(ch);
    item->setEditable(false);
    root->appendRow(item);
    item->appendRow(compraToItemList(c->getTitulo(), c->getData()));
    emit addCompra(c);
}

void MainWindow::carregarCompras()
{
    QList<Compra *> list = GerenciadorDeArquivos::getAllCompras();
    foreach (Compra * c,list){
        adicionarCompra(c);
    }
}

void MainWindow::on_actionSair_triggered()
{
    exit(0);
}

void MainWindow::on_excluirCompra_clicked()
{

}

void MainWindow::on_treeViewCompras_clicked(const QModelIndex &index)
{

}
