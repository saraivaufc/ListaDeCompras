#include "mywidget.h"
#include <QDebug>
#include <QPainterPath>


MyWidget::MyWidget(QWidget *parent) : QWidget(parent) {
    printer = new QPrinter;
    printer->setOutputFileName("caminho.pdf");
    printer->setOutputFormat(QPrinter::PdfFormat);
}

void MyWidget::paintEvent(QPaintEvent *event) {
    QWidget::paintEvent(event);
}
