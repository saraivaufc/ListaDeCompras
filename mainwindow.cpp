#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QThread>
#include <QDesktopWidget>
#include <cmath>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    //Crio aqui dois modelos
    model = new QStandardItemModel(this);
    model2 = new QStandardItemModel(this);
    ui->treeViewCompras->setModel(model);
    ui->treeViewProdutos->setModel(model2);
    typeView = COMPRAS;
    treeViewCompras_clicked();
    connect(ui->treeViewCompras, SIGNAL(mouseClicked()), this, SLOT(treeViewCompras_clicked()));
    connect(ui->treeViewProdutos, SIGNAL(mouseClicked()), this, SLOT(treeViewProdutos_clicked()));


    //Esquema Designer
    preferedSize = size();
    aW = aH = 10;
    setFixedSize(aW, aH);
    speedW = speedH = 0;
}

MainWindow::~MainWindow() {
    delete ui;
}

Compra *MainWindow::getCompraAtual()
{
    QDate dataCompra = QDate::fromString(model->itemFromIndex(selected.parent())->text(),"dd/MM/yyyy");
    QString nomeCompra = model->itemFromIndex(selected)->text();
    Compra **a=NULL;
    Compra *b=NULL;
    a=&b;
    if(nomeCompra == COMPRACORRENTE){
        emit buscaCompraCorrente(a);
    }else{
        emit buscaCompra(a,nomeCompra,dataCompra);
    }
    return b;
}

Produto *MainWindow::getProdutoAtual()
{
    Compra * c = this->getCompraAtual();

    QString nomeProduto = model2->itemFromIndex(selected2)->text();
    QString classeProduto = model2->itemFromIndex(selected2.parent())->text();
    if(nomeProduto == NULL || classeProduto == NULL){
        return NULL;
    }
    Produto **k;
    Produto *k2;
    k = &k2;
    emit buscaProduto(c,k,nomeProduto, stringToClasse(classeProduto));
    return k2;
}

QList<QStandardItem *> MainWindow::compraToItemList(QString titulo, QDate data) {
    QList<QStandardItem*> res;
    res << new QStandardItem(QIcon(ICON_COMPRA), titulo)
        << new QStandardItem(data.toString());
    return res;
}

QList<QStandardItem *> MainWindow::produtoToItemList(QString nome, float valor, int qtd, ClasseDeProduto classe)
{
    QList<QStandardItem*> res;
    res << new QStandardItem(nome)
        << new QStandardItem(QString::number(valor))
        << new QStandardItem(QString::number(qtd))
        << new QStandardItem(classeToString(classe));
    return res;
}

void MainWindow::adicionarCompra(Compra *c)
{
    if(c->getTitulo() == COMPRACORRENTE){
        adicionarCompraCorrente(c);
        return;
    }


    bool a=false;
    emit existeCompra(c, &a);
    if(a && c->getTitulo() != COMPRACORRENTE ){
        DialogConfirmacao msn("Já existe uma compra com esse nome, deseja substituilá?");
        msn.exec();
        if(msn.acepted){
            emit addCompra(c);
            return;
        }
    }
    emit addCompra(c);


    QStandardItem * root = model->invisibleRootItem();
    QStandardItem *item = NULL;

    QString ch = c->getData().toString("dd/MM/yyyy");
    for(int row=0; row < root->rowCount() ; row++){
        QStandardItem * temp  = root->child(row, 0);
        temp->setEditable(false);
        if(temp->text() == ch){
            temp->appendRow(
                        compraToItemList(
                            c->getTitulo(),
                            c->getData()
                            )
                        );
            on_treeViewCompras_clicked(model->indexFromItem(temp->child(temp->rowCount()-1, 0)));
            return;
        }
    }

    item = new QStandardItem(ch);
    item->setEditable(false);
    root->appendRow(item);
    item->appendRow(compraToItemList(c->getTitulo(), c->getData()));
    on_treeViewCompras_clicked(model->indexFromItem(item->child(item->rowCount()-1, 0)));
    return;
}

