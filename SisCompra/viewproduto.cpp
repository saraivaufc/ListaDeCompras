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
    ui->labelNomeProduto->setText(p.getNome());
    ui->lineEditQuantidade->setText(QString::number(p.getQuantidade()));
    ui->lineEditValorUnitario->setText(QString::number(p.getValorUnit()));
    ui->lineEditClasse->setText(p.getClass());
    ui->lineEditvalorTotal->setText(QString::number(p.getValorTotal()));
}

ViewProduto::~ViewProduto()
{
    delete ui;
}
