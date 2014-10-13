#include "viewcompra.h"
#include "ui_viewcompra.h"

ViewCompra::ViewCompra(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewCompra)
{
    ui->setupUi(this);
}

ViewCompra::ViewCompra(Compra *c, QWidget *parent):
QDialog(parent),
ui(new Ui::ViewCompra)
{
    ui->setupUi(this);
    ui->labelNome->setText(c->getTitulo());
    ui->labelData->setText(c->getData().toString());
    ui->labelValorTotal->setText(QString::number(c->getValorTotal()));
}

ViewCompra::~ViewCompra()
{
    delete ui;
}
