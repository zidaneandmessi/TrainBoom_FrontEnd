#include "add.h"
#include "ui_add.h"
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

Add::Add(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Add)
{
    ui->setupUi(this);
    ui->tableWidget->setAlternatingRowColors(true);
}

Add::~Add()
{
    delete ui;
}

void Add::on_pushButton_2_clicked()
{
    this->close();
}

void Add::on_pushButton_3_clicked()
{
    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
}

void Add::on_pushButton_4_clicked()
{
    if (ui->tableWidget->rowCount())
        ui->tableWidget->setRowCount(ui->tableWidget->rowCount() - 1);
}


QJsonObject emptyJson;

void Add::on_pushButton_clicked()
{
    if (ui->lineEdit->text().isEmpty())
        QMessageBox::warning(this, tr("Warning!"), tr("请输入车次编号!!!"), QMessageBox::Yes);
    else
    {
        QString name = ui->lineEdit->text();

        QString id;
        QJsonObject t;
        QNetworkRequest stationRequest;
        t.insert("name", ui->lineEdit->text());
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


        if (!id.isEmpty())
        {
            QNetworkRequest delRequest;
            delRequest.setUrl(QUrl(website+"/routes/"+id));
            delRequest.setRawHeader("Content-Type", "application/json");
            delRequest.setRawHeader("Cache-Control", "no-cache");
            QNetworkAccessManager *delManager=new QNetworkAccessManager;
            QNetworkReply *delReply = delManager->deleteResource(delRequest);
            connect(delReply, SIGNAL(finished()), &ev, SLOT(quit()));
            ev.exec(QEventLoop::ExcludeUserInputEvents);
        }
        QJsonObject obj;
        QJsonArray infor, seg;
        int stations = 0;
        QNetworkRequest addRequest;
        addRequest.setUrl(QUrl(website+"/routes"));
        addRequest.setRawHeader("Content-Type", "application/json");
        addRequest.setRawHeader("Cache-Control", "no-cache");
        obj.insert("name", name);
        QJsonObject tt;
        for (int i = 0; i < ui->tableWidget->rowCount(); i++)
        {
            if (i == 0 || ui->tableWidget->item(i, 0)->text() != ui->tableWidget->item(i - 1, 0)->text())
            {
                stations++;
                if (i > 1)
                {
                    QJsonObject tttt;
                    tttt["tickets"] = tt;
                    seg.push_back(tttt);
                    tt = emptyJson;
                }
                if (i == 0)
                {
                    QJsonObject t;
                    t.insert("distance", 0);
                    t.insert("flags", 1);
                    t.insert("leaveTime", ui->tableWidget->item(i, 2)->text());
                    t.insert("stationName", ui->tableWidget->item(i, 0)->text());
                    infor.push_back(t);
                }
                else if (ui->tableWidget->item(i, 0)->text() == ui->tableWidget->item(ui->tableWidget->rowCount() - 1, 0)->text())
                {
                    QJsonObject t;
                    t.insert("distance", ui->tableWidget->item(i, 3)->text().toInt());
                    t.insert("flags", 2);
                    t.insert("arriveTime", ui->tableWidget->item(i, 1)->text());
                    t.insert("stationName", ui->tableWidget->item(i, 0)->text());
                    infor.push_back(t);
                }
                else
                {
                    QJsonObject t;
                    t.insert("distance", ui->tableWidget->item(i, 3)->text().toInt());
                    t.insert("flags", 0);
                    t.insert("arriveTime", ui->tableWidget->item(i, 1)->text());
                    t.insert("leaveTime", ui->tableWidget->item(i, 2)->text());
                    t.insert("stationName", ui->tableWidget->item(i, 0)->text());
                    infor.push_back(t);
                }
            }
            if (i > 0)
            {
                QJsonObject ttt;
                ttt.insert("nonstop", false);
                ttt.insert("price",  ui->tableWidget->item(i, 5)->text().toDouble());
                ttt.insert("number", ui->tableWidget->item(i, 6)->text().toInt());
                tt.insert(ui->tableWidget->item(i, 4)->text(), ttt);
            }
        }
        if (!tt.isEmpty())
        {
            QJsonObject tttt;
            tttt["tickets"] = tt;
            seg.push_back(tttt);
        }
        obj.insert("n", stations);
        obj.insert("informations", infor);
        obj.insert("segments", seg);
        QNetworkAccessManager *addManager=new QNetworkAccessManager;
        QNetworkReply *addReply = addManager->post(addRequest, QJsonDocument(obj).toJson());
        connect(addReply, SIGNAL(finished()), &ev, SLOT(quit()));
        ev.exec(QEventLoop::ExcludeUserInputEvents);
        bt = addReply->readAll();
        res = QJsonDocument::fromJson(bt).object();
        if (res.isEmpty())
            QMessageBox::warning(this, tr("Warning!"), tr("连接服务器失败!!!"), QMessageBox::Yes);
        if (res["type"] == "error")
            QMessageBox::warning(this, tr("Warning!"), tr("添加车次失败!!!") + res["data"].toObject()["errMsg"].toString(), QMessageBox::Yes);
        else
        {
            QMessageBox::warning(this, tr("Warning!"), tr("添加车次成功!!!"), QMessageBox::Yes);
            accept();
        }
    }
}
