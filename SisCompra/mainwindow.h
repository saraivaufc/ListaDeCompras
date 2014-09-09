#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QTreeView>
#include "compra.h"
#include <QDebug>

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

    QList<QStandardItem *> compraToItemList(QString titulo,
                                            QDate data);

protected:
    void closeEvent (QCloseEvent *event);

signals:
    void addCompra(Compra* c);
    void close();
    void inicializada();
    void existeCompra(Compra *c, bool *existe);


public slots:
    void atualizarCompras();

private slots:
    void on_actionSair_triggered();
    void on_actionAdd_triggered();

    //muda a view selecionada
    void treeViewCompras_clicked();
    void treeViewProdutos_clicked();


public:
    void carregarCompras();
    void adicionarCompra(Compra *c);
};

#endif // MAINWINDOW_H
