#ifndef DIALOGEDITARCOMPRA_H
#define DIALOGEDITARCOMPRA_H

#include <QDialog>
#include "compra.h"

namespace Ui {
class DialogEditarCompra;
}

class DialogEditarCompra : public QDialog {
    Q_OBJECT

public:
    explicit DialogEditarCompra(Compra* c, QWidget *parent = 0);
    ~DialogEditarCompra();
    bool acepted;

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::DialogEditarCompra *ui;

    Compra* compra;

public:
    QString getTitulo();
    QDate getData();

};

#endif // DIALOGEDITARCOMPRA_H
