#include "start.h"
#include "ui_start.h"
#include <QRegExpValidator>
#include "qmessagebox.h"
#include "qjsonobject.h"
#include "qjsondocument.h"
#include "qjsonarray.h"
#include <QCryptographicHash>
#include <Qstring>
#include <QUrl>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QNetworkReply>

const QString website = "http://39.108.7.208:3000";

Start::Start(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Start)
{
    ui->setupUi(this);
    ui->dateEdit->setDisplayFormat("yyyy/M/d");
    ui->dateEdit->setDate(QDate::currentDate());
}

Start::~Start()
{
    delete ui;
}

void Start::on_pushButton_2_clicked()
{
    this->close();
}

void Start::on_pushButton_clicked()
{
    QString id;
    QJsonObject t;
    QNetworkRequest stationRequest;
    t.insert("name", ui->nameLineEdit->text());
    stationRequest.setUrl(QUrl(website+"/routes/name"));
    stationRequest.setRawHeader("Content-Type", "application/json");
    stationRequest.setRawHeader("Cache-Control", "no-cache");
    QNetworkAccessManager *stationManager=new QNetworkAccessManager;
    QNetworkReply *stationReply = stationManager->post(stationRequest, QJsonDocument(t).toJson());
    QEventLoop ev;
    connect(stationReply, SIGNAL(finished()), &ev, SLOT(quit()));
    ev.exec(QEventLoop::ExcludeUserInputEvents);
    QByteArray bt = stationReply->readAll();
    QJsonObject res = QJsonDocument::fromJson(bt).object();
    id = res["routeId"].toString();

    QNetworkRequest startRequest;
    QJsonObject obj;
    obj.insert("date", ui->dateEdit->text());
    startRequest.setUrl(QUrl(website+"/routes/"+id+"/tickets/start"));
    startRequest.setRawHeader("Content-Type", "application/json");
    startRequest.setRawHeader("Cache-Control", "no-cache");
    QNetworkAccessManager *startManager=new QNetworkAccessManager;
    QNetworkReply *startReply = startManager->post(startRequest, QJsonDocument(obj).toJson());
    connect(startReply, SIGNAL(finished()), &ev, SLOT(quit()));
    ev.exec(QEventLoop::ExcludeUserInputEvents);
    bt = startReply->readAll();
    res = QJsonDocument::fromJson(bt).object();
    if (res.isEmpty())
        QMessageBox::warning(this, tr("Warning!"), tr("连接服务器失败!!!"), QMessageBox::Yes);
    else if (res["type"].toString() == "error")
        QMessageBox::warning(this, tr("Warning!"), tr("开始发售失败!!!") + res["data"].toObject()["errMsg"].toString(), QMessageBox::Yes);
    else if (res["type"].toString() == "success")
    {
        QMessageBox::warning(this, tr("Warning!"), tr("开始发售成功!!!"), QMessageBox::Yes);
        accept();
    }
}
