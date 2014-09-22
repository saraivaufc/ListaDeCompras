/********************************************************************************
** Form generated from reading UI file 'viewproduto.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWPRODUTO_H
#define UI_VIEWPRODUTO_H

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

class Ui_ViewProduto
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label_7;
    QSpacerItem *horizontalSpacer_2;
    QGridLayout *gridLayout;
    QLabel *label_6;
    QLabel *labelNomeProduto;
    QLabel *label;
    QLabel *labelQuantidade;
    QLabel *label_2;
    QLabel *labelValorUnitario;
    QLabel *label_4;
    QLabel *labelClasse;
    QLabel *label_5;
    QLabel *labelValorTotal;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QDialogButtonBox *buttonBox;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QDialog *ViewProduto)
    {
        if (ViewProduto->objectName().isEmpty())
            ViewProduto->setObjectName(QStringLiteral("ViewProduto"));
        ViewProduto->resize(344, 282);
        QIcon icon;
        icon.addFile(QStringLiteral(":/imagens/icones/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        ViewProduto->setWindowIcon(icon);
        ViewProduto->setStyleSheet(QStringLiteral(""));
        verticalLayout_2 = new QVBoxLayout(ViewProduto);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_7 = new QLabel(ViewProduto);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setEnabled(true);
        QFont font;
        font.setPointSize(16);
        label_7->setFont(font);

        horizontalLayout->addWidget(label_7);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(ViewProduto);
        label_6->setObjectName(QStringLiteral("label_6"));
        QFont font1;
        font1.setPointSize(14);
        label_6->setFont(font1);

        gridLayout->addWidget(label_6, 0, 0, 1, 1);

        labelNomeProduto = new QLabel(ViewProduto);
        labelNomeProduto->setObjectName(QStringLiteral("labelNomeProduto"));
        labelNomeProduto->setFont(font1);

        gridLayout->addWidget(labelNomeProduto, 0, 1, 1, 1);

        label = new QLabel(ViewProduto);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font1);

        gridLayout->addWidget(label, 1, 0, 1, 1);

        labelQuantidade = new QLabel(ViewProduto);
        labelQuantidade->setObjectName(QStringLiteral("labelQuantidade"));
        labelQuantidade->setFont(font1);

        gridLayout->addWidget(labelQuantidade, 1, 1, 1, 1);

        label_2 = new QLabel(ViewProduto);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font1);

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        labelValorUnitario = new QLabel(ViewProduto);
        labelValorUnitario->setObjectName(QStringLiteral("labelValorUnitario"));
        labelValorUnitario->setFont(font1);

        gridLayout->addWidget(labelValorUnitario, 2, 1, 1, 1);

        label_4 = new QLabel(ViewProduto);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font1);

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        labelClasse = new QLabel(ViewProduto);
        labelClasse->setObjectName(QStringLiteral("labelClasse"));
        labelClasse->setFont(font1);

        gridLayout->addWidget(labelClasse, 3, 1, 1, 1);

        label_5 = new QLabel(ViewProduto);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font1);

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        labelValorTotal = new QLabel(ViewProduto);
        labelValorTotal->setObjectName(QStringLiteral("labelValorTotal"));
        labelValorTotal->setFont(font1);

        gridLayout->addWidget(labelValorTotal, 4, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        buttonBox = new QDialogButtonBox(ViewProduto);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout_2->addWidget(buttonBox);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 7);
        verticalLayout->setStretch(2, 1);

        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(ViewProduto);
        QObject::connect(buttonBox, SIGNAL(accepted()), ViewProduto, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ViewProduto, SLOT(reject()));

        QMetaObject::connectSlotsByName(ViewProduto);
    } // setupUi

    void retranslateUi(QDialog *ViewProduto)
    {
        ViewProduto->setWindowTitle(QApplication::translate("ViewProduto", "Dialog", 0));
        label_7->setText(QApplication::translate("ViewProduto", "Produto", 0));
        label_6->setText(QApplication::translate("ViewProduto", "Nome:", 0));
        labelNomeProduto->setText(QString());
        label->setText(QApplication::translate("ViewProduto", "Quantidade: ", 0));
        labelQuantidade->setText(QString());
        label_2->setText(QApplication::translate("ViewProduto", "Valor Unitario: ", 0));
        labelValorUnitario->setText(QString());
        label_4->setText(QApplication::translate("ViewProduto", "Classe:", 0));
        labelClasse->setText(QString());
        label_5->setText(QApplication::translate("ViewProduto", "Valor Total:", 0));
        labelValorTotal->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ViewProduto: public Ui_ViewProduto {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWPRODUTO_H
