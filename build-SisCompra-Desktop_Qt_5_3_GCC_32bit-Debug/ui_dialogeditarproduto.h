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
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_DialogEditarProduto
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DialogEditarProduto)
    {
        if (DialogEditarProduto->objectName().isEmpty())
            DialogEditarProduto->setObjectName(QStringLiteral("DialogEditarProduto"));
        DialogEditarProduto->resize(400, 300);
        buttonBox = new QDialogButtonBox(DialogEditarProduto);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(DialogEditarProduto);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogEditarProduto, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogEditarProduto, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogEditarProduto);
    } // setupUi

    void retranslateUi(QDialog *DialogEditarProduto)
    {
        DialogEditarProduto->setWindowTitle(QApplication::translate("DialogEditarProduto", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class DialogEditarProduto: public Ui_DialogEditarProduto {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGEDITARPRODUTO_H
