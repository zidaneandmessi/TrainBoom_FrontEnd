#include "buy.h"
#include "ui_buy.h"
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
#include <QMediaPlaylist>
#include <QMediaPlayer>

const QString website = "http://39.108.7.208:3000";

Buy::Buy(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Buy)
{
    ui->setupUi(this);
    ui->label_2->setWordWrap(true);
    ui->label_2->setAlignment(Qt::AlignTop);
    QRegExp regExp("[0-9\-\\\_]{4}");
    QRegExpValidator *pRevalidotor = new QRegExpValidator(regExp, this);
    ui->numLineEdit->setValidator(new QRegExpValidator(regExp, this));
}

Buy::~Buy()
{
    delete ui;
}

void Buy::setUI()
{
    ui->label_2->setText("您将要购买"+routes["routeIntervals"].toArray()[noIndex].toObject()["data"].toObject()["routeName"].toString()+"次列车的"+ticketType+"票，每张"+QString::number(price, 10, 2)+"元。");
}

void Buy::receiveUser(QJsonObject t)
{
    usrInfo = t;
}
void Buy::receiveNo(int t)
{
    noIndex = t;
}
void Buy::receiveRoutes(QJsonObject t)
{
    routes = t;
}
void Buy::receiveDate(QString t)
{
    date = t;
}

void Buy::receiveTicketType(QString t)
{
    ticketType = t;
}
void Buy::receivePrice(double t)
{
    price = t;
}
int Buy::sendNum()
{
    return Num;
}


void Buy::on_pushButton_clicked()
{
    if (ui->numLineEdit->text().isEmpty())
        QMessageBox::warning(this, tr("Warning!"), tr("请输入数量!!!"), QMessageBox::Yes);
    else if (ui->numLineEdit->text().toInt() <= 0)
        QMessageBox::warning(this, tr("Warning!"), tr("数量不合法!!!"), QMessageBox::Yes);
    else
    {
        int num = ui->numLineEdit->text().toInt();
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

        QJsonObject t2;
        t2.insert("date", date);
        t2.insert("l", routes["routeIntervals"].toArray()[noIndex].toObject()["data"].toObject()["l"].toInt());
        t2.insert("r", routes["routeIntervals"].toArray()[noIndex].toObject()["data"].toObject()["r"].toInt());
        t2.insert("ticketNumber", num);
        t2.insert("userId", id);
        t2.insert("ticketType", ticketType);
        QNetworkRequest bookRequest;
        bookRequest.setUrl(QUrl(website+"/routes/"+routes["routeIntervals"].toArray()[noIndex].toObject()["data"].toObject()["routeId"].toString()+"/tickets/book"));

        bookRequest.setRawHeader("Content-Type", "application/json");
        bookRequest.setRawHeader("Cache-Control", "no-cache");
        QNetworkAccessManager *bookManager=new QNetworkAccessManager;
        QNetworkReply *bookReply = bookManager->post(bookRequest, QJsonDocument(t2).toJson());
        connect(bookReply, SIGNAL(finished()), &ev, SLOT(quit()));
        ev.exec(QEventLoop::ExcludeUserInputEvents);
        bt = bookReply->readAll();
        res = QJsonDocument::fromJson(bt).object();

        QByteArray msg = QUrl::toPercentEncoding("请向footoredo付款" + QString::number(res["data"].toObject()["ticketPrice"].toDouble(), 10, 1) + "元");
        QString url =  "http://api.qrserver.com/v1/create-qr-code/?size=300x300&data=";
        url.append(msg);

        QMessageBox msgBox(QMessageBox::NoIcon, "请通过扫描二维码支付", "");
        QPixmap pixmap;
        QNetworkAccessManager *picManager = new QNetworkAccessManager(this);
        QNetworkRequest picRequest;
        picRequest.setUrl(QUrl(url));
        QNetworkReply *picReply = picManager->get(picRequest);
        connect(picReply, SIGNAL(finished()), &ev, SLOT(quit()));
        ev.exec(QEventLoop::ExcludeUserInputEvents);
        bt = picReply->readAll();
        pixmap.loadFromData(bt, "png");
        pixmap.save("qr.png");
        msgBox.setIconPixmap(pixmap);
        msgBox.exec();

        if(res.isEmpty())
            QMessageBox::warning(this, tr("Warning!"), tr("服务器连接失败!!!"), QMessageBox::Yes);
        else if(res["type"] == "error")
            QMessageBox::warning(this, tr("Warning!"), tr("订票失败!!!") + res["data"].toObject()["errMsg"].toString(), QMessageBox::Yes);
        else
        {
            QMessageBox::warning(this, tr("Warning!"), tr("订票成功，您的订单号为") + res["id"].toString()+tr("!!!"), QMessageBox::Yes);
            Num = num;
            accept();
        }
    }
}

void Buy::on_pushButton_2_clicked()
{
    this->close();
}
