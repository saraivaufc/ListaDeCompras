#include "mainwindow.h"
#include "filemanager.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();


    FileManager::createDothDesktop();

    exit(0);
    return a.exec();
}
