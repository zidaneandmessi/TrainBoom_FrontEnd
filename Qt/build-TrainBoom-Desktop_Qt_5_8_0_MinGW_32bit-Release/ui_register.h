/********************************************************************************
** Form generated from reading UI file 'register.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_H
#define UI_REGISTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_Register
{
public:
    QLineEdit *pwdLineEdit;
    QPushButton *exitBtn;
    QLabel *label_3;
    QLabel *label;
    QLineEdit *userLineEdit;
    QLabel *label_2;
    QPushButton *regBtn;
    QLabel *label_4;
    QLineEdit *pwdLineEdit2;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLineEdit *realLineEdit;
    QLineEdit *phoneLineEdit;
    QLineEdit *emailLineEdit;
    QLineEdit *mottoLineEdit;
    QRadioButton *maleRadioBtn;
    QRadioButton *femaleRadioBtn;
    QRadioButton *elseRadioBtn;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;

    void setupUi(QDialog *Register)
    {
        if (Register->objectName().isEmpty())
            Register->setObjectName(QStringLiteral("Register"));
        Register->resize(400, 405);
        pwdLineEdit = new QLineEdit(Register);
        pwdLineEdit->setObjectName(QStringLiteral("pwdLineEdit"));
        pwdLineEdit->setGeometry(QRect(180, 120, 151, 21));
        pwdLineEdit->setEchoMode(QLineEdit::Password);
        pwdLineEdit->setClearButtonEnabled(false);
        exitBtn = new QPushButton(Register);
        exitBtn->setObjectName(QStringLiteral("exitBtn"));
        exitBtn->setGeometry(QRect(210, 350, 93, 28));
        label_3 = new QLabel(Register);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(170, 20, 61, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font.setPointSize(18);
        label_3->setFont(font);
        label = new QLabel(Register);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 90, 91, 16));
        userLineEdit = new QLineEdit(Register);
        userLineEdit->setObjectName(QStringLiteral("userLineEdit"));
        userLineEdit->setGeometry(QRect(180, 90, 151, 21));
        label_2 = new QLabel(Register);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 120, 91, 16));
        regBtn = new QPushButton(Register);
        regBtn->setObjectName(QStringLiteral("regBtn"));
        regBtn->setGeometry(QRect(80, 350, 93, 28));
        label_4 = new QLabel(Register);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(50, 150, 131, 20));
        pwdLineEdit2 = new QLineEdit(Register);
        pwdLineEdit2->setObjectName(QStringLiteral("pwdLineEdit2"));
        pwdLineEdit2->setGeometry(QRect(180, 150, 151, 21));
        pwdLineEdit2->setEchoMode(QLineEdit::Password);
        pwdLineEdit2->setClearButtonEnabled(false);
        label_5 = new QLabel(Register);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(50, 180, 131, 20));
        label_6 = new QLabel(Register);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(50, 210, 131, 20));
        label_7 = new QLabel(Register);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(50, 240, 131, 20));
        label_8 = new QLabel(Register);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(50, 270, 131, 20));
        label_9 = new QLabel(Register);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(50, 300, 131, 20));
        realLineEdit = new QLineEdit(Register);
        realLineEdit->setObjectName(QStringLiteral("realLineEdit"));
        realLineEdit->setGeometry(QRect(180, 180, 151, 21));
        realLineEdit->setEchoMode(QLineEdit::Normal);
        realLineEdit->setClearButtonEnabled(false);
        phoneLineEdit = new QLineEdit(Register);
        phoneLineEdit->setObjectName(QStringLiteral("phoneLineEdit"));
        phoneLineEdit->setGeometry(QRect(180, 210, 151, 21));
        phoneLineEdit->setEchoMode(QLineEdit::Normal);
        phoneLineEdit->setClearButtonEnabled(false);
        emailLineEdit = new QLineEdit(Register);
        emailLineEdit->setObjectName(QStringLiteral("emailLineEdit"));
        emailLineEdit->setGeometry(QRect(180, 240, 151, 21));
        emailLineEdit->setEchoMode(QLineEdit::Normal);
        emailLineEdit->setClearButtonEnabled(false);
        mottoLineEdit = new QLineEdit(Register);
        mottoLineEdit->setObjectName(QStringLiteral("mottoLineEdit"));
        mottoLineEdit->setGeometry(QRect(180, 270, 151, 21));
        mottoLineEdit->setEchoMode(QLineEdit::Normal);
        mottoLineEdit->setClearButtonEnabled(false);
        maleRadioBtn = new QRadioButton(Register);
        maleRadioBtn->setObjectName(QStringLiteral("maleRadioBtn"));
        maleRadioBtn->setGeometry(QRect(150, 300, 61, 19));
        femaleRadioBtn = new QRadioButton(Register);
        femaleRadioBtn->setObjectName(QStringLiteral("femaleRadioBtn"));
        femaleRadioBtn->setEnabled(true);
        femaleRadioBtn->setGeometry(QRect(210, 300, 81, 19));
        elseRadioBtn = new QRadioButton(Register);
        elseRadioBtn->setObjectName(QStringLiteral("elseRadioBtn"));
        elseRadioBtn->setGeometry(QRect(270, 300, 61, 19));
        elseRadioBtn->setChecked(true);
        label_10 = new QLabel(Register);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(340, 90, 31, 20));
        label_11 = new QLabel(Register);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(340, 120, 31, 20));
        label_12 = new QLabel(Register);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(340, 150, 31, 20));
        label_13 = new QLabel(Register);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(370, 300, 31, 20));
        QWidget::setTabOrder(userLineEdit, pwdLineEdit);
        QWidget::setTabOrder(pwdLineEdit, pwdLineEdit2);
        QWidget::setTabOrder(pwdLineEdit2, realLineEdit);
        QWidget::setTabOrder(realLineEdit, phoneLineEdit);
        QWidget::setTabOrder(phoneLineEdit, emailLineEdit);
        QWidget::setTabOrder(emailLineEdit, mottoLineEdit);
        QWidget::setTabOrder(mottoLineEdit, maleRadioBtn);
        QWidget::setTabOrder(maleRadioBtn, femaleRadioBtn);
        QWidget::setTabOrder(femaleRadioBtn, elseRadioBtn);
        QWidget::setTabOrder(elseRadioBtn, regBtn);
        QWidget::setTabOrder(regBtn, exitBtn);

        retranslateUi(Register);

        QMetaObject::connectSlotsByName(Register);
    } // setupUi

    void retranslateUi(QDialog *Register)
    {
        Register->setWindowTitle(QApplication::translate("Register", "Register", Q_NULLPTR));
        pwdLineEdit->setPlaceholderText(QString());
        exitBtn->setText(QApplication::translate("Register", "\350\277\224\345\233\236", Q_NULLPTR));
        label_3->setText(QApplication::translate("Register", "\346\263\250\345\206\214", Q_NULLPTR));
        label->setText(QApplication::translate("Register", "\347\224\250\346\210\267\345\220\215:", Q_NULLPTR));
        userLineEdit->setPlaceholderText(QString());
        label_2->setText(QApplication::translate("Register", "\345\257\206\347\240\201:", Q_NULLPTR));
        regBtn->setText(QApplication::translate("Register", "\346\263\250\345\206\214", Q_NULLPTR));
        label_4->setText(QApplication::translate("Register", "\345\206\215\346\254\241\350\276\223\345\205\245\345\257\206\347\240\201:", Q_NULLPTR));
        pwdLineEdit2->setPlaceholderText(QString());
        label_5->setText(QApplication::translate("Register", "\347\234\237\345\256\236\345\247\223\345\220\215:", Q_NULLPTR));
        label_6->setText(QApplication::translate("Register", "\347\224\265\350\257\235:", Q_NULLPTR));
        label_7->setText(QApplication::translate("Register", "\351\202\256\347\256\261:", Q_NULLPTR));
        label_8->setText(QApplication::translate("Register", "\344\270\252\346\200\247\347\255\276\345\220\215:", Q_NULLPTR));
        label_9->setText(QApplication::translate("Register", "\346\200\247\345\210\253:", Q_NULLPTR));
        realLineEdit->setPlaceholderText(QString());
        phoneLineEdit->setPlaceholderText(QString());
        emailLineEdit->setPlaceholderText(QString());
        mottoLineEdit->setPlaceholderText(QString());
        maleRadioBtn->setText(QApplication::translate("Register", "\347\224\267", Q_NULLPTR));
        femaleRadioBtn->setText(QApplication::translate("Register", "\345\245\263", Q_NULLPTR));
        elseRadioBtn->setText(QApplication::translate("Register", "\345\205\266\344\273\226", Q_NULLPTR));
        label_10->setText(QApplication::translate("Register", "*", Q_NULLPTR));
        label_11->setText(QApplication::translate("Register", "*", Q_NULLPTR));
        label_12->setText(QApplication::translate("Register", "*", Q_NULLPTR));
        label_13->setText(QApplication::translate("Register", "*", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Register: public Ui_Register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H
