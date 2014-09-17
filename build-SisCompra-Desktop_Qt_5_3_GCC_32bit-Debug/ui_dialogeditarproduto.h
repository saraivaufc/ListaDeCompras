/********************************************************************************
** Form generated from reading UI file 'dialogeditarproduto.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGEDITARPRODUTO_H
#define UI_DIALOGEDITARPRODUTO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogEditarProduto
{
public:
    QVBoxLayout *verticalLayout_3;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_5;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEditNome;
    QSpinBox *spinBoxQuant;
    QDoubleSpinBox *doubleSpinBoxValor;
    QComboBox *comboBox;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DialogEditarProduto)
    {
        if (DialogEditarProduto->objectName().isEmpty())
            DialogEditarProduto->setObjectName(QStringLiteral("DialogEditarProduto"));
        DialogEditarProduto->resize(400, 300);
        verticalLayout_3 = new QVBoxLayout(DialogEditarProduto);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_4 = new QLabel(DialogEditarProduto);
        label_4->setObjectName(QStringLiteral("label_4"));
        QFont font;
        font.setPointSize(14);
        label_4->setFont(font);

        verticalLayout_3->addWidget(label_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(DialogEditarProduto);
        label->setObjectName(QStringLiteral("label"));
        QFont font1;
        font1.setPointSize(12);
        label->setFont(font1);

        verticalLayout->addWidget(label);

        label_2 = new QLabel(DialogEditarProduto);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font1);

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(DialogEditarProduto);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font1);

        verticalLayout->addWidget(label_3);

        label_5 = new QLabel(DialogEditarProduto);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout->addWidget(label_5);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        lineEditNome = new QLineEdit(DialogEditarProduto);
        lineEditNome->setObjectName(QStringLiteral("lineEditNome"));
        lineEditNome->setFont(font1);

        verticalLayout_2->addWidget(lineEditNome);

        spinBoxQuant = new QSpinBox(DialogEditarProduto);
        spinBoxQuant->setObjectName(QStringLiteral("spinBoxQuant"));

        verticalLayout_2->addWidget(spinBoxQuant);

        doubleSpinBoxValor = new QDoubleSpinBox(DialogEditarProduto);
        doubleSpinBoxValor->setObjectName(QStringLiteral("doubleSpinBoxValor"));

        verticalLayout_2->addWidget(doubleSpinBoxValor);

        comboBox = new QComboBox(DialogEditarProduto);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        verticalLayout_2->addWidget(comboBox);


        horizontalLayout->addLayout(verticalLayout_2);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 5);

        verticalLayout_3->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        buttonBox = new QDialogButtonBox(DialogEditarProduto);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(buttonBox->sizePolicy().hasHeightForWidth());
        buttonBox->setSizePolicy(sizePolicy);
        buttonBox->setLayoutDirection(Qt::LeftToRight);
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_3->addWidget(buttonBox);

        verticalLayout_3->setStretch(0, 1);
        verticalLayout_3->setStretch(1, 5);
        verticalLayout_3->setStretch(2, 5);
        verticalLayout_3->setStretch(3, 1);

        retranslateUi(DialogEditarProduto);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogEditarProduto, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogEditarProduto, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogEditarProduto);
    } // setupUi

    void retranslateUi(QDialog *DialogEditarProduto)
    {
        DialogEditarProduto->setWindowTitle(QApplication::translate("DialogEditarProduto", "Dialog", 0));
        label_4->setText(QApplication::translate("DialogEditarProduto", "Informa\303\247\303\265es do produto", 0));
        label->setText(QApplication::translate("DialogEditarProduto", "Nome", 0));
        label_2->setText(QApplication::translate("DialogEditarProduto", "Quantidade", 0));
        label_3->setText(QApplication::translate("DialogEditarProduto", "Valor unit\303\241rio", 0));
        label_5->setText(QApplication::translate("DialogEditarProduto", "Classe", 0));
    } // retranslateUi

};

namespace Ui {
    class DialogEditarProduto: public Ui_DialogEditarProduto {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGEDITARPRODUTO_H
