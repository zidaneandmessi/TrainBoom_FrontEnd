#include "delete.h"
#include "ui_delete.h"
#include <QRegExpValidator>
#include "qmessagebox.h"
#include "qjsonobject.h"
#include "qjsondocument.h"
#include "qjsonarray.h"
#include <QCryptographicHash>
#include <Qstring>
#include "qnetwork.h"
#include <QUrl>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QNetworkReply>

const QString website = "http://39.108.7.208:3000";

Delete::Delete(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Delete)
{
    ui->setupUi(this);
}

Delete::~Delete()
{
    delete ui;
}

void Delete::on_pushButton_2_clicked()
{
    this->close();
}

void Delete::on_pushButton_clicked()
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

    QNetworkRequest delRequest;
    delRequest.setUrl(QUrl(website+"/routes/"+id));
    delRequest.setRawHeader("Content-Type", "application/json");
    delRequest.setRawHeader("Cache-Control", "no-cache");
    QNetworkAccessManager *delManager=new QNetworkAccessManager;
    QNetworkReply *delReply = delManager->deleteResource(delRequest);
    connect(delReply, SIGNAL(finished()), &ev, SLOT(quit()));
    ev.exec(QEventLoop::ExcludeUserInputEvents);
    bt = delReply->readAll();
    res = QJsonDocument::fromJson(bt).object();

    if (res.isEmpty())
        QMessageBox::warning(this, tr("Warning!"), tr("连接服务器失败!!!"), QMessageBox::Yes);
    else if (res["type"] == "error")
        QMessageBox::warning(this, tr("Warning!"), tr("删除车次失败!!!") + res["data"].toObject()["errMsg"].toString(), QMessageBox::Yes);
    else if (res["type"].toString() == "success")
        QMessageBox::warning(this, tr("Warning!"), tr("删除车次成功!!!"), QMessageBox::Yes);
}
