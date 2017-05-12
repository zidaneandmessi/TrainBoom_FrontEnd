#include "modify.h"
#include "ui_modify.h"
#include "mainwindow.h"
#include "qmessagebox.h"
#include "qjsonobject.h"
#include "qjsondocument.h"
#include <QCryptographicHash>
#include <Qstring>
#include "qnetwork.h"
#include <QUrl>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QNetworkReply>

const QString website = "http://39.108.7.208:3000";

modify::modify(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modify)
{
    ui->setupUi(this);
}

void modify::setUI()
{
    ui->userLabel->setText(usrInfo["username"].toString());
    ui->realLineEdit->setText(usrInfo["realname"].toString());
    ui->phoneLineEdit->setText(usrInfo["phone"].toString());
    ui->emailLineEdit->setText(usrInfo["email"].toString());
    ui->mottoLineEdit->setText(usrInfo["motto"].toString());
    int g = usrInfo["gender"].toInt();
    if (g == 0) ui->maleRadioBtn->setChecked(1);
    else if (g == 1) ui->femaleRadioBtn->setChecked(1);
    else if (g == 2) ui->elseRadioBtn->setChecked(1);
}

void modify::receiveUser(QJsonObject t)
{
    usrInfo = t;
}

QJsonObject modify::sendUser()
{
    return usrInfo;
}

modify::~modify()
{
    delete ui;
}


void modify::on_exitBtn_clicked()
{
    reject();
}

QString modEncrypt(QString s)
{
    QByteArray string = s.toUtf8();
    QCryptographicHash *hash = new QCryptographicHash(QCryptographicHash::Sha1);
    hash->addData(string);
    QByteArray string1 = hash->result();
    QString string2 = string1.toHex();
    return string2;
}

void modify::on_regBtn_clicked()
{
    if (!ui->maleRadioBtn->isChecked() && !ui->femaleRadioBtn->isChecked() && !ui->elseRadioBtn->isChecked())
        QMessageBox::warning(this, tr("Warning!"), tr("请选择性别!!!"), QMessageBox::Yes);
    else if (ui->pwdLineEdit->text().isEmpty())
        QMessageBox::warning(this, tr("Warning!"), tr("请输入原密码!!!"), QMessageBox::Yes);
    else if (modEncrypt(ui->pwdLineEdit->text()) != usrInfo["password"].toString())
        QMessageBox::warning(this, tr("Warning!"), tr("原密码错误!!!"), QMessageBox::Yes);
    else if (ui->npwdLineEdit->text() != ui->npwdLineEdit2->text())
        QMessageBox::warning(this, tr("Warning!"), tr("密码不匹配!!!"), QMessageBox::Yes);
    else
    {
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
        else id = res["data"].toObject()["userId"].toString();


        QJsonObject obj;
        obj.insert("username", usrInfo["username"]);
        if (ui->npwdLineEdit->text().isEmpty())
            obj.insert("password", usrInfo["password"]);
        else
            obj.insert("password", modEncrypt(ui->npwdLineEdit->text()));
        obj.insert("salt", "gzotpa");
        obj.insert("avatar", "avatar.png");
        obj.insert("realname", ui->realLineEdit->text());
        obj.insert("phone", ui->phoneLineEdit->text());
        obj.insert("email", ui->emailLineEdit->text());
        if(ui->maleRadioBtn->isChecked()) obj.insert("gender", 0);
        else if(ui->femaleRadioBtn->isChecked()) obj.insert("gender", 1);
        else if(ui->elseRadioBtn->isChecked()) obj.insert("gender", 2);
        obj.insert("motto", ui->mottoLineEdit->text());
        obj.insert("isroot", 0);
        QNetworkRequest modRequest;
        modRequest.setUrl(QUrl(website+"/users/"+id));
        modRequest.setRawHeader("Content-Type", "application/json");
        modRequest.setRawHeader("Cache-Control", "no-cache");
        QNetworkAccessManager *modManager=new QNetworkAccessManager;
        QNetworkReply *modReply = modManager->put(modRequest, QJsonDocument(obj).toJson());
        ev;
        connect(modReply, SIGNAL(finished()), &ev, SLOT(quit()));
        ev.exec(QEventLoop::ExcludeUserInputEvents);
        bt = modReply->readAll();
        res = QJsonDocument::fromJson(bt).object();
        usrInfo = res["data"].toObject();

        QMessageBox::warning(this, tr("Warning!"), tr("信息修改成功!!!"), QMessageBox::Yes);
        accept();
    }
}
