#ifndef VIEWCOMPRA_H
#define VIEWCOMPRA_H

#include <QDialog>
#include "compra.h"s

namespace Ui {
class ViewCompra;
}

class ViewCompra : public QDialog
{
    Q_OBJECT

public:
    explicit ViewCompra(QWidget *parent = 0);
    ViewCompra(Compra * c, QWidget *parent = 0);
    ~ViewCompra();
    bool acepted;

private slots:

private:
    Ui::ViewCompra *ui;
};

#endif // VIEWCOMPRA_H
