#include "dialogeditarcompra.h"
#include "ui_dialogeditarcompra.h"

DialogEditarCompra::DialogEditarCompra(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogEditarCompra)
{
    ui->setupUi(this);
}

DialogEditarCompra::~DialogEditarCompra()
{
    delete ui;
}
