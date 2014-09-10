#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    model = new QStandardItemModel(this);
    ui->treeViewCompras->setModel(model);

    typeView = COMPRAS;
    treeViewCompras_clicked();
    connect(ui->treeViewCompras, SIGNAL(mouseClicked()), this, SLOT(treeViewCompras_clicked()));
    connect(ui->treeViewProdutos, SIGNAL(mouseClicked()), this, SLOT(treeViewProdutos_clicked()));
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event) {
    emit close();
}

QList<QStandardItem *> MainWindow::compraToItemList(QString titulo, QDate data) {
    QList<QStandardItem*> res;
    res << new QStandardItem(titulo)
        << new QStandardItem(data.toString());
    return res;
}


void MainWindow::atualizarCompras()
{

}


void MainWindow::adicionarCompra(Compra *c)
{
    bool a=false;
    qDebug() << "Signal Existe Emitido...";
    emit existeCompra(c, &a);
    if(a){
        QMessageBox mss;
        mss.setText("Já existe uma Compra Com esse Titulo nesta Data!!!");
        mss.show();
        mss.exec();
        return;
    }
    qDebug() << "Sinal addCompra Emitido...";
    emit addCompra(c);
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
    return;
}

void MainWindow::carregarCompras()
{
    QList<Compra *> list = GerenciadorDeArquivos::getAllCompras();
    foreach (Compra * c, list){
        Compra * temp = new Compra(*c);
        adicionarCompra(temp);
    }
}

void MainWindow::on_actionSair_triggered() {
    exit(0);
}

void MainWindow::treeViewCompras_clicked() {
    QFont f, f2;
    f = f2 = ui->labelCompras->font();
    f.setBold(true);
    f2.setBold(false);
    ui->labelCompras->setFont(f);
    ui->labelProdutos->setFont(f2);
    typeView = COMPRAS;
}

void MainWindow::treeViewProdutos_clicked() {
    QFont f, f2;
    f = f2 = ui->labelCompras->font();
    f.setBold(true);
    f2.setBold(false);
    ui->labelCompras->setFont(f2);
    ui->labelProdutos->setFont(f);
    typeView = PRODUTO;
}

void MainWindow::on_actionAdd_triggered() {

    if(typeView == COMPRAS) {
        Compra * c = new Compra;
        DialogEditarCompra editarcompra(c);

        editarcompra.show();
        editarcompra.exec();
        if(editarcompra.acepted)
            adicionarCompra(c);
    }
    else if(typeView == PRODUTO) {
    }
}


void MainWindow::on_treeViewCompras_clicked(const QModelIndex &index)
{
    selected = index;
}

void MainWindow::on_actionRemove_triggered()
{
    if(typeView == COMPRAS){
        qDebug() << "Excluindo Conta...";
        QStandardItem * item = model->itemFromIndex(selected);

        emit removeComprasPorData(item->text());

        QStandardItem * parentItem = model->itemFromIndex(selected.parent());
         if(item->rowCount() == 0){
             Compra c(item->text(), QDate::fromString(parentItem->text(),"dd/MM/yyyy" ));
             emit removeCompra(&c);
             qDebug() << c.toString();
         }
        ui->treeViewCompras->model()->removeRow(selected.row(), selected.parent());
    }else if(typeView == PRODUTO){
        qDebug() << "Excluindo Produto...";
    }

}
