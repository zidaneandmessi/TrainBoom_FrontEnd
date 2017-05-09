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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_modify
{
public:
    QLabel *label_3;
    QPushButton *exitBtn;
    QLineEdit *npwdLineEdit2;
    QPushButton *regBtn;
    QLineEdit *phoneLineEdit;
    QRadioButton *femaleRadioBtn;
    QLineEdit *npwdLineEdit;
    QLabel *label_9;
    QLabel *label;
    QRadioButton *elseRadioBtn;
    QRadioButton *maleRadioBtn;
    QLineEdit *emailLineEdit;
    QLabel *label_2;
    QLineEdit *mottoLineEdit;
    QLabel *label_4;
    QLabel *label_7;
    QLabel *label_6;
    QLabel *label_8;
    QLabel *label_5;
    QLineEdit *realLineEdit;
    QLineEdit *pwdLineEdit;
    QLabel *label_13;
    QLabel *label_10;
    QLabel *userLabel;

    void setupUi(QDialog *modify)
    {
        if (modify->objectName().isEmpty())
            modify->setObjectName(QStringLiteral("modify"));
        modify->resize(400, 460);
        label_3 = new QLabel(modify);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(80, 30, 251, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font.setPointSize(18);
        label_3->setFont(font);
        exitBtn = new QPushButton(modify);
        exitBtn->setObjectName(QStringLiteral("exitBtn"));
        exitBtn->setGeometry(QRect(210, 390, 93, 28));
        npwdLineEdit2 = new QLineEdit(modify);
        npwdLineEdit2->setObjectName(QStringLiteral("npwdLineEdit2"));
        npwdLineEdit2->setGeometry(QRect(190, 180, 151, 21));
        npwdLineEdit2->setEchoMode(QLineEdit::Password);
        npwdLineEdit2->setClearButtonEnabled(false);
        regBtn = new QPushButton(modify);
        regBtn->setObjectName(QStringLiteral("regBtn"));
        regBtn->setGeometry(QRect(80, 390, 93, 28));
        phoneLineEdit = new QLineEdit(modify);
        phoneLineEdit->setObjectName(QStringLiteral("phoneLineEdit"));
        phoneLineEdit->setGeometry(QRect(190, 240, 151, 21));
        phoneLineEdit->setEchoMode(QLineEdit::Normal);
        phoneLineEdit->setClearButtonEnabled(false);
        femaleRadioBtn = new QRadioButton(modify);
        femaleRadioBtn->setObjectName(QStringLiteral("femaleRadioBtn"));
        femaleRadioBtn->setEnabled(true);
        femaleRadioBtn->setGeometry(QRect(220, 330, 81, 19));
        npwdLineEdit = new QLineEdit(modify);
        npwdLineEdit->setObjectName(QStringLiteral("npwdLineEdit"));
        npwdLineEdit->setGeometry(QRect(190, 150, 151, 21));
        npwdLineEdit->setEchoMode(QLineEdit::Password);
        npwdLineEdit->setClearButtonEnabled(false);
        label_9 = new QLabel(modify);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(40, 330, 131, 20));
        label = new QLabel(modify);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 90, 91, 16));
        elseRadioBtn = new QRadioButton(modify);
        elseRadioBtn->setObjectName(QStringLiteral("elseRadioBtn"));
        elseRadioBtn->setGeometry(QRect(310, 330, 61, 19));
        elseRadioBtn->setChecked(false);
        maleRadioBtn = new QRadioButton(modify);
        maleRadioBtn->setObjectName(QStringLiteral("maleRadioBtn"));
        maleRadioBtn->setGeometry(QRect(150, 330, 61, 19));
        emailLineEdit = new QLineEdit(modify);
        emailLineEdit->setObjectName(QStringLiteral("emailLineEdit"));
        emailLineEdit->setGeometry(QRect(190, 270, 151, 21));
        emailLineEdit->setEchoMode(QLineEdit::Normal);
        emailLineEdit->setClearButtonEnabled(false);
        label_2 = new QLabel(modify);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 150, 121, 16));
        mottoLineEdit = new QLineEdit(modify);
        mottoLineEdit->setObjectName(QStringLiteral("mottoLineEdit"));
        mottoLineEdit->setGeometry(QRect(190, 300, 151, 21));
        mottoLineEdit->setEchoMode(QLineEdit::Normal);
        mottoLineEdit->setClearButtonEnabled(false);
        label_4 = new QLabel(modify);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(40, 180, 141, 20));
        label_7 = new QLabel(modify);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(40, 270, 131, 20));
        label_6 = new QLabel(modify);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(40, 240, 131, 20));
        label_8 = new QLabel(modify);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(40, 300, 131, 20));
        label_5 = new QLabel(modify);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(40, 210, 131, 20));
        realLineEdit = new QLineEdit(modify);
        realLineEdit->setObjectName(QStringLiteral("realLineEdit"));
        realLineEdit->setGeometry(QRect(190, 210, 151, 21));
        realLineEdit->setEchoMode(QLineEdit::Normal);
        realLineEdit->setClearButtonEnabled(false);
        pwdLineEdit = new QLineEdit(modify);
        pwdLineEdit->setObjectName(QStringLiteral("pwdLineEdit"));
        pwdLineEdit->setGeometry(QRect(190, 120, 151, 21));
        pwdLineEdit->setEchoMode(QLineEdit::Password);
        pwdLineEdit->setClearButtonEnabled(false);
        label_13 = new QLabel(modify);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(350, 120, 31, 20));
        label_10 = new QLabel(modify);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(40, 120, 91, 16));
        userLabel = new QLabel(modify);
        userLabel->setObjectName(QStringLiteral("userLabel"));
        userLabel->setGeometry(QRect(190, 90, 72, 15));
        QWidget::setTabOrder(pwdLineEdit, npwdLineEdit);
        QWidget::setTabOrder(npwdLineEdit, npwdLineEdit2);
        QWidget::setTabOrder(npwdLineEdit2, realLineEdit);
        QWidget::setTabOrder(realLineEdit, phoneLineEdit);
        QWidget::setTabOrder(phoneLineEdit, emailLineEdit);
        QWidget::setTabOrder(emailLineEdit, mottoLineEdit);
        QWidget::setTabOrder(mottoLineEdit, maleRadioBtn);
        QWidget::setTabOrder(maleRadioBtn, femaleRadioBtn);
        QWidget::setTabOrder(femaleRadioBtn, elseRadioBtn);
        QWidget::setTabOrder(elseRadioBtn, regBtn);
        QWidget::setTabOrder(regBtn, exitBtn);

        retranslateUi(modify);

        QMetaObject::connectSlotsByName(modify);
    } // setupUi

    void retranslateUi(QDialog *modify)
    {
        modify->setWindowTitle(QApplication::translate("modify", "Dialog", Q_NULLPTR));
        label_3->setText(QApplication::translate("modify", "\345\260\233\347\204\261\350\275\237\347\263\273\347\273\237\346\265\213\350\257\225\347\211\210", Q_NULLPTR));
        exitBtn->setText(QApplication::translate("modify", "Back", Q_NULLPTR));
        npwdLineEdit2->setPlaceholderText(QString());
        regBtn->setText(QApplication::translate("modify", "Modify", Q_NULLPTR));
        phoneLineEdit->setPlaceholderText(QString());
        femaleRadioBtn->setText(QApplication::translate("modify", "Female", Q_NULLPTR));
        npwdLineEdit->setPlaceholderText(QString());
        label_9->setText(QApplication::translate("modify", "Gender:", Q_NULLPTR));
        label->setText(QApplication::translate("modify", "Username:", Q_NULLPTR));
        elseRadioBtn->setText(QApplication::translate("modify", "Else", Q_NULLPTR));
        maleRadioBtn->setText(QApplication::translate("modify", "Male", Q_NULLPTR));
        emailLineEdit->setPlaceholderText(QString());
        label_2->setText(QApplication::translate("modify", "New Password:", Q_NULLPTR));
        mottoLineEdit->setPlaceholderText(QString());
        label_4->setText(QApplication::translate("modify", "NewPassword Again:", Q_NULLPTR));
        label_7->setText(QApplication::translate("modify", "Email:", Q_NULLPTR));
        label_6->setText(QApplication::translate("modify", "Phone:", Q_NULLPTR));
        label_8->setText(QApplication::translate("modify", "Motto:", Q_NULLPTR));
        label_5->setText(QApplication::translate("modify", "Realname:", Q_NULLPTR));
        realLineEdit->setText(QString());
        realLineEdit->setPlaceholderText(QString());
        pwdLineEdit->setPlaceholderText(QString());
        label_13->setText(QApplication::translate("modify", "*", Q_NULLPTR));
        label_10->setText(QApplication::translate("modify", "Password:", Q_NULLPTR));
        userLabel->setText(QApplication::translate("modify", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class modify: public Ui_modify {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFY_H
