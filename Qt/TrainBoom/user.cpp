#include "user.h"
#include "ui_user.h"
#include "qjsonobject.h"
#include "qjsondocument.h"
#include "register.h"
#include "qtextcodec.h"
#include "mainwindow.h"
#include "qtablewidget.h"
#include "qmessagebox.h"
#include "qjsonarray.h"
#include <QUrl>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <Qstring>

const QString website = "http://39.108.7.208:3000";

User::User(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::User)
{
    ui->setupUi(this);
    ui->userName->setWordWrap(true);
    ui->userName->setAlignment(Qt::AlignTop);
    ui->realName->setWordWrap(true);
    ui->realName->setAlignment(Qt::AlignTop);
    ui->phone->setWordWrap(true);
    ui->phone->setAlignment(Qt::AlignTop);
    ui->email->setWordWrap(true);
    ui->email->setAlignment(Qt::AlignTop);
    ui->motto->setWordWrap(true);
    ui->motto->setAlignment(Qt::AlignTop);
    for(int i = 0; i < 8; i++)
        ui->tableWidget->horizontalHeader()->setSectionResizeMode(i, QHeaderView::ResizeToContents);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->setAlternatingRowColors(true);
    ui->tableWidget->setSortingEnabled(true);
}

User::~User()
{
    delete ui;
}

void User::on_pushButton_2_clicked()
{
    this->close();
}

void User::on_pushButton_clicked()
{
    QString id;
    QJsonObject t;
    t.insert("username", ui->userLineEdit->text());
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
    if (res.isEmpty())
        QMessageBox::warning(this, tr("Warning!"), tr("连接服务器失败!!!"), QMessageBox::Yes);
    else if (res["type"] == "error")
        QMessageBox::warning(this, tr("Warning!"), tr("查询失败!!!") + res["data"].toObject()["errMsg"].toString(), QMessageBox::Yes);
    else
    {
        id = res["userId"].toString();
        ui->tableWidget->setRowCount(0);
        QNetworkRequest modRequest;
        modRequest.setUrl(QUrl(website+"/users/"+id));
        modRequest.setRawHeader("Content-Type", "application/json");
        modRequest.setRawHeader("Cache-Control", "no-cache");
        QNetworkAccessManager *modManager=new QNetworkAccessManager;
        QNetworkReply *modReply = modManager->get(modRequest);
        connect(modReply, SIGNAL(finished()), &ev, SLOT(quit()));
        ev.exec(QEventLoop::ExcludeUserInputEvents);
        bt = modReply->readAll();
        res = QJsonDocument::fromJson(bt).object()["data"].toObject();

        ui->userName->setText(res["username"].toString());
        ui->realName->setText(res["realname"].toString());
        ui->phone->setText(res["phone"].toString());
        ui->email->setText(res["email"].toString());
        ui->motto->setText(res["motto"].toString());
        int g = res["gender"].toInt();
        if (g == 0) ui->sex->setText("男");
        else if (g == 1) ui->sex->setText("女");
        else if (g == 2) ui->sex->setText("其他");

        QNetworkRequest getRequest;
        getRequest.setUrl(QUrl(website+"/users/"+id+"/orders"));
        getRequest.setRawHeader("Content-Type", "application/json");
        getRequest.setRawHeader("Cache-Control", "no-cache");
        QNetworkAccessManager *getManager=new QNetworkAccessManager;
        QNetworkReply *getReply = getManager->get(getRequest);
        connect(getReply, SIGNAL(finished()), &ev, SLOT(quit()));
        ev.exec(QEventLoop::ExcludeUserInputEvents);
        bt = getReply->readAll();
        res = QJsonDocument::fromJson(bt).object();
        QJsonArray orders = res["orders"].toArray();
        int num = orders.size();

        for (int i = 0; i < num; i++)
        {
            QString orderId = orders[i].toString();
            getRequest.setUrl(QUrl(website+"/users/"+id+"/orders/"+orderId));
            getRequest.setRawHeader("Content-Type", "application/json");
            getRequest.setRawHeader("Cache-Control", "no-cache");
            getManager=new QNetworkAccessManager;
            getReply = getManager->get(getRequest);
            connect(getReply, SIGNAL(finished()), &ev, SLOT(quit()));
            ev.exec(QEventLoop::ExcludeUserInputEvents);
            bt = getReply->readAll();
            res = QJsonDocument::fromJson(bt).object()["data"].toObject();
            int rows = ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(rows);
            ui->tableWidget->setItem(rows, 0, new QTableWidgetItem(res["routeInterval"].toObject()["routeName"].toString()));
            ui->tableWidget->setItem(rows, 1, new QTableWidgetItem(res["startStationName"].toString()));
            ui->tableWidget->setItem(rows, 2, new QTableWidgetItem(res["endStationName"].toString()));
            ui->tableWidget->setItem(rows, 5, new QTableWidgetItem(res["ticketType"].toString()));
            ui->tableWidget->setItem(rows, 6, new QTableWidgetItem(QString::number(res["ticketNumber"].toInt(), 10)));
            ui->tableWidget->setItem(rows, 7, new QTableWidgetItem(QString::number(res["ticketPrice"].toDouble(), 10, 2)));

            QJsonObject t;
            t.insert("l", res["routeInterval"].toObject()["l"].toInt());
            t.insert("r", res["routeInterval"].toObject()["r"].toInt());
            t.insert("date", res["date"].toString());
            QNetworkRequest queryRequest;
            queryRequest.setUrl(QUrl(website+"/routes/"+res["routeInterval"].toObject()["routeId"].toString()+"/tickets"));
            queryRequest.setRawHeader("Content-Type", "application/json");
            queryRequest.setRawHeader("Cache-Control", "no-cache");
            QNetworkAccessManager *queryManager=new QNetworkAccessManager;
            QNetworkReply *queryReply = queryManager->post(queryRequest, QJsonDocument(t).toJson());
            connect(queryReply, SIGNAL(finished()), &ev, SLOT(quit()));
            ev.exec(QEventLoop::ExcludeUserInputEvents);
            bt = queryReply->readAll();
            res = QJsonDocument::fromJson(bt).object();
            ui->tableWidget->setItem(rows, 3, new QTableWidgetItem(res["startStation"].toObject()["leaveTime"].toString()));
            ui->tableWidget->setItem(rows, 4, new QTableWidgetItem(res["endStation"].toObject()["arriveTime"].toString()));

            ui->tableWidget->show();
        }
    }
}

