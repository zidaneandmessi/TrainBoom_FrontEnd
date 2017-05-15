/********************************************************************************
** Form generated from reading UI file 'order.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ORDER_H
#define UI_ORDER_H

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

class Ui_Order
{
public:
    QLabel *label_3;
    QTableWidget *tableWidget;
    QPushButton *pushButton;
    QPushButton *refundButton;
    QLineEdit *lineEdit;
    QLabel *label;

    void setupUi(QDialog *Order)
    {
        if (Order->objectName().isEmpty())
            Order->setObjectName(QStringLiteral("Order"));
        Order->resize(772, 529);
        label_3 = new QLabel(Order);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(320, 10, 121, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font.setPointSize(18);
        label_3->setFont(font);
        tableWidget = new QTableWidget(Order);
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
        tableWidget->setGeometry(QRect(20, 70, 721, 371));
        tableWidget->setLayoutDirection(Qt::LeftToRight);
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        pushButton = new QPushButton(Order);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(540, 470, 93, 28));
        refundButton = new QPushButton(Order);
        refundButton->setObjectName(QStringLiteral("refundButton"));
        refundButton->setGeometry(QRect(230, 467, 93, 31));
        lineEdit = new QLineEdit(Order);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(120, 470, 81, 21));
        label = new QLabel(Order);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 470, 72, 21));

        retranslateUi(Order);

        QMetaObject::connectSlotsByName(Order);
    } // setupUi

    void retranslateUi(QDialog *Order)
    {
        Order->setWindowTitle(QApplication::translate("Order", "Dialog", Q_NULLPTR));
        label_3->setText(QApplication::translate("Order", "\346\210\221\347\232\204\350\256\242\345\215\225", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Order", "\350\275\246\346\254\241", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Order", "\350\265\267\347\202\271\347\253\231", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Order", "\347\273\210\347\202\271\347\253\231", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("Order", "\345\207\272\345\217\221\346\227\266\351\227\264", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("Order", "\345\210\260\350\276\276\346\227\266\351\227\264", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("Order", "\345\272\247\344\275\215\347\261\273\345\236\213", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("Order", "\346\225\260\351\207\217", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("Order", "\351\207\221\351\242\235", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("Order", "\345\272\217\345\217\267", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Order", "\350\277\224\345\233\236", Q_NULLPTR));
        refundButton->setText(QApplication::translate("Order", "\351\200\200\347\245\250", Q_NULLPTR));
        label->setText(QApplication::translate("Order", "\351\200\200\347\245\250\346\225\260\351\207\217:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Order: public Ui_Order {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ORDER_H
