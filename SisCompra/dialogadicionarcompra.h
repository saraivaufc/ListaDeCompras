#ifndef DIALOGADICIONARCOMPRA_H
#define DIALOGADICIONARCOMPRA_H

#include <QDialog>
#include <QString>
#include <QDate>

namespace Ui {
class DialogAdicionarCompra;
}

class DialogAdicionarCompra : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAdicionarCompra(QWidget *parent = 0);
    ~DialogAdicionarCompra();

public:
    QString getNomeCompra();
    QDate getDataCompra();
    void limparTudo();


private:
    Ui::DialogAdicionarCompra *ui;
};

#endif // DIALOGADICIONARCOMPRA_H
