#include <iostream>
#include "controladordosistema.h"
#include <QApplication>

using namespace std;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    ControladorDoSistema();
    return a.exec();
}
