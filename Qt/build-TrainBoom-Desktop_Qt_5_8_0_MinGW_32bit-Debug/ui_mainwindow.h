/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_UM;
    QAction *action_UL;
    QAction *action_UQ;
    QAction *action_HA;
    QWidget *centralWidget;
    QPushButton *pushButton;
    QLineEdit *numLineEdit;
    QLabel *label;
    QLabel *label_3;
    QPushButton *queryButton;
    QTableWidget *tableWidget;
    QProgressBar *progressBar;
    QLabel *label_2;
    QLineEdit *noLineEdit;
    QPushButton *adminButton;
    QPushButton *orderButton;
    QLabel *welcomeLabel;
    QMenuBar *menuBar;
    QMenu *menu_U;
    QMenu *menu_H;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(949, 615);
        action_UM = new QAction(MainWindow);
        action_UM->setObjectName(QStringLiteral("action_UM"));
        action_UL = new QAction(MainWindow);
        action_UL->setObjectName(QStringLiteral("action_UL"));
        action_UQ = new QAction(MainWindow);
        action_UQ->setObjectName(QStringLiteral("action_UQ"));
        action_HA = new QAction(MainWindow);
        action_HA->setObjectName(QStringLiteral("action_HA"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(850, 520, 61, 21));
        numLineEdit = new QLineEdit(centralWidget);
        numLineEdit->setObjectName(QStringLiteral("numLineEdit"));
        numLineEdit->setGeometry(QRect(770, 520, 41, 21));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(720, 520, 38, 21));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(350, 20, 240, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font.setPointSize(18);
        label_3->setFont(font);
        queryButton = new QPushButton(centralWidget);
        queryButton->setObjectName(QStringLiteral("queryButton"));
        queryButton->setGeometry(QRect(40, 110, 93, 28));
        tableWidget = new QTableWidget(centralWidget);
        if (tableWidget->columnCount() < 6)
            tableWidget->setColumnCount(6);
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
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(170, 80, 741, 371));
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(170, 470, 781, 23));
        progressBar->setValue(24);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(610, 520, 41, 21));
        noLineEdit = new QLineEdit(centralWidget);
        noLineEdit->setObjectName(QStringLiteral("noLineEdit"));
        noLineEdit->setGeometry(QRect(660, 520, 41, 21));
        adminButton = new QPushButton(centralWidget);
        adminButton->setObjectName(QStringLiteral("adminButton"));
        adminButton->setGeometry(QRect(40, 190, 93, 28));
        orderButton = new QPushButton(centralWidget);
        orderButton->setObjectName(QStringLiteral("orderButton"));
        orderButton->setGeometry(QRect(40, 150, 93, 28));
        welcomeLabel = new QLabel(centralWidget);
        welcomeLabel->setObjectName(QStringLiteral("welcomeLabel"));
        welcomeLabel->setGeometry(QRect(10, 530, 511, 21));
        MainWindow->setCentralWidget(centralWidget);
        pushButton->raise();
        numLineEdit->raise();
        label->raise();
        label_3->raise();
        queryButton->raise();
        tableWidget->raise();
        progressBar->raise();
        adminButton->raise();
        label_2->raise();
        noLineEdit->raise();
        orderButton->raise();
        welcomeLabel->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 949, 26));
        menu_U = new QMenu(menuBar);
        menu_U->setObjectName(QStringLiteral("menu_U"));
        menu_H = new QMenu(menuBar);
        menu_H->setObjectName(QStringLiteral("menu_H"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(queryButton, adminButton);
        QWidget::setTabOrder(adminButton, tableWidget);
        QWidget::setTabOrder(tableWidget, noLineEdit);
        QWidget::setTabOrder(noLineEdit, numLineEdit);
        QWidget::setTabOrder(numLineEdit, pushButton);

        menuBar->addAction(menu_U->menuAction());
        menuBar->addAction(menu_H->menuAction());
        menu_U->addAction(action_UM);
        menu_U->addSeparator();
        menu_U->addAction(action_UL);
        menu_U->addAction(action_UQ);
        menu_H->addAction(action_HA);

        retranslateUi(MainWindow);
        QObject::connect(action_UQ, SIGNAL(triggered()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\345\260\233\347\204\261\350\275\237\347\263\273\347\273\237\346\265\213\350\257\225\347\211\210", Q_NULLPTR));
        action_UM->setText(QApplication::translate("MainWindow", "\344\277\256\346\224\271(M)", Q_NULLPTR));
        action_UL->setText(QApplication::translate("MainWindow", "\346\263\250\351\224\200(&L)", Q_NULLPTR));
        action_UQ->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272(&Q)", Q_NULLPTR));
        action_HA->setText(QApplication::translate("MainWindow", "\345\205\263\344\272\216(&A)", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "\350\264\255\344\271\260", Q_NULLPTR));
        numLineEdit->setText(QString());
        label->setText(QApplication::translate("MainWindow", "\346\225\260\351\207\217:", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "\345\260\233\347\204\261\350\275\237\347\263\273\347\273\237\346\265\213\350\257\225\347\211\210", Q_NULLPTR));
        queryButton->setText(QApplication::translate("MainWindow", "\346\237\245\350\257\242", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "\350\275\246\346\254\241", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "\345\207\272\345\217\221\346\227\266\351\227\264", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "\345\210\260\350\276\276\346\227\266\351\227\264", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "\345\272\247\344\275\215\347\261\273\345\236\213", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "\344\273\267\346\240\274", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "\345\211\251\344\275\231\346\225\260\351\207\217", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "\345\272\217\345\217\267:", Q_NULLPTR));
        adminButton->setText(QApplication::translate("MainWindow", "\347\256\241\347\220\206\347\263\273\347\273\237", Q_NULLPTR));
        orderButton->setText(QApplication::translate("MainWindow", "\346\210\221\347\232\204\350\256\242\345\215\225", Q_NULLPTR));
        welcomeLabel->setText(QString());
        menu_U->setTitle(QApplication::translate("MainWindow", "\347\224\250\346\210\267(&U)", Q_NULLPTR));
        menu_H->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251(&H)", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
