#include "dialogrelatorio.h"
#include "ui_dialogrelatorio.h"
#include <QDebug>

DialogRelatorio::DialogRelatorio(QWidget *parent) : QDialog(parent), ui(new Ui::DialogRelatorio) {
    ui->setupUi(this);
}

DialogRelatorio::~DialogRelatorio()
{
    delete ui;
}

void DialogRelatorio::setModel(QStandardItemModel *m) {
    ui->tableView->setModel(m);
}

QPixmap DialogRelatorio::getPixmapFromWidget() {
    return ui->widgetToPrint->grab();
}

void DialogRelatorio::on_buttonSalvar_clicked() {
    QFileDialog fd(this);
    fd.setWindowTitle("Salvar");
    fd.setNameFilter(tr("PDF Files (*.pdf);;All Files (*.*)"));
    fd.setFileMode(QFileDialog::AnyFile);
    fd.setAcceptMode(QFileDialog::AcceptSave);

    fd.show();
    fd.exec();

    if(!fd.selectedFiles().isEmpty()) {
        QString fileName = fd.selectedFiles().at(0);

        if(!fileName.contains(fileFormat)) {
            fileName += ".pdf";
        }

        qDebug() << fileName;

        QPrinter printer;
        printer.setOutputFileName(fileName);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOrientation(QPrinter::Portrait);

        QPainter painter(&printer);
        ui->widgetToPrint->render(&painter);

        painter.end();
    }
}

void DialogRelatorio::on_buttonFechar_clicked() {
    close();
}
