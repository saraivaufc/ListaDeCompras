/********************************************************************************
** Form generated from reading UI file 'dialogconfirmacao.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGCONFIRMACAO_H
#define UI_DIALOGCONFIRMACAO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogConfirmacao
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *labelMenssagem;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *buttonBox;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *DialogConfirmacao)
    {
        if (DialogConfirmacao->objectName().isEmpty())
            DialogConfirmacao->setObjectName(QStringLiteral("DialogConfirmacao"));
        DialogConfirmacao->resize(435, 115);
        verticalLayout_2 = new QVBoxLayout(DialogConfirmacao);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        labelMenssagem = new QLabel(DialogConfirmacao);
        labelMenssagem->setObjectName(QStringLiteral("labelMenssagem"));
        QFont font;
        font.setPointSize(18);
        labelMenssagem->setFont(font);

        verticalLayout->addWidget(labelMenssagem);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        buttonBox = new QDialogButtonBox(DialogConfirmacao);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout->addWidget(buttonBox);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(DialogConfirmacao);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogConfirmacao, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogConfirmacao, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogConfirmacao);
    } // setupUi

    void retranslateUi(QDialog *DialogConfirmacao)
    {
        DialogConfirmacao->setWindowTitle(QApplication::translate("DialogConfirmacao", "Dialog", 0));
        labelMenssagem->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DialogConfirmacao: public Ui_DialogConfirmacao {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGCONFIRMACAO_H
