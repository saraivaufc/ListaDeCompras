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

    if(somenteNaInterface == false){
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

void MainWindow::limparProdutosInterface()
{

    QStandardItem * root = model2->invisibleRootItem();
    root->removeColumns(0, root->columnCount());
    root->removeRows(0, root->rowCount());
}

void MainWindow::carregaCompraSelecionada(Compra **c)
{

    QString nomeCompra= model->itemFromIndex(selected)->text();
    QDate dataCompra= QDate::fromString(model->itemFromIndex(selected.parent())->text(),"dd/MM/yyyy");
    Compra **a;
    a=&(*c);
    emit buscaCompra(a,nomeCompra,dataCompra);
    return;
}

void MainWindow::carregaProdutoSelecionado(Produto **p)
{
    Compra ** c;
    Compra *c2;
    c=&c2;
    carregaCompraSelecionada(c);
    //se eu tento editar uma data como se fosse uma compra

    if(selected2.parent() == model2->invisibleRootItem()->index()){
        return;
    }
    QString nomeProduto = model2->itemFromIndex(selected2)->text();
    QString classeProduto = model2->itemFromIndex(selected2.parent())->text();
    if(nomeProduto == NULL || classeProduto == NULL){
        return;
    }
    Produto **k;
    k=&(*p);
    emit buscaProduto(c2,k,nomeProduto, classeProduto);
    return;
}


void MainWindow::carregarCompras()
{
    QList<Compra *> list = GerenciadorDeArquivos::getAllCompras();
    foreach (Compra * c, list){
        adicionarCompra(c);
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
        if(editarcompra.acepted){
            adicionarCompra(c);
        }
        return;
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
            return;
        }
    }
}


void MainWindow::on_treeViewCompras_clicked(const QModelIndex &index)
{
    qDebug() << "Compra Selecionada...";
    selected = index;

    QStandardItem * root = model->invisibleRootItem();
    QStandardItem * root2 = model2->invisibleRootItem();

    limparProdutosInterface();
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

    if(typeView == COMPRAS){

        QStandardItem * item = model->itemFromIndex(selected);
        //se não tiver nenhum item selecionado ele retorna
        if(item == NULL){
            return;
        }
        qDebug() << "Excluindo Conta...";

        if(selected.parent() == model->invisibleRootItem()->index()){
            //emite uma sinal para o controlador com a compra que ele quer remover
            emit removeComprasPorData(item->text());
        }
        if(item->rowCount() == 0){
            Compra c(item->text(), QDate::fromString(item->parent()->text(),"dd/MM/yyyy" ));
            emit removeCompra(&c);
            qDebug() << c.toString();
        }
        ui->treeViewCompras->model()->removeRow(selected.row(), selected.parent());


    }else if(typeView == PRODUTO){

        QStandardItem * item = model->itemFromIndex(selected);
        QStandardItem * item2 = model2->itemFromIndex(selected2);

        qDebug()<<"Remove Produto Emitido";

        if(item == NULL || item2 == NULL){
            return;
        }

        if(selected2.parent() == model2->invisibleRootItem()->index()){
            emit removeProdutoPorClasse(item2->text());
        }

        if(item2->rowCount() == 0){
            Compra c(item->text(), QDate::fromString(item->parent()->text(),"dd/MM/yyyy" ));
            Produto p(item2->text(),item2->parent()->text());
            emit removeProduto(&c, &p);
        }

        ui->treeViewProdutos->model()->removeRow(selected2.row(), selected2.parent());
        qDebug() << "Excluindo Produto";

    }

}

void MainWindow::on_actionEdit_triggered()
{
    QString nomeCompra= model->itemFromIndex(selected)->text();
    QDate dataCompra= QDate::fromString(model->itemFromIndex(selected.parent())->text(),"dd/MM/yyyy");
    Compra **a;
    Compra *b;
    a=&b;
    emit buscaCompra(a,nomeCompra,dataCompra);

    if(typeView == COMPRAS){

        //se eu tento editar uma data como se fosse uma compra
        if(selected.parent() == model->invisibleRootItem()->index()){
            return;
        }

        //apago a velha compra
        emit removeCompra(b);
        //edito ela
        DialogEditarCompra editarCompra(b);
        editarCompra.show();
        editarCompra.exec();
        //adiciono a nova compra na interface e na lista de compras
        ui->treeViewCompras->model()->removeRow(selected.row(), selected.parent());
        adicionarCompra(b);


    }else if(typeView == PRODUTO){

        //se eu tento editar uma data como se fosse uma compra
        if(selected2.parent() == model2->invisibleRootItem()->index()){
            return;
        }
        QString nomeProduto = model2->itemFromIndex(selected2)->text();
        QString classeProduto = model2->itemFromIndex(selected2.parent())->text();
        if(nomeProduto == NULL || classeProduto == NULL){
            return;
        }
        Produto **c;
        Produto *d;
        c=&d;
        emit buscaProduto(b,c,nomeProduto, classeProduto);
        if(d == NULL){
            qDebug() << "D vazio";
            return;
        }
        Produto antigo(d);
        emit removeProduto(b, &antigo);
        DialogEditarProduto editarProduto(d);
        editarProduto.setWindowTitle("Editar Produto");
        editarProduto.setDescricao("Edições");
        editarProduto.show();
        editarProduto.exec();
        //adiciono a nova compra na interface e na lista de compras
        ui->treeViewProdutos->model()->removeRow(selected2.row(), selected2.parent());
        adicionarProduto(b,d);
    }
}

void MainWindow::on_treeViewProdutos_doubleClicked(const QModelIndex &index)
{
    emit on_treeViewProdutos_clicked(index);

    if(index.parent() == model2->invisibleRootItem()->index()){
        return;
    }else{
        Produto ** p;
        Produto *p2;
        p=&p2;
        qDebug() << "Temntando carregar o produto";
        carregaProdutoSelecionado(p);

        if(p2 == NULL)
            return;
        ViewProduto viewProduto(*p2);
        viewProduto.show();
        viewProduto.exec();
    }
}
