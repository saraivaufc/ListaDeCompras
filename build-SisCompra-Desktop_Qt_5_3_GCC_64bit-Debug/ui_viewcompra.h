/********************************************************************************
** Form generated from reading UI file 'viewcompra.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWCOMPRA_H
#define UI_VIEWCOMPRA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ViewCompra
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QGridLayout *gridLayout;
    QLabel *labelNome;
    QLabel *labelData;
    QLabel *label_3;
    QLabel *labelValorTotal;
    QLabel *label_4;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QDialogButtonBox *buttonBox;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QDialog *ViewCompra)
    {
        if (ViewCompra->objectName().isEmpty())
            ViewCompra->setObjectName(QStringLiteral("ViewCompra"));
        ViewCompra->resize(286, 209);
        verticalLayout_2 = new QVBoxLayout(ViewCompra);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(ViewCompra);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(16);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        labelNome = new QLabel(ViewCompra);
        labelNome->setObjectName(QStringLiteral("labelNome"));
        QFont font1;
        font1.setPointSize(14);
        labelNome->setFont(font1);

        gridLayout->addWidget(labelNome, 2, 1, 1, 1);

        labelData = new QLabel(ViewCompra);
        labelData->setObjectName(QStringLiteral("labelData"));
        labelData->setFont(font1);

        gridLayout->addWidget(labelData, 3, 1, 1, 1);

        label_3 = new QLabel(ViewCompra);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font1);

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        labelValorTotal = new QLabel(ViewCompra);
        labelValorTotal->setObjectName(QStringLiteral("labelValorTotal"));
        labelValorTotal->setFont(font1);

        gridLayout->addWidget(labelValorTotal, 4, 1, 1, 1);

        label_4 = new QLabel(ViewCompra);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font1);

        gridLayout->addWidget(label_4, 4, 0, 1, 1);

        label_2 = new QLabel(ViewCompra);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font1);

        gridLayout->addWidget(label_2, 2, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        buttonBox = new QDialogButtonBox(ViewCompra);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout_2->addWidget(buttonBox);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 3);
        verticalLayout->setStretch(2, 1);

        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(ViewCompra);
        QObject::connect(buttonBox, SIGNAL(accepted()), ViewCompra, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ViewCompra, SLOT(reject()));

        QMetaObject::connectSlotsByName(ViewCompra);
    } // setupUi

    void retranslateUi(QDialog *ViewCompra)
    {
        ViewCompra->setWindowTitle(QApplication::translate("ViewCompra", "Dialog", 0));
        label->setText(QApplication::translate("ViewCompra", "Compra", 0));
        labelNome->setText(QString());
        labelData->setText(QString());
        label_3->setText(QApplication::translate("ViewCompra", "Data:", 0));
        labelValorTotal->setText(QString());
        label_4->setText(QApplication::translate("ViewCompra", "Valor Total:", 0));
        label_2->setText(QApplication::translate("ViewCompra", "Nome:", 0));
    } // retranslateUi

};

namespace Ui {
    class ViewCompra: public Ui_ViewCompra {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWCOMPRA_H
