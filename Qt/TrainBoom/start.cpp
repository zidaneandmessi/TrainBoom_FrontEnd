#include "start.h"
#include "ui_start.h"
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

Start::Start(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Start)
{
    ui->setupUi(this);
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
    QString id = "";
    QNetworkRequest startRequest;
    startRequest.setUrl(QUrl(website+"/routes/"+id+"/start"));
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
        QMessageBox::warning(this, tr("Warning!"), tr("开始发售成功!!!"), QMessageBox::Yes);
    else
        QMessageBox::warning(this, tr("Warning!"), tr("开始发售失败!!!"), QMessageBox::Yes);
}