void MainWindow::adicionarProduto(Compra *c, Produto *p, bool somenteNaInterface)
{
    if(somenteNaInterface == false){
        emit addProduto(c, p);
    }


    QStandardItem * root2 = model2->invisibleRootItem();
    QString ch = classeToString(p->getClass());

    for(int row=0; row < root2->rowCount() ; row++){
        QStandardItem * item  = root2->child(row, 0);
        item->setEditable(false);
        if(item->text() == ch){
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
    QStandardItem * item = new QStandardItem(QIcon(classeToIcon(p->getClass())), ch);
    item->setEditable(false);
    root2->appendRow(item);

    item->appendRow(produtoToItemList(
                        p->getNome(),
                        p->getQuantidade(),
                        p->getValorUnit(),
                        stringToClasse(ch)
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
void MainWindow::carregarCompras()
{
    QList<Compra *> list = GerenciadorDeArquivos::getAllCompras();
    foreach (Compra * c, list){
        adicionarCompra(c);
    }
    QStandardItem * root = model->invisibleRootItem();
    QStandardItem * item  = root->child(0, 0);
    ui->treeViewCompras->setCurrentIndex(item->child(0,0)->index());
    limparProdutosInterface();
    this->selected = item->child(0,0)->index();
    this->treeViewProdutos_clicked();
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
        emit clearCompraCorrente();
        limparProdutosInterface();
        QStandardItem * root = model->invisibleRootItem();
        QStandardItem * item  = root->child(0, 0)->child(0,0);
        ui->treeViewCompras->setCurrentIndex(item->index());
        return;
    }
    else if(typeView == PRODUTO) {
        if(!compraIsSelected()){
            QMessageBox aviso;
            aviso.setWindowTitle("Aviso!!!");
            aviso.setText("Error!, Favor Selecionar uma Compra...");
            aviso.show();
            aviso.exec();
            return ;
        }
        Produto *p = new Produto;
        DialogEditarProduto editarproduto(p, this);
        editarproduto.setWindowTitle("Adicionar produto");
        editarproduto.setDescricao("Novo Produto");
        editarproduto.exec();
        if(editarproduto.acepted){
            Compra * a = this->getCompraAtual();
            adicionarProduto(a,p);
            return;
        }
    }
}


void MainWindow::on_treeViewCompras_clicked(const QModelIndex &index)
{
    selected = index;
    QStandardItem * root = model->invisibleRootItem();
    ui->treeViewCompras->setCurrentIndex(index);
    limparProdutosInterface();
    //Se eu tiver clicado numa Data, então eu limpo os produtos e saio
    if(index.parent() == root->index()){
        return;
    }

    //Se eu tiver clicado numa compra, eu preciso recarregar os produtos
    QString nomeCompra= model->itemFromIndex(index)->text();
    QDate dataCompra= QDate::fromString(model->itemFromIndex(index.parent())->text(),"dd/MM/yyyy");
    Compra **a;
    Compra *b;
    a=&b;
    if(nomeCompra == COMPRACORRENTE){
        emit buscaCompraCorrente(a);
    }else{
        emit buscaCompra(a,nomeCompra,dataCompra);
    }
    foreach (Produto * p, b->getProdutos()){
        adicionarProduto(b, p, true);
    }

}

void MainWindow::on_treeViewProdutos_clicked(const QModelIndex &index)
{
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
        if(item->text() == COMPRACORRENTE){
            limparProdutosInterface();
            return;
        }
        DialogConfirmacao confirm("Deseja remover essa Compra?");
        confirm.exec();
        if(!confirm.acepted){
            return;
        }
        bool removerPorData = false;
        if(selected.parent() == model->invisibleRootItem()->index()){
            //emite uma sinal para o controlador com a compra que ele quer remover
            emit removeComprasPorData(item->text());
            removerPorData = true;
        }
        if(item->rowCount() == 0){
            Compra c(item->text(), QDate::fromString(item->parent()->text(),"dd/MM/yyyy" ));
            emit removeCompra(&c);
        }
        ui->treeViewCompras->model()->removeRow(selected.row(), selected.parent());
        if(removerPorData){
            Compra * p = new Compra(COMPRACORRENTE);
            adicionarCompraCorrente(p);
        }else{
            limparProdutosInterface();
        }


    }else if(typeView == PRODUTO){

        QStandardItem * item = model->itemFromIndex(selected);
        QStandardItem * item2 = model2->itemFromIndex(selected2);
        if(item == NULL || item2 == NULL){
            return;
        }
        DialogConfirmacao confirm("Deseja remover esse Produto?");
        confirm.exec();
        if(!confirm.acepted){
            return;
        }

        Compra * a = this->getCompraAtual();

        if(selected2.parent() == model2->invisibleRootItem()->index()){
            emit removeProdutoPorClasse(a, stringToClasse(item2->text()));
        }


        if(item2->rowCount() == 0){
            Compra c(item->text(), QDate::fromString(item->parent()->text(),"dd/MM/yyyy" ));
            Produto p(item2->text(),stringToClasse(item2->parent()->text() ));
            emit removeProduto(&c, &p);
        }

        ui->treeViewProdutos->model()->removeRow(selected2.row(), selected2.parent());

    }

}

void MainWindow::updateSize() {
    for(int i = 0; i < 15; i++) {
        double defAscel = 0.2;

        double W = preferedSize.width() - aW;
        double H = preferedSize.height() - aH;

        double D = sqrt(pow(W, 2) + pow(H, 2));

        if(D < 0.01 && speedW < 0.01) {
            D = 0;
            return;
        }

        double ascelW = (W)*defAscel/D;
        double ascelH = (H)*defAscel/D;

        speedW += ascelW;
        speedH += ascelH;

        aW = aW + speedW + ascelW/2;
        aH = aH + speedH + ascelH/2;

        setFixedSize(aW, aH);
        move(QApplication::desktop()->availableGeometry().center() - this->rect().center());

        speedW *= 0.97;
        speedH *= 0.97;
    }
}

void MainWindow::on_actionEdit_triggered() {
    Compra * a = this->getCompraAtual();
    if(a->getTitulo() == COMPRACORRENTE){
        return;
    }

    if(typeView == COMPRAS){

        //se eu tento editar uma data como se fosse uma compra
        if(selected.parent() == model->invisibleRootItem()->index()){
            return;
        }

        //apago a velha compra
        emit removeCompra(a);
        //edito ela
        DialogEditarCompra editarCompra(a);
        editarCompra.exec();
        //adiciono a nova compra na interface e na lista de compras
        ui->treeViewCompras->model()->removeRow(selected.row(), selected.parent());
        if(a->getTitulo() == COMPRACORRENTE){
            adicionarCompraCorrente(a);
        }else{
            adicionarCompra(a);
        }


    }else if(typeView == PRODUTO){

        //se eu tento editar uma data como se fosse uma compra
        if(selected2.parent() == model2->invisibleRootItem()->index()){
            return;
        }

        Produto * b = this->getProdutoAtual();
        if(b == NULL){
            return;
        }
        Produto antigo(b);
        emit removeProduto(a, &antigo);
        DialogEditarProduto editarProduto(b);
        editarProduto.setWindowTitle("Editar Produto");
        editarProduto.setDescricao("Edições");
        editarProduto.exec();
        //adiciono a nova compra na interface e na lista de compras
        ui->treeViewProdutos->model()->removeRow(selected2.row(), selected2.parent());
        adicionarProduto(a,b);
    }
}

void MainWindow::on_treeViewProdutos_doubleClicked(const QModelIndex &index)
{
    emit on_treeViewProdutos_clicked(index);

    if(index.parent() == model2->invisibleRootItem()->index()){
        return;
    }else{
        Produto *p = this->getProdutoAtual();
        if(p == NULL)
            return;
        ViewProduto viewProduto(p);
        viewProduto.exec();
    }
}

void MainWindow::on_treeViewCompras_doubleClicked(const QModelIndex &index)
{
    emit on_treeViewCompras_clicked(index);
    if(index.parent() == model->invisibleRootItem()->index()){
        return;
    }else{
        Compra *c = this->getCompraAtual();
        ViewCompra viewCompra(c);
        viewCompra.exec();
    }
}

void MainWindow::on_actionSalvar_triggered()
{
    Compra *a = this->getCompraAtual();
    if(a->getTitulo() != COMPRACORRENTE){
        GerenciadorDeArquivos::salvarCompra(a);
        return;
    }
    Compra *b = a->clone();
    b->setTitulo(" ");
    DialogEditarCompra editCompra(b);
    editCompra.exec();
    if(editCompra.acepted){
        if(a->getTitulo() != b->getTitulo()){
            adicionarCompra(b);
            emit clearCompraCorrente();
        }else{
        }
    }
}


void MainWindow::adicionarCompraCorrente(Compra *c)
{
    QStandardItem * root = model->invisibleRootItem();
    QString ch = c->getData().toString("dd/MM/yyyy");
    for(int row=0; row < root->rowCount() ; row++){
        QStandardItem * item  = root->child(row, 0);
        item->setEditable(false);
        if(item->text() == ch){
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
    ui->treeViewCompras->setCurrentIndex(item->index());
    return;
}

void MainWindow::on_actionGerar_Relatorio_Mensal_triggered() {
    gerarRelatorio(GerenciadorDeRelatorios::GASTO_MES);
}

void MainWindow::on_actionGerar_Relat_rio_por_Classe_de_Produto_triggered()
{
    gerarRelatorio(GerenciadorDeRelatorios::GASTO_CLASSE);
}

void MainWindow::on_actionGerar_Relat_rio_Mensal_Classe_triggered()
{
    gerarRelatorio(GerenciadorDeRelatorios::GASTO_CLASSE_MES);
}

void MainWindow::on_actionMaiores_Gastos_triggered()
{
    gerarRelatorio(GerenciadorDeRelatorios::GASTO_MAX);
}
