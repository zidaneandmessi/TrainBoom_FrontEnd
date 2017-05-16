/********************************************************************************
** Form generated from reading UI file 'query.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUERY_H
#define UI_QUERY_H

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

class Ui_Query
{
public:
    QLabel *label_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_4;
    QLineEdit *stLineEdit;
    QLineEdit *enLineEdit;
    QDateEdit *dateEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *Query)
    {
        if (Query->objectName().isEmpty())
            Query->setObjectName(QStringLiteral("Query"));
        Query->resize(400, 300);
        label_3 = new QLabel(Query);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(160, 20, 61, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font.setPointSize(18);
        label_3->setFont(font);
        label = new QLabel(Query);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 90, 72, 21));
        label_2 = new QLabel(Query);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(70, 140, 72, 21));
        label_4 = new QLabel(Query);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(70, 190, 72, 21));
        stLineEdit = new QLineEdit(Query);
        stLineEdit->setObjectName(QStringLiteral("stLineEdit"));
        stLineEdit->setGeometry(QRect(150, 90, 151, 21));
        enLineEdit = new QLineEdit(Query);
        enLineEdit->setObjectName(QStringLiteral("enLineEdit"));
        enLineEdit->setGeometry(QRect(150, 140, 151, 21));
        dateEdit = new QDateEdit(Query);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setGeometry(QRect(150, 190, 110, 22));
        pushButton = new QPushButton(Query);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(80, 240, 93, 28));
        pushButton_2 = new QPushButton(Query);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(220, 240, 93, 28));

        retranslateUi(Query);

        QMetaObject::connectSlotsByName(Query);
    } // setupUi

    void retranslateUi(QDialog *Query)
    {
        Query->setWindowTitle(QApplication::translate("Query", "Dialog", Q_NULLPTR));
        label_3->setText(QApplication::translate("Query", "\346\237\245\350\257\242", Q_NULLPTR));
        label->setText(QApplication::translate("Query", "\350\265\267\347\202\271\347\253\231:", Q_NULLPTR));
        label_2->setText(QApplication::translate("Query", "\347\273\210\347\202\271\347\253\231:", Q_NULLPTR));
        label_4->setText(QApplication::translate("Query", "\346\227\245\346\234\237:", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Query", "\346\237\245\350\257\242", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Query", "\350\277\224\345\233\236", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Query: public Ui_Query {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUERY_H
