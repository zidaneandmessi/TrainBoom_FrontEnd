#include "mainwindow.h"
#include "qmessagebox.h"
#include "ui_mainwindow.h"
#include "logindialog.h"
#include "modify.h"
#include "admin.h"
#include "query.h"
#include "order.h"
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
#include <QRegExpValidator>

const QString website = "http://39.108.7.208:3000";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    for(int i = 0; i < 6; i++)
        ui->tableWidget->horizontalHeader()->setSectionResizeMode(i, QHeaderView::ResizeToContents);
    ui->progressBar->hide();
    QRegExp regExp("[0-9\-\\\_]{4}");
    QRegExpValidator *pRevalidotor = new QRegExpValidator(regExp, this);
    ui->noLineEdit->setValidator(new QRegExpValidator(regExp, this));
    ui->numLineEdit->setValidator(new QRegExpValidator(regExp, this));
}
void MainWindow::setUI()
{
    ui->welcomeLabel->setText("Welcome, " + usrInfo["username"].toString() + "!");
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


void MainWindow::on_action_UL_triggered()
{
    usrInfo = QJsonObject();
    this->close();
    LoginDialog *w = new LoginDialog;
    if (w->exec() == QDialog::Accepted)
    {
        receiveUser(w->sendUser());
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

void MainWindow::on_adminButton_clicked()
{
    if(usrInfo["isRoot"] == false)
        QMessageBox::warning(this, tr("Warning!"), tr("你没有权限!!!"), QMessageBox::Yes);
    else
    {
        Admin *w = new Admin;
        w->exec();
    }
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
                    routeIndex[rows + 1] = i;
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
        ui->progressBar->hide();
    }
}

void MainWindow::on_pushButton_clicked()
{
    int rows = ui->tableWidget->rowCount();
    int no = ui->noLineEdit->text().toInt(), num = ui->numLineEdit->text().toInt();
    if (no <= 0 || no > rows)
        QMessageBox::warning(this, tr("Warning!"), tr("序号不合法!!!"), QMessageBox::Yes);
    else if (num <= 0)
        QMessageBox::warning(this, tr("Warning!"), tr("数量不合法!!!"), QMessageBox::Yes);
    else
    {
        QString id;
        QJsonObject t;
        t.insert("username", usrInfo["username"]);
        QNetworkRequest chkusrRequest;
        chkusrRequest.setUrl(QUrl(website+"/users/username"));
        chkusrRequest.setRawHeader("Content-Type", "application/json");
        chkusrRequest.setRawHeader("Cache-Control", "no-cache");
        QNetworkAccessManager *chkusrManager=new QNetworkAccessManager;
        QNetworkReply *chkusrReply = chkusrManager->post(chkusrRequest, QJsonDocument(t).toJson());
        QEventLoop ev;
        connect(chkusrReply, SIGNAL(finished()), &ev, SLOT(quit()));
        ev.exec(QEventLoop::ExcludeUserInputEvents);
        QByteArray bt = chkusrReply->readAll();
        QJsonObject res = QJsonDocument::fromJson(bt).object();
        if (res["type"] == "error") id = QString("");
        else id = res["userId"].toString();

        QJsonObject t2;
        t2.insert("l", routes["routeIntervals"].toArray()[routeIndex[no]].toObject()["data"].toObject()["l"].toInt());
        t2.insert("r", routes["routeIntervals"].toArray()[routeIndex[no]].toObject()["data"].toObject()["r"].toInt());
        t2.insert("ticketNumber", num);
        t2.insert("userId", id);
        t2.insert("ticketType", ui->tableWidget->item(no - 1, 3)->text());
        QNetworkRequest bookRequest;
        bookRequest.setUrl(QUrl(website+"/routes/"+routes["routeIntervals"].toArray()[routeIndex[no]].toObject()["data"].toObject()["routeId"].toString()+"/tickets"));
        bookRequest.setRawHeader("Content-Type", "application/json");
        bookRequest.setRawHeader("Cache-Control", "no-cache");
        QNetworkAccessManager *bookManager=new QNetworkAccessManager;
        QNetworkReply *bookReply = bookManager->put(bookRequest, QJsonDocument(t2).toJson());
        connect(bookReply, SIGNAL(finished()), &ev, SLOT(quit()));
        ev.exec(QEventLoop::ExcludeUserInputEvents);
        bt = bookReply->readAll();
        res = QJsonDocument::fromJson(bt).object();

        if(res["type"] == "error")
            QMessageBox::warning(this, tr("Warning!"), tr("车票数量不足!!!"), QMessageBox::Yes);
        else
        {
            QMessageBox::warning(this, tr("Warning!"), tr("订票成功,你的订单号为")+res["id"].toString()+tr("!!!"), QMessageBox::Yes);
            int t = ui->tableWidget->item(no - 1, 5)->text().toInt() - num;
            ui->tableWidget->setItem(no - 1, 5, new QTableWidgetItem(QString::number(t, 10)));
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
