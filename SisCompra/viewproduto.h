#ifndef VIEWPRODUTO_H
#define VIEWPRODUTO_H

#include <QDialog>
#include "produto.h"
#include <QDebug>

namespace Ui {
class ViewProduto;
}

class ViewProduto : public QDialog
{
    Q_OBJECT

public:
    explicit ViewProduto(QWidget *parent = 0);
    ViewProduto(Produto p,QWidget *parent = 0);
    ~ViewProduto();

private:
    Ui::ViewProduto *ui;
};

#endif // VIEWPRODUTO_H
