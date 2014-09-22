#include <iostream>
#include "controladordosistema.h"
#include <QApplication>

using namespace std;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    //new ControladorDoSistema();

    DialogRelatorio dr;
    dr.show();
    dr.exec();

    return a.exec();
}
