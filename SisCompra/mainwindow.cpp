#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    model = new QStandardItemModel(this);
    model2 = new QStandardItemModel(this);
    ui->treeViewCompras->setModel(model);
    ui->treeViewProdutos->setModel(model2);


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

QList<QStandardItem *> MainWindow::produtoToItemList(QString nome, float valor, int qtd, QString classe)
{
    QList<QStandardItem*> res;
    res << new QStandardItem(nome)
        << new QStandardItem(QString::number(valor))
        << new QStandardItem(QString::number(qtd))
        << new QStandardItem(classe);
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
            item->appendRow(
                        compraToItemList(
                            c->getTitulo(),
                            c->getData()
                        )
            );
            return;
        }
    }

    QStandardItem * item = new QStandardItem(ch);
    item->setEditable(false);
    root->appendRow(item);
    item->appendRow(compraToItemList(c->getTitulo(), c->getData()));
    return;
}

void MainWindow::adicionarProduto(Compra *c, Produto *p, bool somenteNaInterface)
{

    qDebug() << "tentando adicionar Produto..";

    bool a=false;
    qDebug() << "Compra=" + c->toString() + "Produto=" + p->toString();

     qDebug() << "Signal Existe do Produto Emitido...";
     emit existeProduto(c, p, &a);

     if(a && (somenteNaInterface == false)){
        return;
    }
     if(!somenteNaInterface){
         qDebug() << "Sinal addProduto Emitido...";
         emit addProduto(c, p);
     }


    QStandardItem * root2 = model2->invisibleRootItem();
    QString ch = p->getClass().toUpper();

    for(int row=0; row < root2->rowCount() ; row++){
        QStandardItem * item  = root2->child(row, 0);
        item->setEditable(false);
        if(item->text().toUpper() == ch){
            item->appendRow(    produtoToItemList(
                                    p->getNome(),
                                    p->getQuantidade(),
                                    p->getValorUnit(),
                                    p->getClass()
                                 )
                            );

            return;
        }
    }

    qDebug() << "Adicionada uma nova Classe";
    QStandardItem * item = new QStandardItem(ch);
    item->setEditable(false);
    root2->appendRow(item);

    item->appendRow(produtoToItemList(
                        p->getNome(),
                        p->getQuantidade(),
                        p->getValorUnit(),
                        p->getClass()
                        )
                    );
    return;
}

void MainWindow::listaProdutosVisivel(bool estado)
{
    ui->treeViewProdutos->setVisible(estado);
    ui->labelProdutos->setVisible(estado);
}

void MainWindow::listaComprasVisivel(bool estado)
{
    ui->treeViewCompras->setVisible(estado);
    ui->labelCompras->setVisible(estado);
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
    close();
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
    qDebug() << "Compras Clicada!!!";
}

void MainWindow::treeViewProdutos_clicked() {
    QFont f, f2;
    f = f2 = ui->labelCompras->font();
    f.setBold(true);
    f2.setBold(false);
    ui->labelCompras->setFont(f2);
    ui->labelProdutos->setFont(f);
    typeView = PRODUTO;
    qDebug() << "Produto Clicado!!!";
}

void MainWindow::on_actionAdd_triggered() {

    if(typeView == COMPRAS) {
        Compra * c = new Compra;
        DialogEditarCompra editarcompra(c);
        editarcompra.setWindowTitle("Adicionar Compra");
        editarcompra.setDescricao("Nova Compra");
        editarcompra.show();
        editarcompra.exec();
        if(editarcompra.acepted)
            adicionarCompra(c);
    }
    else if(typeView == PRODUTO) {
        if(!compraIsSelected()){
            QMessageBox aviso;
            aviso.setWindowTitle("Aviso!!!");
            aviso.setText("Error!, Favor Selecionar uma Compra...");
            aviso.setFocus();
            aviso.show();
            aviso.exec();
            return ;
        }
        Produto *p = new Produto;
        DialogEditarProduto editarproduto(p);
        editarproduto.setWindowTitle("Adicionar produto");
        editarproduto.setDescricao("Novo Produto");
        editarproduto.show();
        editarproduto.exec();
        if(editarproduto.acepted){
            QDate dataCompra = QDate::fromString(model->itemFromIndex(selected.parent())->text(),"dd/MM/yyyy");
            QString nomeCompra = model->itemFromIndex(selected)->text();
            Compra **a;
            Compra *b;
            a=&b;

            qDebug() << nomeCompra << "-" <<dataCompra.toString();
            emit buscaCompra(a,nomeCompra,dataCompra);
            qDebug() << b->toString();
            adicionarProduto(b,p);
        }
    }
}


void MainWindow::on_treeViewCompras_clicked(const QModelIndex &index)
{
    qDebug() << "Compra Selecionada...";
    selected = index;

    QStandardItem * root = model->invisibleRootItem();
    QStandardItem * root2 = model2->invisibleRootItem();

    //quando eu clica numa compra, eu removo todos os itens da interface, para poder colocar os outros
    root2->removeColumns(0, root2->columnCount());
    root2->removeRows(0, root2->rowCount());
    //Se eu tiver clicado numa Data, então eu limpo os produtos e saio
    if(index.parent() == root->index()){
        qDebug() << "Cliquei Numa Data...";
        return;
    }

    QString nomeCompra= model->itemFromIndex(index)->text();
    QDate dataCompra= QDate::fromString(model->itemFromIndex(index.parent())->text(),"dd/MM/yyyy");
    Compra **a;
    Compra *b;
    a=&b;
    qDebug() << nomeCompra << "-" <<dataCompra.toString();
    qDebug() << "Sinal Busca Compra Emitido";
    emit buscaCompra(a,nomeCompra,dataCompra);


    qDebug() << "SIGNAL Atualizando Produtos emitido";
    emit atualizandoProdutosNaGui();
    foreach (Produto * p, b->getProdutos()){
        adicionarProduto(b, p, true);
    }

}

void MainWindow::on_treeViewProdutos_clicked(const QModelIndex &index)
{
    qDebug() << "Produto Selecionada...";
    selected2 = index;
}

bool MainWindow::compraIsSelected()
{
    return !(selected.parent() == model->invisibleRootItem()->index());
}

bool MainWindow::produtoIsSelected()
{
    return !(selected2.parent() == model2->invisibleRootItem()->index());
}


void MainWindow::on_actionRemove_triggered()
{

    QStandardItem * item = model->itemFromIndex(selected);
    //se não tiver nenhum item selecionado ele retorna
    if(item == NULL){
        return;
    }
    if(typeView == COMPRAS){
        qDebug() << "Excluindo Conta...";

        //emite uma sinal para o controlador com a compra que ele quer remover
        emit removeComprasPorData(item->text());

        //pega o pai do item selecionado
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
