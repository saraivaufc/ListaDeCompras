#ifndef DIALOGEDITARCOMPRA_H
#define DIALOGEDITARCOMPRA_H

#include <QDialog>

namespace Ui {
class DialogEditarCompra;
}

class DialogEditarCompra : public QDialog
{
    Q_OBJECT

public:
    explicit DialogEditarCompra(QWidget *parent = 0);
    ~DialogEditarCompra();

private:
    Ui::DialogEditarCompra *ui;
};

#endif // DIALOGEDITARCOMPRA_H
