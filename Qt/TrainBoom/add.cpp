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

void Add::on_pushButton_clicked()
{
    if (ui->lineEdit->text().isEmpty())
        QMessageBox::warning(this, tr("Warning!"), tr("请输入车次编号!!!"), QMessageBox::Yes);
    else
    {
        QString name = ui->lineEdit->text();

        QString id = "";

        if (1)//存在
        {
//删除
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
                if (i > 0)
                {
                    QJsonObject tttt;
                    tttt["tickets"] = tt;
                    seg.push_back(tttt);
                    for (QJsonObject::iterator it = tt.begin(); it != tt.end(); )
                            tt.erase(++it);
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
            QJsonObject ttt;
            ttt["nonstop"] = false;
            ttt["price"] = ui->tableWidget->item(i, 5)->text().toDouble();
            ttt["number"] = ui->tableWidget->item(i, 6)->text().toInt();
            tt[ui->tableWidget->item(i, 4)->text()] = ttt;
        }
        obj.insert("n", stations);
        obj.insert("informations", infor);
        obj.insert("segments", seg);
        QNetworkAccessManager *addManager=new QNetworkAccessManager;
        QNetworkReply *addReply = addManager->post(addRequest, QJsonDocument(obj).toJson());
        QEventLoop ev;
        connect(addReply, SIGNAL(finished()), &ev, SLOT(quit()));
        ev.exec(QEventLoop::ExcludeUserInputEvents);
        QByteArray bt = addReply->readAll();
        QJsonObject res = QJsonDocument::fromJson(bt).object();
    }
}
