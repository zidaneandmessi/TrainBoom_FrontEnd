/********************************************************************************
** Form generated from reading UI file 'modify.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFY_H
#define UI_MODIFY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_modify
{
public:

    void setupUi(QDialog *modify)
    {
        if (modify->objectName().isEmpty())
            modify->setObjectName(QStringLiteral("modify"));
        modify->resize(400, 300);

        retranslateUi(modify);

        QMetaObject::connectSlotsByName(modify);
    } // setupUi

    void retranslateUi(QDialog *modify)
    {
        modify->setWindowTitle(QApplication::translate("modify", "Dialog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class modify: public Ui_modify {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFY_H
