#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include "compra.h"
#include <QDebug>

#include "dialogeditarcompra.h"
#include "dialogeditarproduto.h"

#include "gerenciadordearquivos.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QStandardItemModel* model;
    QList<QStandardItem *> compraToItemList(QString titulo,
                                            QDate data);

private:
    Ui::MainWindow *ui;
    QStandardItemModel listaDeCompras;
    QStandardItemModel listaDeProdutos;


public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void closeEvent (QCloseEvent *event);

signals:
    void addCompra(Compra* c);
    void close();
    void inicializada();


public slots:
    void atualizarCompras();

private slots:
    void on_actionSair_triggered();
    void on_adicionarCompra_clicked();

public:
    void adicionarCompra(Compra * c);
    void carregarCompras();
};

#endif // MAINWINDOW_H
