#include "mainwindow.h"
#include "qmessagebox.h"
#include "ui_mainwindow.h"
#include "logindialog.h"
#include "modify.h"
#include "query.h"
#include "order.h"
#include "buy.h"
#include "user.h"
#include "start.h"
#include "delete.h"
#include "qjsonarray.h"
#include "qtablewidget.h"
#include <Qstring>
#include "qnetwork.h"
#include <QUrl>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonObject>
#include <QByteArray>
#include <QJsonDocument>

const QString website = "http://39.108.7.208:3000";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    for(int i = 0; i < 6; i++)
        ui->tableWidget->horizontalHeader()->setSectionResizeMode(i, QHeaderView::ResizeToContents);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->setAlternatingRowColors(true);
    ui->tableWidget->setSortingEnabled(true);
    ui->progressBar->hide();
}
void MainWindow::setUI()
{
    if (usrInfo["isRoot"].toBool() == true)
        ui->welcomeLabel->setText("欢迎尊贵的管理员用户" + usrInfo["username"].toString() + "!");
    else
        ui->welcomeLabel->setText("欢迎, " + usrInfo["username"].toString() + "!");
    ui->tableWidget->setRowCount(0);
}

void MainWindow::receiveUser(QJsonObject t)
{
    usrInfo = t;
}
void MainWindow::receiveRoutes(QJsonObject t)
{
    routes = t;
}


MainWindow::~MainWindow()
{
    delete ui;
}

QJsonObject MainWindow::sendUser()
{
    return usrInfo;
}
QJsonObject MainWindow::sendRoutes()
{
    return routes;
}

void MainWindow::on_action_UL_triggered()
{
    usrInfo = QJsonObject();
    this->close();
    LoginDialog *w = new LoginDialog;
    if (w->exec() == QDialog::Accepted)
    {
        receiveUser(w->sendUser());
        this->setUI();
        this->show();
    }
}

void MainWindow::on_action_UM_triggered()
{
    modify *w = new modify;
    w->receiveUser(this->sendUser());
    w->setUI();
    if(w->exec() == QDialog::Accepted)
        receiveUser(w->sendUser());
}

int routeIndex[2001];

void MainWindow::on_queryButton_clicked()
{
    Query *w = new Query;
    if(w->exec() == QDialog::Accepted)
    {
        receiveRoutes(w->sendRoutes());
        int num = routes["routeIntervals"].toArray().size();
        ui->progressBar->setRange(0, num - 1);
        ui->progressBar->setValue(0);
        ui->tableWidget->setRowCount(0);
        ui->tableWidget->setSortingEnabled(false);
        if (!num)
            QMessageBox::warning(this, tr("Warning!"), tr("没有找到满足条件的车票!!!"), QMessageBox::Yes);
        else
            ui->progressBar->show();
        for (int i = 0; i < num; i++)
        {
            ui->progressBar->setValue(i);
            QString id = routes["routeIntervals"].toArray()[i].toObject()["data"].toObject()["routeId"].toString();
            QNetworkRequest queryRequest;
            queryRequest.setUrl(QUrl(website+"/routes/"+id));
            queryRequest.setRawHeader("Content-Type", "application/json");
            queryRequest.setRawHeader("Cache-Control", "no-cache");
            QNetworkAccessManager *queryManager=new QNetworkAccessManager;
            QNetworkReply *queryReply = queryManager->get(queryRequest);
            QEventLoop ev;
            connect(queryReply, SIGNAL(finished()), &ev, SLOT(quit()));
            ev.exec(QEventLoop::ExcludeUserInputEvents);
            QByteArray bt = queryReply->readAll();
            QJsonObject res = QJsonDocument::fromJson(bt).object()["data"].toObject();
            QString train = res["name"].toString();

            QJsonObject t;
            t.insert("l", routes["routeIntervals"].toArray()[i].toObject()["data"].toObject()["l"].toInt());
            t.insert("r", routes["routeIntervals"].toArray()[i].toObject()["data"].toObject()["r"].toInt());
            QNetworkRequest queryRequest2;
            queryRequest2.setUrl(QUrl(website+"/routes/"+id+"/tickets"));
            queryRequest2.setRawHeader("Content-Type", "application/json");
            queryRequest2.setRawHeader("Cache-Control", "no-cache");
            QNetworkAccessManager *queryManager2=new QNetworkAccessManager;
            QNetworkReply *queryReply2 = queryManager2->post(queryRequest2, QJsonDocument(t).toJson());
            connect(queryReply2, SIGNAL(finished()), &ev, SLOT(quit()));
            ev.exec(QEventLoop::ExcludeUserInputEvents);
            bt = queryReply2->readAll();
            res = QJsonDocument::fromJson(bt).object();
            QJsonObject tickets = res["tickets"].toObject();
            QString stTime = res["startStation"].toObject()["leaveTime"].toString(), enTime = res["endStation"].toObject()["arriveTime"].toString();

            QJsonObject::iterator it;
            for (it = tickets.begin(); it != tickets.end(); it++)
                if((*it).toObject()["nonstop"].toBool() == false)
                {
                    int rows = ui->tableWidget->rowCount();
                    routeIndex[rows] = i;
                    ui->tableWidget->insertRow(rows);
                    ui->tableWidget->setItem(rows, 0, new QTableWidgetItem(train));
                    ui->tableWidget->setItem(rows, 1, new QTableWidgetItem(stTime));
                    ui->tableWidget->setItem(rows, 2, new QTableWidgetItem(enTime));
                    ui->tableWidget->setItem(rows, 3, new QTableWidgetItem(it.key()));
                    ui->tableWidget->setItem(rows, 4, new QTableWidgetItem(QString::number((*it).toObject()["price"].toDouble(), 10, 2)));
                    ui->tableWidget->setItem(rows, 5, new QTableWidgetItem(QString::number((*it).toObject()["number"].toInt(), 10)));
                    ui->tableWidget->show();
                }
        }
        ui->tableWidget->setSortingEnabled(true);
        ui->progressBar->hide();
    }
}

