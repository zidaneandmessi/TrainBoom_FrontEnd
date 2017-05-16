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
    QAction *actionfootoredo;
    QAction *actionzidaneandmessi;
    QAction *actionWillYoung;
    QAction *actionCreeperLin;
    QWidget *centralWidget;
    QPushButton *pushButton;
    QLabel *label_3;
    QPushButton *queryButton;
    QTableWidget *tableWidget;
    QProgressBar *progressBar;
    QPushButton *startButton;
    QPushButton *orderButton;
    QLabel *welcomeLabel;
    QPushButton *stopButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QMenuBar *menuBar;
    QMenu *menu_U;
    QMenu *menu_H;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(886, 623);
        MainWindow->setCursor(QCursor(Qt::ArrowCursor));
        action_UM = new QAction(MainWindow);
        action_UM->setObjectName(QStringLiteral("action_UM"));
        action_UL = new QAction(MainWindow);
        action_UL->setObjectName(QStringLiteral("action_UL"));
        action_UQ = new QAction(MainWindow);
        action_UQ->setObjectName(QStringLiteral("action_UQ"));
        action_HA = new QAction(MainWindow);
        action_HA->setObjectName(QStringLiteral("action_HA"));
        actionfootoredo = new QAction(MainWindow);
        actionfootoredo->setObjectName(QStringLiteral("actionfootoredo"));
        actionzidaneandmessi = new QAction(MainWindow);
        actionzidaneandmessi->setObjectName(QStringLiteral("actionzidaneandmessi"));
        actionWillYoung = new QAction(MainWindow);
        actionWillYoung->setObjectName(QStringLiteral("actionWillYoung"));
        actionCreeperLin = new QAction(MainWindow);
        actionCreeperLin->setObjectName(QStringLiteral("actionCreeperLin"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(170, 490, 641, 31));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(320, 20, 240, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font.setPointSize(18);
        label_3->setFont(font);
        queryButton = new QPushButton(centralWidget);
        queryButton->setObjectName(QStringLiteral("queryButton"));
        queryButton->setGeometry(QRect(40, 80, 101, 28));
        tableWidget = new QTableWidget(centralWidget);
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
        tableWidget->setGeometry(QRect(170, 70, 641, 381));
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(170, 460, 681, 23));
        progressBar->setValue(24);
        startButton = new QPushButton(centralWidget);
        startButton->setObjectName(QStringLiteral("startButton"));
        startButton->setGeometry(QRect(40, 160, 101, 61));
        orderButton = new QPushButton(centralWidget);
        orderButton->setObjectName(QStringLiteral("orderButton"));
        orderButton->setGeometry(QRect(40, 120, 101, 28));
        welcomeLabel = new QLabel(centralWidget);
        welcomeLabel->setObjectName(QStringLiteral("welcomeLabel"));
        welcomeLabel->setGeometry(QRect(40, 540, 511, 21));
        stopButton = new QPushButton(centralWidget);
        stopButton->setObjectName(QStringLiteral("stopButton"));
        stopButton->setGeometry(QRect(40, 230, 101, 61));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(40, 390, 101, 28));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(40, 350, 101, 28));
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(40, 430, 101, 28));
        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(40, 300, 101, 41));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 886, 26));
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
        QWidget::setTabOrder(queryButton, startButton);
        QWidget::setTabOrder(startButton, tableWidget);
        QWidget::setTabOrder(tableWidget, pushButton);

        menuBar->addAction(menu_U->menuAction());
        menuBar->addAction(menu_H->menuAction());
        menu_U->addAction(action_UM);
        menu_U->addSeparator();
        menu_U->addAction(action_UL);
        menu_U->addAction(action_UQ);
        menu_H->addAction(action_HA);
        menu_H->addSeparator();
        menu_H->addAction(actionfootoredo);
        menu_H->addAction(actionzidaneandmessi);
        menu_H->addAction(actionWillYoung);
        menu_H->addAction(actionCreeperLin);

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
        action_HA->setText(QApplication::translate("MainWindow", "Powered by", Q_NULLPTR));
        actionfootoredo->setText(QApplication::translate("MainWindow", "footoredo", Q_NULLPTR));
        actionzidaneandmessi->setText(QApplication::translate("MainWindow", "ZidaneAndMessi", Q_NULLPTR));
        actionWillYoung->setText(QApplication::translate("MainWindow", "WillYoung", Q_NULLPTR));
        actionCreeperLin->setText(QApplication::translate("MainWindow", "CreeperLin", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "\350\264\255\344\271\260", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "\345\260\233\347\204\261\350\275\237\347\263\273\347\273\237\346\255\243\345\274\217\347\211\210", Q_NULLPTR));
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
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "\345\215\225\344\273\267", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "\345\211\251\344\275\231\346\225\260\351\207\217", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "\345\272\217\345\217\267", Q_NULLPTR));
        startButton->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213\345\217\221\345\224\256\n"
"\346\237\220\350\275\246\346\254\241\346\237\220\345\244\251\n"
"\346\211\200\346\234\211\350\275\246\347\245\250", Q_NULLPTR));
        orderButton->setText(QApplication::translate("MainWindow", "\346\210\221\347\232\204\350\256\242\345\215\225", Q_NULLPTR));
        welcomeLabel->setText(QApplication::translate("MainWindow", "\345\225\212\345\225\212\345\225\212", Q_NULLPTR));
        stopButton->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242\345\207\272\345\224\256\n"
"\350\257\245\350\275\246\346\254\241\345\275\223\345\244\251\n"
"\346\211\200\346\234\211\350\275\246\347\245\250", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "\346\237\245\350\257\242\347\224\250\346\210\267\344\277\241\346\201\257", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244\346\237\220\350\275\246\346\254\241", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("MainWindow", "\346\237\245\347\234\213\347\263\273\347\273\237\346\227\245\345\277\227", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240/\344\277\256\346\224\271\n"
"\350\275\246\346\254\241", Q_NULLPTR));
        menu_U->setTitle(QApplication::translate("MainWindow", "\347\224\250\346\210\267(&U)", Q_NULLPTR));
        menu_H->setTitle(QApplication::translate("MainWindow", "\345\205\263\344\272\216(&A)", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
