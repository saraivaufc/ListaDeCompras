#ifndef DIALOGEDITARPRODUTO_H
#define DIALOGEDITARPRODUTO_H

#include <QDialog>
#include "produto.h"

namespace Ui {
class DialogEditarProduto;
}

class DialogEditarProduto : public QDialog {
    Q_OBJECT

public:
    explicit DialogEditarProduto(Produto* prod, QWidget *parent = 0);
    ~DialogEditarProduto();
    bool acepted;
    void setDescricao(QString text);

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::DialogEditarProduto *ui;
    Produto* produto;
};

#endif // DIALOGEDITARPRODUTO_H
