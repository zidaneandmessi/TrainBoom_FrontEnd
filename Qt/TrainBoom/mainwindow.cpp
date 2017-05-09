#include "mainwindow.h"
#include "qmessagebox.h"
#include "ui_mainwindow.h"
#include "logindialog.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

void MainWindow::receive(QJsonObject t)
{
    usrInfo = t;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    box.exec();
}

void MainWindow::on_action_UL_triggered()
{
    usrInfo = QJsonObject();
    this->hide();
    LoginDialog *w = new LoginDialog;
    w->exec();
}
