#include "mainwindow.h"
#include "qmessagebox.h"
#include "ui_mainwindow.h"
#include "logindialog.h"
#include "modify.h"
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

QJsonObject MainWindow::send()
{
    return usrInfo;
}


void MainWindow::on_pushButton_clicked()
{
    QMessageBox::warning(this, tr("Warning!"), tr("+1s"), QMessageBox::Yes);
}

void MainWindow::on_action_UL_triggered()
{
    usrInfo = QJsonObject();
    this->close();
    LoginDialog *w = new LoginDialog;
    if (w->exec() == QDialog::Accepted)
    {
        receive(w->send());
        this->show();
    }
}

void MainWindow::on_action_UM_triggered()
{
    this->hide();
    modify *w = new modify;
    w->receive(this->send());
    w->setUI();
    if(w->exec() == QDialog::Accepted)
        receive(w->send());
    this->show();
}
