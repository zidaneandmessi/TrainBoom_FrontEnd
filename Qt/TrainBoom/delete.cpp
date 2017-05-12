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
    QString id = "";
    QNetworkRequest delRequest;
    delRequest.setUrl(QUrl(website+"/routes/"+id+"/delete"));
    delRequest.setRawHeader("Content-Type", "application/json");
    delRequest.setRawHeader("Cache-Control", "no-cache");
    QNetworkAccessManager *delManager=new QNetworkAccessManager;
    QNetworkReply *delReply = delManager->get(delRequest);
    QEventLoop ev;
    connect(delReply, SIGNAL(finished()), &ev, SLOT(quit()));
    ev.exec(QEventLoop::ExcludeUserInputEvents);
    QByteArray bt = delReply->readAll();
    QJsonObject res = QJsonDocument::fromJson(bt).object();
    if (res["type"].toString() == "success")
        QMessageBox::warning(this, tr("Warning!"), tr("删除车次成功!!!"), QMessageBox::Yes);
    else
        QMessageBox::warning(this, tr("Warning!"), tr("删除车次失败!!!"), QMessageBox::Yes);
}
