#include "ticket.h"
#include "ui_ticket.h"
#include "qjsonarray.h"
#include "qtablewidget.h"
#include <Qstring>
#include <QUrl>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonObject>
#include <QByteArray>
#include <QJsonDocument>
#include <QMessageBox>

const QString website = "http://39.108.7.208:3000";

void Ticket::receiveRouteId(QString t)
{
    id = t;
}

Ticket::Ticket(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ticket)
{
    ui->setupUi(this);
    ui->tableWidget->setSelectionMode(QAbstractItemView::NoSelection);
}
void Ticket::setUI()
{
    QNetworkRequest routeRequest;
    routeRequest.setUrl(QUrl(website+"/routes/"+id));
    routeRequest.setRawHeader("Content-Type", "application/json");
    routeRequest.setRawHeader("Cache-Control", "no-cache");
    QNetworkAccessManager *routeManager=new QNetworkAccessManager;
    QNetworkReply *routeReply = routeManager->get(routeRequest);
    QEventLoop ev;
    connect(routeReply, SIGNAL(finished()), &ev, SLOT(quit()));
    ev.exec(QEventLoop::ExcludeUserInputEvents);
    QByteArray bt = routeReply->readAll();
    QJsonObject res = QJsonDocument::fromJson(bt).object();
    ui->label->setText(res["data"].toObject()["name"].toString());
    QJsonArray stations = res["data"].toObject()["informations"].toArray();
    for (int i = 0; i < stations.size(); i++)
    {
        int columns = ui->tableWidget->columnCount();
        ui->tableWidget->insertColumn(columns);
        QJsonObject t = stations[i].toObject();
        ui->tableWidget->setItem(0, columns, new QTableWidgetItem(t["stationName"].toString()));
        if (t["flags"].toInt() != 1)
        {
            ui->tableWidget->setItem(1, columns, new QTableWidgetItem(t["distance"].toString()));
            ui->tableWidget->setItem(2, columns, new QTableWidgetItem(t["leaveTime"].toString()));
        }
        if (t["flags"].toInt() != 2)
            ui->tableWidget->setItem(3, columns, new QTableWidgetItem(t["arriveTime"].toString()));
        ui->tableWidget->show();
    }
}

Ticket::~Ticket()
{
    delete ui;
}

void Ticket::on_pushButton_clicked()
{
    close();
}
