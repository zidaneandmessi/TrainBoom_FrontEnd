/********************************************************************************
** Form generated from reading UI file 'ticket.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TICKET_H
#define UI_TICKET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_Ticket
{
public:
    QLabel *label_3;
    QLabel *label;
    QTableWidget *tableWidget;
    QPushButton *pushButton;

    void setupUi(QDialog *Ticket)
    {
        if (Ticket->objectName().isEmpty())
            Ticket->setObjectName(QStringLiteral("Ticket"));
        Ticket->resize(844, 365);
        label_3 = new QLabel(Ticket);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(360, 10, 121, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font.setPointSize(18);
        label_3->setFont(font);
        label = new QLabel(Ticket);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(380, 60, 72, 15));
        tableWidget = new QTableWidget(Ticket);
        if (tableWidget->rowCount() < 4)
            tableWidget->setRowCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem3);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(40, 90, 761, 211));
        pushButton = new QPushButton(Ticket);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(370, 320, 93, 28));

        retranslateUi(Ticket);

        QMetaObject::connectSlotsByName(Ticket);
    } // setupUi

    void retranslateUi(QDialog *Ticket)
    {
        Ticket->setWindowTitle(QApplication::translate("Ticket", "Dialog", Q_NULLPTR));
        label_3->setText(QApplication::translate("Ticket", "\345\210\227\350\275\246\344\277\241\346\201\257", Q_NULLPTR));
        label->setText(QApplication::translate("Ticket", "TextLabel", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Ticket", "\347\253\231\345\220\215", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Ticket", "\351\207\214\347\250\213", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Ticket", "\345\207\272\345\217\221\346\227\266\351\227\264", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("Ticket", "\345\210\260\350\276\276\346\227\266\351\227\264", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Ticket", "\350\277\224\345\233\236", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Ticket: public Ui_Ticket {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TICKET_H
