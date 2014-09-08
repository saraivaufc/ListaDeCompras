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

private slots:
    void on_buttonBox_accepted();

private:
    Ui::DialogEditarCompra *ui;

    Compra* compra;

};

#endif // DIALOGEDITARCOMPRA_H