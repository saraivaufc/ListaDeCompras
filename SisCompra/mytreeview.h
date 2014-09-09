#ifndef MYTREEVIEW_H
#define MYTREEVIEW_H

#include <QMouseEvent>
#include <QTreeView>

class MyTreeView : public QTreeView {
    Q_OBJECT
public:
    MyTreeView(QWidget* parent);


protected:
    void mousePressEvent(QMouseEvent * event);

signals:
    void mouseClicked();

};

#endif // MYTREEVIEW_H
