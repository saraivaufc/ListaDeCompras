#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPrinter>
#include <QPaintEvent>
#include <QPaintEngine>

class MyWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyWidget(QWidget *parent = 0);

private:
    QPrinter* printer;

protected:
    void paintEvent(QPaintEvent *);

signals:

public slots:

};

#endif // MYWIDGET_H
