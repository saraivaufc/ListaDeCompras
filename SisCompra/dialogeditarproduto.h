#ifndef DIALOGEDITARPRODUTO_H
#define DIALOGEDITARPRODUTO_H

#include <QDialog>

namespace Ui {
class DialogEditarProduto;
}

class DialogEditarProduto : public QDialog
{
    Q_OBJECT

public:
    explicit DialogEditarProduto(QWidget *parent = 0);
    ~DialogEditarProduto();

private:
    Ui::DialogEditarProduto *ui;
};

#endif // DIALOGEDITARPRODUTO_H
