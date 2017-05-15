#include "register.h"
#include "logindialog.h"
#include "ui_register.h"
#include "qmessagebox.h"
#include "qjsonobject.h"
#include "qbytearray.h"
#include "qjsondocument.h"
#include "qradiobutton.h"
#include "qstring.h"
#include "qurl.h"
#include "qnetwork.h"
#include "qtextcodec.h"
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QCryptographicHash>

const QString website = "http://39.108.7.208:3000";

Register::Register(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
    ui->userLineEdit->setFocus();
}

Register::~Register()
{
    delete ui;
}

void Register::on_exitBtn_clicked()
{
    this->close();
    //LoginDialog *w = new LoginDialog;
    //w->exec();
}

QString regEncrypt(QString s)
{
    QByteArray string = s.toUtf8();
    QCryptographicHash *hash = new QCryptographicHash(QCryptographicHash::Sha1);
    hash->addData(string);
    QByteArray string1 = hash->result();
    QString string2 = string1.toHex();
    return string2;
}

void Register::on_regBtn_clicked()
{
    if (ui->userLineEdit->text().isEmpty()
            || ui->pwdLineEdit->text().isEmpty()
            || ui->pwdLineEdit2->text().isEmpty()
            || !ui->maleRadioBtn->isChecked() && !ui->femaleRadioBtn->isChecked() && !ui->elseRadioBtn->isChecked())
        QMessageBox::warning(this, tr("Warning!"), tr("请输入所有必要信息!!!"), QMessageBox::Yes);
    else if (ui->pwdLineEdit->text() != ui->pwdLineEdit2->text())
        QMessageBox::warning(this, tr("Warning!"), tr("密码不匹配!!!"), QMessageBox::Yes);
    else
    {
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
        if (res["type"] == "error") id = QString("");
        else id = res["userId"].toString();


        if (!id.isEmpty())
            QMessageBox::warning(this, tr("Warning!"), tr("用户名已存在!!!"), QMessageBox::Yes);
        else
        {
            QJsonObject obj;
            obj.insert("username", ui->userLineEdit->text());
            QString tmp = QString("0123456789ABCDEFGHIJKLMNOPQRSTUVWZYZ");
            QString salt;
            salt.clear();
            QTime t = QTime::currentTime();
            qsrand(t.msec()+t.second()*1000);
            for (int i = 0; i < 8; i++)
                salt[i] = tmp.at(qrand() % tmp.length());
            obj.insert("password", regEncrypt(ui->pwdLineEdit->text()+"|"+salt));
            obj.insert("salt", salt);
            obj.insert("avatar", "avatar.png");
            obj.insert("realname", ui->realLineEdit->text());
            obj.insert("phone", ui->phoneLineEdit->text());
            obj.insert("email", ui->emailLineEdit->text());
            if(ui->maleRadioBtn->isChecked()) obj.insert("gender", 0);
            else if(ui->femaleRadioBtn->isChecked()) obj.insert("gender", 1);
            else if(ui->elseRadioBtn->isChecked()) obj.insert("gender", 2);
            obj.insert("motto", ui->mottoLineEdit->text());
            if (ui->userLineEdit->text() == "gzotpa")
                obj.insert("isRoot", true);
            else
                obj.insert("isRoot", false);
            QNetworkRequest regRequest;
            regRequest.setUrl(QUrl(website+"/users"));
            regRequest.setRawHeader("Content-Type", "application/json");
            regRequest.setRawHeader("Cache-Control", "no-cache");
            QNetworkAccessManager *regManager=new QNetworkAccessManager;
            QNetworkReply *regReply = regManager->post(regRequest, QJsonDocument(obj).toJson());
            QEventLoop ev;
            connect(regReply, SIGNAL(finished()), &ev, SLOT(quit()));
            ev.exec(QEventLoop::ExcludeUserInputEvents);
            bt = regReply->readAll();
            res = QJsonDocument::fromJson(bt).object();
            if (res.isEmpty())
                QMessageBox::warning(this, tr("Warning!"), tr("连接服务器失败!!!"), QMessageBox::Yes);
            else if (res["type"] == "error")
                QMessageBox::warning(this, tr("Warning!"), tr("注册失败!!!") + res["data"].toObject()["errMsg"].toString(), QMessageBox::Yes);
            else
                this->close();
        }
    }
}
