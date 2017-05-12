/********************************************************************************
** Form generated from reading UI file 'buy.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUY_H
#define UI_BUY_H

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

class Ui_Buy
{
public:
    QLabel *label;
    QLineEdit *numLineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_2;

    void setupUi(QDialog *Buy)
    {
        if (Buy->objectName().isEmpty())
            Buy->setObjectName(QStringLiteral("Buy"));
        Buy->resize(254, 195);
        label = new QLabel(Buy);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 110, 111, 21));
        numLineEdit = new QLineEdit(Buy);
        numLineEdit->setObjectName(QStringLiteral("numLineEdit"));
        numLineEdit->setGeometry(QRect(170, 110, 41, 21));
        pushButton = new QPushButton(Buy);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(40, 150, 71, 28));
        pushButton_2 = new QPushButton(Buy);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(140, 150, 71, 28));
        label_2 = new QLabel(Buy);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 40, 151, 51));

        retranslateUi(Buy);

        QMetaObject::connectSlotsByName(Buy);
    } // setupUi

    void retranslateUi(QDialog *Buy)
    {
        Buy->setWindowTitle(QApplication::translate("Buy", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("Buy", "\350\257\267\350\276\223\345\205\245\350\264\255\344\271\260\346\225\260\351\207\217:", Q_NULLPTR));
        numLineEdit->setText(QString());
        pushButton->setText(QApplication::translate("Buy", "\347\241\256\350\256\244", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Buy", "\350\277\224\345\233\236", Q_NULLPTR));
        label_2->setText(QApplication::translate("Buy", "er", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Buy: public Ui_Buy {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUY_H
