/********************************************************************************
** Form generated from reading UI file 'dialogeditarcompra.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGEDITARCOMPRA_H
#define UI_DIALOGEDITARCOMPRA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogEditarCompra
{
public:
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEditTitulo;
    QDateEdit *dateEdit;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DialogEditarCompra)
    {
        if (DialogEditarCompra->objectName().isEmpty())
            DialogEditarCompra->setObjectName(QStringLiteral("DialogEditarCompra"));
        DialogEditarCompra->resize(400, 300);
        verticalLayout_4 = new QVBoxLayout(DialogEditarCompra);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_3 = new QLabel(DialogEditarCompra);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_3->addWidget(label_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(DialogEditarCompra);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(DialogEditarCompra);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        lineEditTitulo = new QLineEdit(DialogEditarCompra);
        lineEditTitulo->setObjectName(QStringLiteral("lineEditTitulo"));

        verticalLayout_2->addWidget(lineEditTitulo);

        dateEdit = new QDateEdit(DialogEditarCompra);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));

        verticalLayout_2->addWidget(dateEdit);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        buttonBox = new QDialogButtonBox(DialogEditarCompra);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_3->addWidget(buttonBox);

        verticalLayout_3->setStretch(0, 1);
        verticalLayout_3->setStretch(1, 5);
        verticalLayout_3->setStretch(2, 5);
        verticalLayout_3->setStretch(3, 1);

        verticalLayout_4->addLayout(verticalLayout_3);


        retranslateUi(DialogEditarCompra);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogEditarCompra, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogEditarCompra, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogEditarCompra);
    } // setupUi

    void retranslateUi(QDialog *DialogEditarCompra)
    {
        DialogEditarCompra->setWindowTitle(QApplication::translate("DialogEditarCompra", "Dialog", 0));
        label_3->setText(QApplication::translate("DialogEditarCompra", "Informa\303\247\303\265es da compra", 0));
        label->setText(QApplication::translate("DialogEditarCompra", "T\303\255tulo", 0));
        label_2->setText(QApplication::translate("DialogEditarCompra", "Data", 0));
    } // retranslateUi

};

namespace Ui {
    class DialogEditarCompra: public Ui_DialogEditarCompra {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGEDITARCOMPRA_H
