#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include "compra.h"
#include <QDebug>

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


public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


signals:
    void addCompra();

private:
    Ui::MainWindow *ui;
    GerenciadorDeArquivos * gerenciadorArquivos;


    QStandardItemModel listaDeCompras;
    QStandardItemModel listaDeProdutos;

public slots:
    void atualizarCompras();


private slots:
    void on_adicionarCompra_clicked();

    void on_actionSair_triggered();

public:
    void adicionarCompra(Compra c);
    void loadCompras();

};

#endif // MAINWINDOW_H
