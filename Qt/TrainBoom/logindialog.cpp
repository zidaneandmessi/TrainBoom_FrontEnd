#include "qmessagebox.h"
#include "logindialog.h"
#include "ui_logindialog.h"
#include "qjsonobject.h"
#include "qjsondocument.h"
#include "register.h"
#include "qtextcodec.h"
#include "mainwindow.h"
#include "qnetwork.h"
#include <QUrl>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <Qstring>
#include <QCryptographicHash>

const QString website = "http://39.108.7.208:3000";

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

QString loginEncrypt(QString s)
{
    QByteArray string = s.toUtf8();
    QCryptographicHash *hash=new QCryptographicHash(QCryptographicHash::Sha1);
    hash->addData(string);
    QByteArray string1 = hash->result();
    QString string2 = string1.toHex();
    return string2;
}
QJsonObject LoginDialog::sendUser()
{
    return usrInfo;
}

void LoginDialog::on_loginBtn_clicked()
{
    if(ui->userLineEdit->text().isEmpty() || ui->pwdLineEdit->text().isEmpty())
    {
        QMessageBox::warning(this, tr("Warning!"),tr("请输入用户名和密码!!!"),QMessageBox::Yes);
        return;
    }

    QString id;
    QJsonObject t;
    t.insert("username", ui->userLineEdit->text());
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
    if (res.isEmpty())
        QMessageBox::warning(this, tr("Warning!"), tr("连接服务器失败!!!"), QMessageBox::Yes);
    else if (res["type"] == "error")
        QMessageBox::warning(this, tr("Warning!"), tr("登录失败!!!") + res["data"].toObject()["errMsg"].toString(), QMessageBox::Yes);
    else
    {
        id = res["userId"].toString();
        QNetworkRequest loginRequest;
        loginRequest.setUrl(QUrl(website+"/users/"+id));
        loginRequest.setRawHeader("Content-Type", "application/json");
        loginRequest.setRawHeader("Cache-Control", "no-cache");
        QNetworkAccessManager *loginManager=new QNetworkAccessManager;
        QNetworkReply *loginReply = loginManager->get(loginRequest);
        QEventLoop ev;
        connect(loginReply, SIGNAL(finished()), &ev, SLOT(quit()));
        ev.exec(QEventLoop::ExcludeUserInputEvents);
        bt = loginReply->readAll();
        res = QJsonDocument::fromJson(bt).object();
        if (res["data"].toObject()["password"] == loginEncrypt(ui->pwdLineEdit->text()+"|"+res["data"].toObject()["salt"].toString()))
        {
            usrInfo = res["data"].toObject();
            accept();
        }
        else
        {
            QMessageBox::warning(this, tr("Warning!"), tr("密码错误!!!"),QMessageBox::Yes);
            ui->pwdLineEdit->clear();
            ui->pwdLineEdit->setFocus();
        }
    }
}

void LoginDialog::on_regBtn_clicked()
{
    Register *w = new Register;
    w->exec();
}
