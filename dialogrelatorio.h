#ifndef DIALOGRELATORIO_H
#define DIALOGRELATORIO_H

#include <QDialog>
#include <QPainter>
#include <QPaintEngine>
#include <QPrinter>
#include <QPixmap>
#include <QFileDialog>
#include <QStandardItemModel>

namespace Ui {
class DialogRelatorio;
}

class DialogRelatorio : public QDialog {
    Q_OBJECT

public:
    explicit DialogRelatorio(QWidget *parent = 0);
    ~DialogRelatorio();

    void setLabel(QString);
    void setHorizontalHeaderSize(int);
    void setModel(QStandardItemModel*);

private slots:
    void on_buttonSalvar_clicked();
    void on_buttonFechar_clicked();

private:
    Ui::DialogRelatorio *ui;
    QPixmap getPixmapFromWidget();
    QString fileFormat;

    void preencherRelatorio();

};

#endif // DIALOGRELATORIO_H
