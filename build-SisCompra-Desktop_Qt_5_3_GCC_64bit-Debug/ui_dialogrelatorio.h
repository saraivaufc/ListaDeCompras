/********************************************************************************
** Form generated from reading UI file 'dialogrelatorio.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGRELATORIO_H
#define UI_DIALOGRELATORIO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <mywidget.h>

QT_BEGIN_NAMESPACE

class Ui_DialogRelatorio
{
public:
    QVBoxLayout *verticalLayout;
    MyWidget *widgetToPrint;
    QVBoxLayout *verticalLayout_2;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *buttonSalvar;
    QPushButton *buttonFechar;

    void setupUi(QDialog *DialogRelatorio)
    {
        if (DialogRelatorio->objectName().isEmpty())
            DialogRelatorio->setObjectName(QStringLiteral("DialogRelatorio"));
        DialogRelatorio->resize(719, 499);
        verticalLayout = new QVBoxLayout(DialogRelatorio);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        widgetToPrint = new MyWidget(DialogRelatorio);
        widgetToPrint->setObjectName(QStringLiteral("widgetToPrint"));
        verticalLayout_2 = new QVBoxLayout(widgetToPrint);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        tableView = new QTableView(widgetToPrint);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

        verticalLayout_2->addWidget(tableView);


        verticalLayout->addWidget(widgetToPrint);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        buttonSalvar = new QPushButton(DialogRelatorio);
        buttonSalvar->setObjectName(QStringLiteral("buttonSalvar"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(buttonSalvar->sizePolicy().hasHeightForWidth());
        buttonSalvar->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(buttonSalvar);

        buttonFechar = new QPushButton(DialogRelatorio);
        buttonFechar->setObjectName(QStringLiteral("buttonFechar"));
        sizePolicy.setHeightForWidth(buttonFechar->sizePolicy().hasHeightForWidth());
        buttonFechar->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(buttonFechar);

        horizontalLayout->setStretch(0, 5);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 1);

        verticalLayout->addLayout(horizontalLayout);

        verticalLayout->setStretch(0, 10);
        verticalLayout->setStretch(1, 1);

        retranslateUi(DialogRelatorio);

        QMetaObject::connectSlotsByName(DialogRelatorio);
    } // setupUi

    void retranslateUi(QDialog *DialogRelatorio)
    {
        DialogRelatorio->setWindowTitle(QApplication::translate("DialogRelatorio", "Dialog", 0));
        buttonSalvar->setText(QApplication::translate("DialogRelatorio", "Salvar", 0));
        buttonFechar->setText(QApplication::translate("DialogRelatorio", "Fechar", 0));
    } // retranslateUi

};

namespace Ui {
    class DialogRelatorio: public Ui_DialogRelatorio {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGRELATORIO_H
