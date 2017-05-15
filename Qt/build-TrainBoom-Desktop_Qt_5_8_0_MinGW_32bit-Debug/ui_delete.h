/********************************************************************************
** Form generated from reading UI file 'delete.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETE_H
#define UI_DELETE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Delete
{
public:
    QPushButton *pushButton_2;
    QLabel *label;
    QLineEdit *nameLineEdit;
    QPushButton *pushButton;

    void setupUi(QDialog *Delete)
    {
        if (Delete->objectName().isEmpty())
            Delete->setObjectName(QStringLiteral("Delete"));
        Delete->resize(246, 136);
        pushButton_2 = new QPushButton(Delete);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(140, 80, 71, 28));
        label = new QLabel(Delete);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 30, 81, 21));
        nameLineEdit = new QLineEdit(Delete);
        nameLineEdit->setObjectName(QStringLiteral("nameLineEdit"));
        nameLineEdit->setGeometry(QRect(120, 30, 101, 21));
        pushButton = new QPushButton(Delete);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(40, 80, 71, 28));

        retranslateUi(Delete);

        QMetaObject::connectSlotsByName(Delete);
    } // setupUi

    void retranslateUi(QDialog *Delete)
    {
        Delete->setWindowTitle(QApplication::translate("Delete", "Dialog", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Delete", "\350\277\224\345\233\236", Q_NULLPTR));
        label->setText(QApplication::translate("Delete", "\350\275\246\346\254\241\347\274\226\345\217\267:", Q_NULLPTR));
        nameLineEdit->setText(QString());
        pushButton->setText(QApplication::translate("Delete", "\347\241\256\350\256\244", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Delete: public Ui_Delete {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETE_H
