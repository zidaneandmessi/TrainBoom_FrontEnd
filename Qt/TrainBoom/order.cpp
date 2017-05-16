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
    ui->tableWidget->hideColumn(8);
    for(int i = 0; i < 8; i++)
        ui->tableWidget->horizontalHeader()->setSectionResizeMode(i, QHeaderView::ResizeToContents);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->setAlternatingRowColors(true);
    ui->tableWidget->setSortingEnabled(true);
    QRegExp regExp("[0-9\-\\\_]{4}");
    QRegExpValidator *pRevalidotor = new QRegExpValidator(regExp, this);
    ui->lineEdit->setValidator(new QRegExpValidator(regExp, this));
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
        ui->tableWidget->setItem(rows, 8, new QTableWidgetItem(QString::number(rows, 10)));

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

Order::~Order()
{
    delete ui;
}

void Order::on_pushButton_clicked()
{
    reject();
}

void Order::on_refundButton_clicked()
{
    int num;
    if (!ui->tableWidget->selectedItems().size())
        QMessageBox::warning(this, tr("Warning!"), tr("请选择车票!!!"), QMessageBox::Yes);
    else if(ui->lineEdit->text().isEmpty())
        QMessageBox::warning(this, tr("Warning!"), tr("请输入数量!!!"), QMessageBox::Yes);
    else if(ui->lineEdit->text().toInt() <= 0)
        QMessageBox::warning(this, tr("Warning!"), tr("数量不合法!!!"), QMessageBox::Yes);
    else
    {
        num = ui->lineEdit->text().toInt();
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

        int row = ui->tableWidget->row(ui->tableWidget->selectedItems().at(0));
        int no = ui->tableWidget->item(row, 8)->text().toInt();

        QString orderId = orders[no].toString();
        getRequest.setUrl(QUrl(website+"/users/"+id+"/orders/"+orderId));
        getRequest.setRawHeader("Content-Type", "application/json");
        getRequest.setRawHeader("Cache-Control", "no-cache");
        getManager=new QNetworkAccessManager;
        getReply = getManager->get(getRequest);
        connect(getReply, SIGNAL(finished()), &ev, SLOT(quit()));
        ev.exec(QEventLoop::ExcludeUserInputEvents);
        bt = getReply->readAll();
        res = QJsonDocument::fromJson(bt).object()["data"].toObject();

        QJsonObject t2;
        t2.insert("date", res["date"].toString());
        t2.insert("l", res["routeInterval"].toObject()["l"].toInt());
        t2.insert("r", res["routeInterval"].toObject()["r"].toInt());
        t2.insert("ticketNumber", num);
        t2.insert("userId", id);
        t2.insert("ticketType", ui->tableWidget->item(row, 5)->text());
        QNetworkRequest refundRequest;
        refundRequest.setUrl(QUrl(website+"/routes/"+res["routeInterval"].toObject()["routeId"].toString()+"/tickets/refund"));

        refundRequest.setRawHeader("Content-Type", "application/json");
        refundRequest.setRawHeader("Cache-Control", "no-cache");
        QNetworkAccessManager *refundManager=new QNetworkAccessManager;
        QNetworkReply *refundReply = refundManager->post(refundRequest, QJsonDocument(t2).toJson());
        connect(refundReply, SIGNAL(finished()), &ev, SLOT(quit()));
        ev.exec(QEventLoop::ExcludeUserInputEvents);
        bt = refundReply->readAll();
        res = QJsonDocument::fromJson(bt).object();

        if (res.isEmpty())
            QMessageBox::warning(this, tr("Warning!"), tr("连接服务器失败!!!"), QMessageBox::Yes);
        else if (res["type"] == "error")
            QMessageBox::warning(this, tr("Warning!"), tr("退票失败!!!"), QMessageBox::Yes);
        else
            QMessageBox::warning(this, tr("Warning!"), tr("退票成功!!!"));
    }
}

