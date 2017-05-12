/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

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

class Ui_LoginDialog
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *userLineEdit;
    QLineEdit *pwdLineEdit;
    QPushButton *loginBtn;
    QPushButton *exitBtn;
    QLabel *label_3;
    QPushButton *regBtn;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName(QStringLiteral("LoginDialog"));
        LoginDialog->resize(400, 300);
        label = new QLabel(LoginDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(80, 100, 91, 16));
        label_2 = new QLabel(LoginDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(80, 140, 91, 16));
        userLineEdit = new QLineEdit(LoginDialog);
        userLineEdit->setObjectName(QStringLiteral("userLineEdit"));
        userLineEdit->setGeometry(QRect(170, 100, 151, 21));
        pwdLineEdit = new QLineEdit(LoginDialog);
        pwdLineEdit->setObjectName(QStringLiteral("pwdLineEdit"));
        pwdLineEdit->setGeometry(QRect(170, 140, 151, 21));
        pwdLineEdit->setEchoMode(QLineEdit::Password);
        pwdLineEdit->setClearButtonEnabled(false);
        loginBtn = new QPushButton(LoginDialog);
        loginBtn->setObjectName(QStringLiteral("loginBtn"));
        loginBtn->setGeometry(QRect(50, 220, 93, 28));
        exitBtn = new QPushButton(LoginDialog);
        exitBtn->setObjectName(QStringLiteral("exitBtn"));
        exitBtn->setGeometry(QRect(270, 220, 93, 28));
        label_3 = new QLabel(LoginDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(80, 30, 251, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font.setPointSize(18);
        label_3->setFont(font);
        regBtn = new QPushButton(LoginDialog);
        regBtn->setObjectName(QStringLiteral("regBtn"));
        regBtn->setGeometry(QRect(160, 220, 93, 28));
        QWidget::setTabOrder(userLineEdit, pwdLineEdit);
        QWidget::setTabOrder(pwdLineEdit, loginBtn);
        QWidget::setTabOrder(loginBtn, regBtn);
        QWidget::setTabOrder(regBtn, exitBtn);

        retranslateUi(LoginDialog);
        QObject::connect(exitBtn, SIGNAL(clicked()), LoginDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QApplication::translate("LoginDialog", "Login", Q_NULLPTR));
        label->setText(QApplication::translate("LoginDialog", "\347\224\250\346\210\267\345\220\215:", Q_NULLPTR));
        label_2->setText(QApplication::translate("LoginDialog", "\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        userLineEdit->setPlaceholderText(QString());
        pwdLineEdit->setPlaceholderText(QString());
        loginBtn->setText(QApplication::translate("LoginDialog", "\347\231\273\345\275\225", Q_NULLPTR));
        exitBtn->setText(QApplication::translate("LoginDialog", "\351\200\200\345\207\272", Q_NULLPTR));
        label_3->setText(QApplication::translate("LoginDialog", "\345\260\233\347\204\261\350\275\237\347\263\273\347\273\237\346\265\213\350\257\225\347\211\210", Q_NULLPTR));
        regBtn->setText(QApplication::translate("LoginDialog", "\346\263\250\345\206\214", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
