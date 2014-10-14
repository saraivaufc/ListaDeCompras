#include <QDebug>
#include "mytreeview.h"

MyTreeView::MyTreeView(QWidget* parent = 0) : QTreeView(parent){
}

void MyTreeView::mousePressEvent(QMouseEvent *event) {
    QTreeView::mousePressEvent(event);
    emit mouseClicked();
}
