#ifndef DIALOGCONFIRMACAO_H
#define DIALOGCONFIRMACAO_H

#include <QDialog>

namespace Ui {
class DialogConfirmacao;
}

class DialogConfirmacao : public QDialog
{
    Q_OBJECT

public:
    explicit DialogConfirmacao(QWidget *parent = 0);
    DialogConfirmacao( QString pergunta, QWidget *parent=0);
    ~DialogConfirmacao();
    bool acepted;
    void setText(QString str);

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
    Ui::DialogConfirmacao *ui;
};

#endif // DIALOGCONFIRMACAO_H
