#include "dialogeditarproduto.h"
#include "ui_dialogeditarproduto.h"

DialogEditarProduto::DialogEditarProduto(Produto* prod, QWidget *parent) : QDialog(parent), ui(new Ui::DialogEditarProduto) {
    ui->setupUi(this);

    produto = prod;

    ui->lineEditNome->setText(produto->getNome());
    ui->spinBoxQuant->setValue(produto->getQuantidade());
    ui->doubleSpinBoxValor->setValue(produto->getValorUnit());

    ui->comboBox->addItem("Limpeza");
    ui->comboBox->addItem("Alimentar");
    ui->comboBox->addItem("Utensílio");
}

DialogEditarProduto::~DialogEditarProduto() {
    delete ui;
}

void DialogEditarProduto::setDescricao(QString text)
{
    ui->label_4->setText(text);
}

void DialogEditarProduto::on_buttonBox_accepted() {
    produto->setNome(ui->lineEditNome->text());
    produto->setQuantidade(ui->spinBoxQuant->value());
    produto->setValorUnit(ui->doubleSpinBoxValor->value());
    produto->setClasse(ui->comboBox->currentText());
    acepted = true;
}

void DialogEditarProduto::on_buttonBox_rejected() {
    acepted = false;
}