void MainWindow::on_pushButton_clicked()
{
    if (!ui->tableWidget->selectedItems().size())
        QMessageBox::warning(this, tr("Warning!"), tr("请选择车票!!!"), QMessageBox::Yes);
    else
    {
        int no = ui->tableWidget->row(ui->tableWidget->selectedItems().at(0));
        Buy *w = new Buy;
        w->receiveUser(this->sendUser());
        w->receiveNo(routeIndex[no]);
        w->receiveRoutes(this->sendRoutes());
        w->receiveTicketType(ui->tableWidget->item(no, 3)->text());
        w->receivePrice(ui->tableWidget->item(no, 4)->text().toDouble());
        w->setUI();
        if (w->exec() == QDialog::Accepted)
        {
            int num = w->sendNum();
            int t = ui->tableWidget->item(no, 5)->text().toInt() - num;
            ui->tableWidget->setItem(no, 5, new QTableWidgetItem(QString::number(t, 10)));
        }
    }
}

void MainWindow::on_orderButton_clicked()
{
    Order *w = new Order;
    w->receiveUser(this->sendUser());
    w->setUI();
    w->exec();
}

void MainWindow::on_startButton_clicked()
{
    if (usrInfo["isRoot"] == false)
        QMessageBox::warning(this, tr("Warning!"), tr("你没有权限!!!"), QMessageBox::Yes);
    else
    {
        Start *w = new Start;
        w->exec();
    }
}


void MainWindow::on_stopButton_clicked()
{
    if (usrInfo["isRoot"] == false)
        QMessageBox::warning(this, tr("Warning!"), tr("你没有权限!!!"), QMessageBox::Yes);
    else if (!ui->tableWidget->selectedItems().size())
        QMessageBox::warning(this, tr("Warning!"), tr("请选择车票!!!"), QMessageBox::Yes);

    else
    {
        int no = ui->tableWidget->row(ui->tableWidget->selectedItems().at(0));
        QString id = routes["routeIntervals"].toArray()[routeIndex[no]].toObject()["data"].toObject()["routeId"].toString();
        QNetworkRequest startRequest;
        startRequest.setUrl(QUrl(website+"/routes/"+id+"/stop"));
        startRequest.setRawHeader("Content-Type", "application/json");
        startRequest.setRawHeader("Cache-Control", "no-cache");
        QNetworkAccessManager *startManager=new QNetworkAccessManager;
        QNetworkReply *startReply = startManager->get(startRequest);
        QEventLoop ev;
        connect(startReply, SIGNAL(finished()), &ev, SLOT(quit()));
        ev.exec(QEventLoop::ExcludeUserInputEvents);
        QByteArray bt = startReply->readAll();
        QJsonObject res = QJsonDocument::fromJson(bt).object();
        if (res["type"].toString() == "success")
            QMessageBox::warning(this, tr("Warning!"), tr("停止出售成功!!!"), QMessageBox::Yes);
        else
            QMessageBox::warning(this, tr("Warning!"), tr("停止出售失败!!!"), QMessageBox::Yes);

    }
}

void MainWindow::on_pushButton_2_clicked()//查询用户
{
    User *w = new User;
    w->exec();
}

void MainWindow::on_pushButton_3_clicked()
{
    Delete *w = new Delete;
    w->exec();
}
