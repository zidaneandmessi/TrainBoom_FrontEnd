/********************************************************************************
** Form generated from reading UI file 'start.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_START_H
#define UI_START_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Start
{
public:
    QPushButton *pushButton;
    QLineEdit *nameLineEdit;
    QPushButton *pushButton_2;
    QLabel *label;
    QDateEdit *dateEdit;
    QLabel *label_2;

    void setupUi(QDialog *Start)
    {
        if (Start->objectName().isEmpty())
            Start->setObjectName(QStringLiteral("Start"));
        Start->resize(282, 143);
        pushButton = new QPushButton(Start);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(50, 100, 71, 28));
        nameLineEdit = new QLineEdit(Start);
        nameLineEdit->setObjectName(QStringLiteral("nameLineEdit"));
        nameLineEdit->setGeometry(QRect(130, 20, 101, 21));
        pushButton_2 = new QPushButton(Start);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(150, 100, 71, 28));
        label = new QLabel(Start);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 20, 81, 21));
        dateEdit = new QDateEdit(Start);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setGeometry(QRect(130, 60, 101, 22));
        label_2 = new QLabel(Start);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 60, 51, 21));

        retranslateUi(Start);

        QMetaObject::connectSlotsByName(Start);
    } // setupUi

    void retranslateUi(QDialog *Start)
    {
        Start->setWindowTitle(QApplication::translate("Start", "Dialog", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Start", "\347\241\256\350\256\244", Q_NULLPTR));
        nameLineEdit->setText(QString());
        pushButton_2->setText(QApplication::translate("Start", "\350\277\224\345\233\236", Q_NULLPTR));
        label->setText(QApplication::translate("Start", "\350\275\246\346\254\241\347\274\226\345\217\267:", Q_NULLPTR));
        label_2->setText(QApplication::translate("Start", "\346\227\245\346\234\237:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Start: public Ui_Start {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_START_H
