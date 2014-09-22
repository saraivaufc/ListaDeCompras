#include "dialogconfirmacao.h"
#include "ui_dialogconfirmacao.h"

DialogConfirmacao::DialogConfirmacao(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogConfirmacao)
{
    ui->setupUi(this);
}

DialogConfirmacao::DialogConfirmacao(QString pergunta, QWidget *parent):
    QDialog(parent),
    ui(new Ui::DialogConfirmacao)
{
    ui->setupUi(this);
    ui->labelMenssagem->setText(pergunta);
}

DialogConfirmacao::~DialogConfirmacao()
{
    delete ui;
}

void DialogConfirmacao::on_buttonBox_accepted()
{
    acepted=true;
}

void DialogConfirmacao::on_buttonBox_rejected()
{
    acepted=false;
}
