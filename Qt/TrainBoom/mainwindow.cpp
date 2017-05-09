#include "mainwindow.h"
#include "qmessagebox.h"
#include "ui_mainwindow.h"
#include "logindialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QMessageBox box(QMessageBox::NoIcon,"苟","+1s",QMessageBox::Yes);
    box.setIconPixmap(QPixmap("1.png"));
    box.exec();
}

void MainWindow::on_action_UL_triggered()
{
    this->hide();
    LoginDialog *w = new LoginDialog;
    w->exec();
}
