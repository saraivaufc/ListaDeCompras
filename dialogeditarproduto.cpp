#include "dialogeditarproduto.h"
#include "ui_dialogeditarproduto.h"

DialogEditarProduto::DialogEditarProduto(Produto* prod, QWidget *parent) : QDialog(parent), ui(new Ui::DialogEditarProduto) {
    ui->setupUi(this);

    produto = prod;

    ui->lineEditNome->setText(produto->getNome());
    ui->spinBoxQuant->setValue(produto->getQuantidade());
    ui->doubleSpinBoxValor->setValue(produto->getValorUnit());

    ui->comboBox->addItem("LIMPESA");
    ui->comboBox->addItem("COMIDA");
    ui->comboBox->addItem("UTENSILIOS");
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
    produto->setClasse(stringToClasse(ui->comboBox->currentText()));
    if(ui->lineEditNome->text().isEmpty()){
        QMessageBox msn;
        msn.setText("Por favor, digite o nome do produto e tente novamente...");
        msn.show();
        msn.exec();
        acepted=false;
    }else{
        acepted = true;
    }
}

void DialogEditarProduto::on_buttonBox_rejected() {
    acepted = false;
}
