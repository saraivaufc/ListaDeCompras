/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <mytreeview.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSair;
    QAction *actionAdd;
    QAction *actionRemove;
    QAction *actionEdit;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_6;
    QSplitter *splitter;
    QFrame *frame;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_3;
    QLabel *labelCompras;
    MyTreeView *treeViewCompras;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QLabel *labelProdutos;
    MyTreeView *treeViewProdutos;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuMenu;
    QMenu *menuEditar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(602, 441);
        QIcon icon;
        icon.addFile(QStringLiteral(":/imagens/icones/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionSair = new QAction(MainWindow);
        actionSair->setObjectName(QStringLiteral("actionSair"));
        actionAdd = new QAction(MainWindow);
        actionAdd->setObjectName(QStringLiteral("actionAdd"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/imagens/icones/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAdd->setIcon(icon1);
        actionRemove = new QAction(MainWindow);
        actionRemove->setObjectName(QStringLiteral("actionRemove"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/imagens/icones/remove.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRemove->setIcon(icon2);
        actionEdit = new QAction(MainWindow);
        actionEdit->setObjectName(QStringLiteral("actionEdit"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/imagens/icones/edit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionEdit->setIcon(icon3);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        centralWidget->setFont(font);
        verticalLayout_6 = new QVBoxLayout(centralWidget);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(15, 0, 15, 0);
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(splitter->sizePolicy().hasHeightForWidth());
        splitter->setSizePolicy(sizePolicy);
        splitter->setOrientation(Qt::Horizontal);
        frame = new QFrame(splitter);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Raised);
        frame->setLineWidth(0);
        verticalLayout_5 = new QVBoxLayout(frame);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        labelCompras = new QLabel(frame);
        labelCompras->setObjectName(QStringLiteral("labelCompras"));
        QFont font1;
        font1.setPointSize(14);
        labelCompras->setFont(font1);

        verticalLayout_3->addWidget(labelCompras);

        treeViewCompras = new MyTreeView(frame);
        treeViewCompras->setObjectName(QStringLiteral("treeViewCompras"));
        treeViewCompras->setSortingEnabled(true);
        treeViewCompras->setAnimated(false);
        treeViewCompras->setHeaderHidden(true);
        treeViewCompras->header()->setVisible(false);

        verticalLayout_3->addWidget(treeViewCompras);

        verticalLayout_3->setStretch(1, 6);

        verticalLayout_5->addLayout(verticalLayout_3);

        splitter->addWidget(frame);
        frame_2 = new QFrame(splitter);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setFrameShape(QFrame::NoFrame);
        frame_2->setFrameShadow(QFrame::Raised);
        frame_2->setLineWidth(0);
        verticalLayout_4 = new QVBoxLayout(frame_2);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        labelProdutos = new QLabel(frame_2);
        labelProdutos->setObjectName(QStringLiteral("labelProdutos"));
        labelProdutos->setFont(font1);

        verticalLayout_2->addWidget(labelProdutos);

        treeViewProdutos = new MyTreeView(frame_2);
        treeViewProdutos->setObjectName(QStringLiteral("treeViewProdutos"));
        treeViewProdutos->setMouseTracking(true);
        treeViewProdutos->setAcceptDrops(true);
        treeViewProdutos->setEditTriggers(QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed);
        treeViewProdutos->header()->setVisible(false);
        treeViewProdutos->header()->setCascadingSectionResizes(true);
        treeViewProdutos->header()->setProperty("showSortIndicator", QVariant(false));

        verticalLayout_2->addWidget(treeViewProdutos);

        verticalLayout_2->setStretch(1, 6);

        verticalLayout_4->addLayout(verticalLayout_2);

        splitter->addWidget(frame_2);

        verticalLayout_6->addWidget(splitter);

        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setIconSize(QSize(32, 32));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 602, 28));
        menuMenu = new QMenu(menuBar);
        menuMenu->setObjectName(QStringLiteral("menuMenu"));
        menuEditar = new QMenu(menuBar);
        menuEditar->setObjectName(QStringLiteral("menuEditar"));
        MainWindow->setMenuBar(menuBar);

        mainToolBar->addAction(actionAdd);
        mainToolBar->addAction(actionRemove);
        mainToolBar->addAction(actionEdit);
        menuBar->addAction(menuMenu->menuAction());
        menuBar->addAction(menuEditar->menuAction());
        menuMenu->addAction(actionSair);
        menuEditar->addAction(actionAdd);
        menuEditar->addAction(actionRemove);
        menuEditar->addAction(actionEdit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Compras F\303\241cil", 0));
        actionSair->setText(QApplication::translate("MainWindow", "Sair", 0));
        actionAdd->setText(QApplication::translate("MainWindow", "Adicionar", 0));
        actionRemove->setText(QApplication::translate("MainWindow", "Remover", 0));
        actionEdit->setText(QApplication::translate("MainWindow", "Editar", 0));
        labelCompras->setText(QApplication::translate("MainWindow", "Compras", 0));
        labelProdutos->setText(QApplication::translate("MainWindow", "Produtos", 0));
        menuMenu->setTitle(QApplication::translate("MainWindow", "Menu", 0));
        menuEditar->setTitle(QApplication::translate("MainWindow", "Editar", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
