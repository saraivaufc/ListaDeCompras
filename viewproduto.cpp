#include "viewproduto.h"
#include "ui_viewproduto.h"

ViewProduto::ViewProduto(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewProduto)
{
    ui->setupUi(this);
}

ViewProduto::ViewProduto(Produto p, QWidget *parent): QDialog(parent), ui(new Ui::ViewProduto)
{
    ui->setupUi(this);
    qDebug() << p.toString();
    ui->labelNomeProduto->setText(p.getNome());
    ui->labelQuantidade->setText(QString::number(p.getQuantidade()));
    ui->labelValorUnitario->setText(QString::number(p.getValorUnit()));
    ui->labelClasse->setText(classeToString(p.getClass()));
    ui->labelValorTotal->setText(QString::number(p.getValorTotal()));
}

ViewProduto::~ViewProduto()
{
    delete ui;
}
