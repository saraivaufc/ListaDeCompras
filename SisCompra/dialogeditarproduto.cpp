#include "dialogeditarproduto.h"
#include "ui_dialogeditarproduto.h"

DialogEditarProduto::DialogEditarProduto(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogEditarProduto)
{
    ui->setupUi(this);
}

DialogEditarProduto::~DialogEditarProduto()
{
    delete ui;
}
