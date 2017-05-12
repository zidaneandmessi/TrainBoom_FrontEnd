#include "order.h"
#include "ui_order.h"
#include "qmessagebox.h"
#include "qjsonobject.h"
#include "qbytearray.h"
#include "qjsondocument.h"
#include "qradiobutton.h"
#include "qtablewidget.h"
#include "qstring.h"
#include "qurl.h"
#include "qnetwork.h"
#include "qtextcodec.h"
#include "qjsonarray.h"
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QNetworkReply>

const QString website = "http://39.108.7.208:3000";



Order::Order(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Order)
{
    ui->setupUi(this);
    for(int i = 0; i < 8; i++)
        ui->tableWidget->horizontalHeader()->setSectionResizeMode(i, QHeaderView::ResizeToContents);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->setAlternatingRowColors(true);
}

void Order::receiveUser(QJsonObject t)
{
    usrInfo = t;
}

void Order::setUI()
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

Order::~Order()
{
    delete ui;
}

void Order::on_pushButton_clicked()
{
    reject();
}
