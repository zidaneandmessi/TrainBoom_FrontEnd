/********************************************************************************
** Form generated from reading UI file 'user.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USER_H
#define UI_USER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_User
{
public:
    QLabel *label_3;
    QLabel *label_7;
    QLabel *label_9;
    QLabel *label;
    QLabel *label_8;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *userLineEdit;
    QPushButton *pushButton;
    QTableWidget *tableWidget;
    QLabel *realName;
    QLabel *phone;
    QLabel *email;
    QLabel *motto;
    QLabel *sex;
    QPushButton *pushButton_2;
    QLabel *label_2;
    QLabel *userName;

    void setupUi(QDialog *User)
    {
        if (User->objectName().isEmpty())
            User->setObjectName(QStringLiteral("User"));
        User->resize(1131, 542);
        label_3 = new QLabel(User);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(500, 10, 131, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font.setPointSize(18);
        label_3->setFont(font);
        label_7 = new QLabel(User);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(39, 270, 61, 20));
        label_9 = new QLabel(User);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(39, 330, 51, 20));
        label = new QLabel(User);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(130, 100, 91, 16));
        label_8 = new QLabel(User);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(39, 300, 71, 20));
        label_5 = new QLabel(User);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(39, 210, 71, 20));
        label_6 = new QLabel(User);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(39, 240, 61, 20));
        userLineEdit = new QLineEdit(User);
        userLineEdit->setObjectName(QStringLiteral("userLineEdit"));
        userLineEdit->setGeometry(QRect(200, 100, 113, 21));
        pushButton = new QPushButton(User);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(320, 100, 41, 21));
        tableWidget = new QTableWidget(User);
        if (tableWidget->columnCount() < 9)
            tableWidget->setColumnCount(9);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(450, 80, 641, 371));
        tableWidget->setLayoutDirection(Qt::LeftToRight);
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        realName = new QLabel(User);
        realName->setObjectName(QStringLiteral("realName"));
        realName->setGeometry(QRect(119, 210, 321, 21));
        phone = new QLabel(User);
        phone->setObjectName(QStringLiteral("phone"));
        phone->setGeometry(QRect(119, 240, 321, 21));
        email = new QLabel(User);
        email->setObjectName(QStringLiteral("email"));
        email->setGeometry(QRect(119, 270, 321, 21));
        motto = new QLabel(User);
        motto->setObjectName(QStringLiteral("motto"));
        motto->setGeometry(QRect(119, 300, 321, 21));
        sex = new QLabel(User);
        sex->setObjectName(QStringLiteral("sex"));
        sex->setGeometry(QRect(120, 330, 121, 21));
        pushButton_2 = new QPushButton(User);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(950, 480, 93, 28));
        label_2 = new QLabel(User);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 180, 61, 16));
        userName = new QLabel(User);
        userName->setObjectName(QStringLiteral("userName"));
        userName->setGeometry(QRect(120, 180, 321, 21));

        retranslateUi(User);

        QMetaObject::connectSlotsByName(User);
    } // setupUi

    void retranslateUi(QDialog *User)
    {
        User->setWindowTitle(QApplication::translate("User", "Dialog", Q_NULLPTR));
        label_3->setText(QApplication::translate("User", "\347\224\250\346\210\267\344\277\241\346\201\257", Q_NULLPTR));
        label_7->setText(QApplication::translate("User", "\351\202\256\347\256\261:", Q_NULLPTR));
        label_9->setText(QApplication::translate("User", "\346\200\247\345\210\253:", Q_NULLPTR));
        label->setText(QApplication::translate("User", "\347\224\250\346\210\267\345\220\215:", Q_NULLPTR));
        label_8->setText(QApplication::translate("User", "\344\270\252\346\200\247\347\255\276\345\220\215:", Q_NULLPTR));
        label_5->setText(QApplication::translate("User", "\347\234\237\345\256\236\345\247\223\345\220\215:", Q_NULLPTR));
        label_6->setText(QApplication::translate("User", "\347\224\265\350\257\235:", Q_NULLPTR));
        pushButton->setText(QApplication::translate("User", "\346\237\245\350\257\242", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("User", "\350\275\246\346\254\241", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("User", "\350\265\267\347\202\271\347\253\231", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("User", "\347\273\210\347\202\271\347\253\231", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("User", "\345\207\272\345\217\221\346\227\266\351\227\264", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("User", "\345\210\260\350\276\276\346\227\266\351\227\264", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("User", "\345\272\247\344\275\215\347\261\273\345\236\213", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("User", "\346\225\260\351\207\217", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("User", "\351\207\221\351\242\235", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("User", "id", Q_NULLPTR));
        realName->setText(QString());
        phone->setText(QString());
        email->setText(QString());
        motto->setText(QString());
        sex->setText(QString());
        pushButton_2->setText(QApplication::translate("User", "\350\277\224\345\233\236", Q_NULLPTR));
        label_2->setText(QApplication::translate("User", "\347\224\250\346\210\267\345\220\215:", Q_NULLPTR));
        userName->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class User: public Ui_User {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USER_H
