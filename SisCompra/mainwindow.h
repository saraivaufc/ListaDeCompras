#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QTreeView>
#include "compra.h"
#include <QDebug>
#include <QDate>

#include "dialogeditarcompra.h"
#include "dialogeditarproduto.h"

#include "gerenciadordearquivos.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    enum TypeView{COMPRAS, PRODUTO};

    TypeView typeView;
    Ui::MainWindow *ui;
    QStandardItemModel listaDeCompras;
    QStandardItemModel listaDeProdutos;
    QStandardItemModel* model;
    QStandardItemModel* model2;

    QModelIndex selected;
    QModelIndex selected2;

    QList<QStandardItem *> compraToItemList(QString titulo,
                                            QDate data);

    QList<QStandardItem *> produtoToItemList(QString nome,
                                             float valor,
                                             int qtd,
                                             QString classe);

protected:
    void closeEvent (QCloseEvent *event);

signals:
    void addCompra(Compra* c);
    void addProduto(Compra * c, Produto *p);

    void close();
    void inicializada();

    void existeCompra(Compra *c, bool *existe);
    void existeProduto(Compra * c,Produto *p, bool *existe);
    void removeCompra(Compra * c);
    void removeComprasPorData(QString data);

    void buscaCompra(Compra **c, QString nome, QDate data);


public slots:
    void atualizarCompras();
    void on_actionSair_triggered();
    void on_actionAdd_triggered();

    //muda a view selecionada
    void treeViewCompras_clicked();
    void treeViewProdutos_clicked();

    void on_treeViewCompras_clicked(const QModelIndex &index);

    void on_actionRemove_triggered();

public:
    void carregarCompras();
    void adicionarCompra(Compra *c);
    void adicionarProduto(Compra *c, Produto *p);
    void listaProdutosVisivel(bool estado);
    void listaComprasVisivel(bool estado);
private slots:
    void on_treeViewProdutos_clicked(const QModelIndex &index);
};

#endif // MAINWINDOW_H
