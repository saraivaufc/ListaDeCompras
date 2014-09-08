#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include "compra.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QStandardItemModel listaDeCompras;
    QStandardItemModel listaDeProdutos;


public:
    void adicionaCompra(Compra * compra);

};

#endif // MAINWINDOW_H
