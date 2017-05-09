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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
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
    QLabel *label;
    QMenuBar *menuBar;
    QMenu *menu_U;
    QMenu *menu_H;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 300);
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
        pushButton->setGeometry(QRect(150, 150, 93, 28));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(110, 80, 171, 16));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 26));
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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\350\233\244\350\233\244", Q_NULLPTR));
        action_UM->setText(QApplication::translate("MainWindow", "\344\277\256\346\224\271(M)", Q_NULLPTR));
        action_UL->setText(QApplication::translate("MainWindow", "\346\263\250\351\224\200(&L)", Q_NULLPTR));
        action_UQ->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272(&Q)", Q_NULLPTR));
        action_HA->setText(QApplication::translate("MainWindow", "\345\205\263\344\272\216(&A)", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "\345\275\223\347\204\266\346\273\213\347\243\201\344\272\206", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\350\221\243\345\205\210\347\224\237\350\277\236\344\273\273\344\275\240\346\273\213\344\270\215\346\273\213\347\243\201\345\225\212", Q_NULLPTR));
        menu_U->setTitle(QApplication::translate("MainWindow", "\347\224\250\346\210\267(&U)", Q_NULLPTR));
        menu_H->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251(&H)", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
