/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_Conta;
    QAction *actionAdicionar_Produto;
    QAction *actionEditar_Compra;
    QAction *actionEditar_Produto;
    QAction *actionSair;
    QAction *actionCompra;
    QAction *actionProduto;
    QAction *actionCompra_2;
    QAction *actionProdut;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_6;
    QSplitter *splitter;
    QFrame *frame;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_3;
    QTreeView *treeViewCompras;
    QWidget *widgetCompra;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *adicionarCompra;
    QPushButton *excluirCompra;
    QPushButton *editarCompra;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QTreeView *treeViewProdutos;
    QWidget *widgetProduto;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *adicionarProduto;
    QPushButton *excluirProduto;
    QPushButton *editarProduto;
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
        action_Conta = new QAction(MainWindow);
        action_Conta->setObjectName(QStringLiteral("action_Conta"));
        actionAdicionar_Produto = new QAction(MainWindow);
        actionAdicionar_Produto->setObjectName(QStringLiteral("actionAdicionar_Produto"));
        actionEditar_Compra = new QAction(MainWindow);
        actionEditar_Compra->setObjectName(QStringLiteral("actionEditar_Compra"));
        actionEditar_Produto = new QAction(MainWindow);
        actionEditar_Produto->setObjectName(QStringLiteral("actionEditar_Produto"));
        actionSair = new QAction(MainWindow);
        actionSair->setObjectName(QStringLiteral("actionSair"));
        actionCompra = new QAction(MainWindow);
        actionCompra->setObjectName(QStringLiteral("actionCompra"));
        actionProduto = new QAction(MainWindow);
        actionProduto->setObjectName(QStringLiteral("actionProduto"));
        actionCompra_2 = new QAction(MainWindow);
        actionCompra_2->setObjectName(QStringLiteral("actionCompra_2"));
        actionProdut = new QAction(MainWindow);
        actionProdut->setObjectName(QStringLiteral("actionProdut"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_6 = new QVBoxLayout(centralWidget);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
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
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_5 = new QVBoxLayout(frame);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        treeViewCompras = new QTreeView(frame);
        treeViewCompras->setObjectName(QStringLiteral("treeViewCompras"));

        verticalLayout_3->addWidget(treeViewCompras);

        widgetCompra = new QWidget(frame);
        widgetCompra->setObjectName(QStringLiteral("widgetCompra"));
        verticalLayout = new QVBoxLayout(widgetCompra);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        adicionarCompra = new QPushButton(widgetCompra);
        adicionarCompra->setObjectName(QStringLiteral("adicionarCompra"));
        QSizePolicy sizePolicy1(QSizePolicy::Ignored, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(adicionarCompra->sizePolicy().hasHeightForWidth());
        adicionarCompra->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(adicionarCompra);

        excluirCompra = new QPushButton(widgetCompra);
        excluirCompra->setObjectName(QStringLiteral("excluirCompra"));
        sizePolicy1.setHeightForWidth(excluirCompra->sizePolicy().hasHeightForWidth());
        excluirCompra->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(excluirCompra);

        editarCompra = new QPushButton(widgetCompra);
        editarCompra->setObjectName(QStringLiteral("editarCompra"));
        sizePolicy1.setHeightForWidth(editarCompra->sizePolicy().hasHeightForWidth());
        editarCompra->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(editarCompra);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_3->addWidget(widgetCompra);


        verticalLayout_5->addLayout(verticalLayout_3);

        splitter->addWidget(frame);
        frame_2 = new QFrame(splitter);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout_4 = new QVBoxLayout(frame_2);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        treeViewProdutos = new QTreeView(frame_2);
        treeViewProdutos->setObjectName(QStringLiteral("treeViewProdutos"));

        verticalLayout_2->addWidget(treeViewProdutos);

        widgetProduto = new QWidget(frame_2);
        widgetProduto->setObjectName(QStringLiteral("widgetProduto"));
        horizontalLayout_2 = new QHBoxLayout(widgetProduto);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        adicionarProduto = new QPushButton(widgetProduto);
        adicionarProduto->setObjectName(QStringLiteral("adicionarProduto"));
        sizePolicy1.setHeightForWidth(adicionarProduto->sizePolicy().hasHeightForWidth());
        adicionarProduto->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(adicionarProduto);

        excluirProduto = new QPushButton(widgetProduto);
        excluirProduto->setObjectName(QStringLiteral("excluirProduto"));
        sizePolicy1.setHeightForWidth(excluirProduto->sizePolicy().hasHeightForWidth());
        excluirProduto->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(excluirProduto);

        editarProduto = new QPushButton(widgetProduto);
        editarProduto->setObjectName(QStringLiteral("editarProduto"));
        sizePolicy1.setHeightForWidth(editarProduto->sizePolicy().hasHeightForWidth());
        editarProduto->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(editarProduto);


        verticalLayout_2->addWidget(widgetProduto);


        verticalLayout_4->addLayout(verticalLayout_2);

        splitter->addWidget(frame_2);

        verticalLayout_6->addWidget(splitter);

        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
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

        menuBar->addAction(menuMenu->menuAction());
        menuBar->addAction(menuEditar->menuAction());
        menuMenu->addAction(actionSair);
        menuEditar->addAction(actionEditar_Compra);
        menuEditar->addAction(actionEditar_Produto);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        action_Conta->setText(QApplication::translate("MainWindow", "Adicionar Compra", 0));
        actionAdicionar_Produto->setText(QApplication::translate("MainWindow", "Adicionar Produto", 0));
        actionEditar_Compra->setText(QApplication::translate("MainWindow", "Compra", 0));
        actionEditar_Produto->setText(QApplication::translate("MainWindow", "Produto", 0));
        actionSair->setText(QApplication::translate("MainWindow", "Sair", 0));
        actionCompra->setText(QApplication::translate("MainWindow", "Compra", 0));
        actionProduto->setText(QApplication::translate("MainWindow", "Produto", 0));
        actionCompra_2->setText(QApplication::translate("MainWindow", "Compra", 0));
        actionProdut->setText(QApplication::translate("MainWindow", "Produto", 0));
        adicionarCompra->setText(QApplication::translate("MainWindow", "Novo", 0));
        excluirCompra->setText(QApplication::translate("MainWindow", "Excluir", 0));
        editarCompra->setText(QApplication::translate("MainWindow", "Editar", 0));
        adicionarProduto->setText(QApplication::translate("MainWindow", "Novo", 0));
        excluirProduto->setText(QApplication::translate("MainWindow", "Excluir", 0));
        editarProduto->setText(QApplication::translate("MainWindow", "Editar", 0));
        menuMenu->setTitle(QApplication::translate("MainWindow", "Menu", 0));
        menuEditar->setTitle(QApplication::translate("MainWindow", "Editar", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
