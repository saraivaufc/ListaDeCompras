#-------------------------------------------------
#
# Project created by QtCreator 2014-09-03T20:28:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SisCompra
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    gerenciadordecompras.cpp \
    dialogeditarcompra.cpp \
    dialogeditarproduto.cpp \
    compra.cpp \
    produto.cpp \
    gerenciadordearquivos.cpp \
    controladordosistema.cpp \
    mytreeview.cpp \
    viewproduto.cpp

HEADERS  += mainwindow.h \
    gerenciadordecompras.h \
    dialogeditarcompra.h \
    dialogeditarproduto.h \
    compra.h \
    produto.h \
    Macros.h \
    gerenciadordearquivos.h \
    controladordosistema.h \
    mytreeview.h \
    viewproduto.h

FORMS    += mainwindow.ui \
    dialogeditarcompra.ui \
    dialogeditarproduto.ui \
    viewproduto.ui

RESOURCES += \
    Imagens.qrc
