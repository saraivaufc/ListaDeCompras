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
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_DialogEditarCompra
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DialogEditarCompra)
    {
        if (DialogEditarCompra->objectName().isEmpty())
            DialogEditarCompra->setObjectName(QStringLiteral("DialogEditarCompra"));
        DialogEditarCompra->resize(400, 300);
        buttonBox = new QDialogButtonBox(DialogEditarCompra);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(DialogEditarCompra);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogEditarCompra, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogEditarCompra, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogEditarCompra);
    } // setupUi

    void retranslateUi(QDialog *DialogEditarCompra)
    {
        DialogEditarCompra->setWindowTitle(QApplication::translate("DialogEditarCompra", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class DialogEditarCompra: public Ui_DialogEditarCompra {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGEDITARCOMPRA_H
