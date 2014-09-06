#include "dialogeditarcompra.h"
#include "ui_dialogeditarcompra.h"

DialogEditarCompra::DialogEditarCompra(Compra* c, QWidget *parent) : QDialog(parent), ui(new Ui::DialogEditarCompra) {
    ui->setupUi(this);

    this->compra = c;

    ui->lineEditTitulo->setText(compra->getTitulo());
    ui->dateEdit->setDate(c->getData());
}

DialogEditarCompra::~DialogEditarCompra() {
    delete ui;
}

void DialogEditarCompra::on_buttonBox_accepted() {
    compra->setTitulo(ui->lineEditTitulo->text());
    compra->setData(ui->dateEdit->date());
}
