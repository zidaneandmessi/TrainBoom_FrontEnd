/********************************************************************************
** Form generated from reading UI file 'add.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADD_H
#define UI_ADD_H

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

class Ui_Add
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QTableWidget *tableWidget;
    QLabel *label_3;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QLabel *label_2;

    void setupUi(QDialog *Add)
    {
        if (Add->objectName().isEmpty())
            Add->setObjectName(QStringLiteral("Add"));
        Add->resize(982, 540);
        pushButton = new QPushButton(Add);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(340, 490, 93, 28));
        pushButton_2 = new QPushButton(Add);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(570, 490, 93, 28));
        tableWidget = new QTableWidget(Add);
        if (tableWidget->columnCount() < 7)
            tableWidget->setColumnCount(7);
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
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(50, 100, 881, 351));
        label_3 = new QLabel(Add);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(370, 10, 251, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font.setPointSize(18);
        label_3->setFont(font);
        label = new QLabel(Add);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(390, 60, 72, 21));
        lineEdit = new QLineEdit(Add);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(480, 60, 113, 21));
        pushButton_3 = new QPushButton(Add);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(680, 60, 71, 21));
        pushButton_4 = new QPushButton(Add);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(770, 60, 71, 21));
        label_2 = new QLabel(Add);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(240, 460, 511, 16));

        retranslateUi(Add);

        QMetaObject::connectSlotsByName(Add);
    } // setupUi

    void retranslateUi(QDialog *Add)
    {
        Add->setWindowTitle(QApplication::translate("Add", "Dialog", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Add", "\347\241\256\345\256\232", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Add", "\350\277\224\345\233\236", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Add", "\347\253\231\345\220\215", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Add", "\345\210\260\350\276\276\346\227\266\351\227\264", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Add", "\345\207\272\345\217\221\346\227\266\351\227\264", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("Add", "\351\207\214\347\250\213", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("Add", "\345\272\247\344\275\215\347\261\273\345\236\213", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("Add", "\345\215\225\344\273\267", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("Add", "\346\225\260\351\207\217", Q_NULLPTR));
        label_3->setText(QApplication::translate("Add", "\346\267\273\345\212\240/\344\277\256\346\224\271\350\277\220\350\241\214\350\256\241\345\210\222", Q_NULLPTR));
        label->setText(QApplication::translate("Add", "\350\275\246\346\254\241\347\274\226\345\217\267:", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("Add", "\346\267\273\345\212\240\347\253\231", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("Add", "\345\210\240\351\231\244\347\253\231", Q_NULLPTR));
        label_2->setText(QApplication::translate("Add", "\346\263\250: \350\265\267\347\202\271\347\253\231\347\232\204\351\207\214\347\250\213\343\200\201\350\275\246\347\245\250\344\277\241\346\201\257\343\200\201\345\210\260\350\276\276\346\227\266\351\227\264\357\274\214\344\273\245\345\217\212\347\273\210\347\202\271\347\253\231\347\232\204\345\207\272\345\217\221\346\227\266\351\227\264\350\257\267\347\225\231\347\251\272\343\200\202", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Add: public Ui_Add {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_H
