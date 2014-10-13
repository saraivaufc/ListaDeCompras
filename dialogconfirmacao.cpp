<<<<<<< HEAD
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

void DialogConfirmacao::setText(QString str)
{
    ui->labelMenssagem->setText(str);
}

void DialogConfirmacao::on_buttonBox_accepted()
{
    acepted=true;
}

void DialogConfirmacao::on_buttonBox_rejected()
{
    acepted=false;
}
=======
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

void DialogConfirmacao::setText(QString str)
{
    ui->labelMenssagem->setText(str);
}

void DialogConfirmacao::on_buttonBox_accepted()
{
    acepted=true;
}

void DialogConfirmacao::on_buttonBox_rejected()
{
    acepted=false;
}
>>>>>>> 39f381eefdb8a8c2d1c947ccd6862df2067ef649
