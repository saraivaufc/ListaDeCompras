#include "dialogadicionarcompra.h"
#include "ui_dialogadicionarcompra.h"

DialogAdicionarCompra::DialogAdicionarCompra(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAdicionarCompra)
{
    ui->setupUi(this);
}

DialogAdicionarCompra::~DialogAdicionarCompra()
{
    delete ui;
}

QString DialogAdicionarCompra::getNomeCompra()
{
    return ui->lineEditNomeCompra->text();
}

QDate DialogAdicionarCompra::getDataCompra()
{
    return ui->dateEditDataCompra->date();
}

void DialogAdicionarCompra::limparTudo()
{
    ui->lineEditNomeCompra->clear();
    ui->dateEditDataCompra->clear();
}
