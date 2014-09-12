#-------------------------------------------------
#
# Project created by QtCreator 2014-09-11T20:45:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Instalador
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    filemanager.cpp

HEADERS  += mainwindow.h \
    filemanager.h \
    macros.h

FORMS    += mainwindow.ui

RESOURCES += \
    source.qrc
