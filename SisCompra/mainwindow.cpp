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
    DialogEditarCompra * editarcompra= new DialogEditarCompra(c);
    connect(editarcompra, SIGNAL(accepted()), this, SLOT(aceitouCompra()));
    editarcompra->show();
    editarcompra->exec();
}


void MainWindow::atualizarCompras()
{

}

void MainWindow::aceitouCompra()
{
    DialogEditarCompra *c = dynamic_cast<DialogEditarCompra *>(sender());
    if(c != 0){
        Compra * compra = new Compra(c->getTitulo(), c->getData());
        adicionarCompra(compra);
    }
}


void MainWindow::adicionarCompra(Compra *c)
{

    if(c->getTitulo().isEmpty())
        return;

    QStandardItem * root = model->invisibleRootItem();
    QString ch = c->getData().toString("dd/MM/yyyy").toUpper();
    for(int row=0; row < root->rowCount() ; row++){
        QStandardItem * item  = root->child(row, 0);
        item->setEditable(false);
        if(item->text().toUpper() == ch){
            item->appendRow(compraToItemList(c->getTitulo(), c->getData()));
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
    foreach (Compra * c, GerenciadorDeArquivos::getAllCompras()) {
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
    QStandardItem * item = model->itemFromIndex(index);
     if(item->rowCount() == 0){
         QString nome = item->text();
         QString telefone = index.sibling(index.row(),1).data().toString();
         QString email = index.sibling(index.row(),2).data().toString();
         ui->lbNome->setText(nome);
         ui->lbTelefone->setText(telefone);
         ui->lbemail->setText(email);
         ui->frame->setVisible(true);
     }else{
         ui->frame->setVisible(false);
     }
}
