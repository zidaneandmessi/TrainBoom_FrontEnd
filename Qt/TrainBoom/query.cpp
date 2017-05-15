#include "query.h"
#include "ui_query.h"
#include "qmessagebox.h"
#include "qjsonobject.h"
#include "qbytearray.h"
#include "qjsondocument.h"
#include "qradiobutton.h"
#include "qstring.h"
#include "qurl.h"
#include "qnetwork.h"
#include "qtextcodec.h"
#include "qjsonarray.h"
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QDate>

const QString website = "http://39.108.7.208:3000";

Query::Query(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Query)
{
    ui->setupUi(this);
    ui->dateEdit->setDisplayFormat("yyyy/M/d");
    ui->dateEdit->setDate(QDate::currentDate());
}

Query::~Query()
{
    delete ui;
}

QJsonObject Query::sendRoutes()
{
    return routes;
}
QString Query::sendDate()
{
    return date;
}

void Query::on_pushButton_2_clicked()
{
    this->close();
}

void Query::on_pushButton_clicked()
{
    if (ui->stLineEdit->text().isEmpty()
            || ui->enLineEdit->text().isEmpty())
        QMessageBox::warning(this, tr("Warning!"), tr("请输入起点站与终点站!!!"), QMessageBox::Yes);
    else if (ui->stLineEdit->text() == ui->enLineEdit->text())
        QMessageBox::warning(this, tr("Warning!"), tr("起点站与终点站相同!!!"), QMessageBox::Yes);
    else
    {
        QString id;
        QJsonObject t;
        t.insert("startStation", ui->stLineEdit->text());
        t.insert("endStation", ui->enLineEdit->text());
        date = ui->dateEdit->text();
        QNetworkRequest queryRequest;
        queryRequest.setUrl(QUrl(website+"/routeInterval/get"));
        queryRequest.setRawHeader("Content-Type", "application/json");
        queryRequest.setRawHeader("Cache-Control", "no-cache");
        QNetworkAccessManager *queryManager=new QNetworkAccessManager;
        QNetworkReply *queryReply = queryManager->post(queryRequest, QJsonDocument(t).toJson());
        QEventLoop ev;
        connect(queryReply, SIGNAL(finished()), &ev, SLOT(quit()));
        ev.exec(QEventLoop::ExcludeUserInputEvents);
        QByteArray bt = queryReply->readAll();
        QJsonObject res = QJsonDocument::fromJson(bt).object();
        if (res["type"] == "error")
            QMessageBox::warning(this, tr("Warning!"), tr("没找到符合条件的票!!!"), QMessageBox::Yes);
        else
        {
            routes = res;
            accept();
        }
    }
}
