/********************************************************************************
** Form generated from reading UI file 'dialogadicionarcompra.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGADICIONARCOMPRA_H
#define UI_DIALOGADICIONARCOMPRA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogAdicionarCompra
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEditNomeCompra;
    QDateEdit *dateEditDataCompra;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DialogAdicionarCompra)
    {
        if (DialogAdicionarCompra->objectName().isEmpty())
            DialogAdicionarCompra->setObjectName(QStringLiteral("DialogAdicionarCompra"));
        DialogAdicionarCompra->resize(398, 172);
        verticalLayout_3 = new QVBoxLayout(DialogAdicionarCompra);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(DialogAdicionarCompra);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(17);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        verticalLayout_2->addLayout(verticalLayout);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_2 = new QLabel(DialogAdicionarCompra);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        label_3 = new QLabel(DialogAdicionarCompra);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        lineEditNomeCompra = new QLineEdit(DialogAdicionarCompra);
        lineEditNomeCompra->setObjectName(QStringLiteral("lineEditNomeCompra"));

        gridLayout->addWidget(lineEditNomeCompra, 0, 2, 1, 1);

        dateEditDataCompra = new QDateEdit(DialogAdicionarCompra);
        dateEditDataCompra->setObjectName(QStringLiteral("dateEditDataCompra"));

        gridLayout->addWidget(dateEditDataCompra, 1, 2, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        buttonBox = new QDialogButtonBox(DialogAdicionarCompra);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_2->addWidget(buttonBox);


        verticalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(DialogAdicionarCompra);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogAdicionarCompra, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogAdicionarCompra, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogAdicionarCompra);
    } // setupUi

    void retranslateUi(QDialog *DialogAdicionarCompra)
    {
        DialogAdicionarCompra->setWindowTitle(QApplication::translate("DialogAdicionarCompra", "Dialog", 0));
        label->setText(QApplication::translate("DialogAdicionarCompra", "Nova Compra", 0));
        label_2->setText(QApplication::translate("DialogAdicionarCompra", "Nome da Compra", 0));
        label_3->setText(QApplication::translate("DialogAdicionarCompra", "Data da Compra", 0));
    } // retranslateUi

};

namespace Ui {
    class DialogAdicionarCompra: public Ui_DialogAdicionarCompra {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGADICIONARCOMPRA_H
