#include "dialogeditarcompra.h"
#include "ui_dialogeditarcompra.h"

DialogEditarCompra::DialogEditarCompra(Compra* c, QWidget *parent) : QDialog(parent), ui(new Ui::DialogEditarCompra) {
    ui->setupUi(this);
    this->compra = c;

    ui->lineEditTitulo->setText(compra->getTitulo());
    ui->dateEdit->setDate(c->getData());

    acepted = false;
}

DialogEditarCompra::~DialogEditarCompra() {
    delete ui;
}

void DialogEditarCompra::setDescricao(QString text)
{
    ui->label_3->setText(text);
}

void DialogEditarCompra::on_buttonBox_accepted() {
    GerenciadorDeArquivos::removeCompra(compra);
    compra->setTitulo(ui->lineEditTitulo->text());
    compra->setData(ui->dateEdit->date());
    if(ui->lineEditTitulo->text().isEmpty()){
        QMessageBox msn;
        msn.setText("Por favor, digite um titulo e tente novamente...");
        msn.show();
        msn.exec();
    }else{
        GerenciadorDeArquivos::salvarCompra(compra);
        acepted= true;
    }
}

QString DialogEditarCompra::getTitulo() {
    return ui->lineEditTitulo->text();
}

QDate DialogEditarCompra::getData()
{
    return ui->dateEdit->date();
}

void DialogEditarCompra::on_buttonBox_rejected() {
    acepted = false;
}
