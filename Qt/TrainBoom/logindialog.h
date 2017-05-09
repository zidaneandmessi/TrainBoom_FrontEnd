#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QJsonObject>

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = 0);
    ~LoginDialog();
    QJsonObject send();

signals:

private slots:

    void on_loginBtn_clicked();

    void on_regBtn_clicked();

private:
    Ui::LoginDialog *ui;
    QJsonObject usrInfo;
};

#endif // LOGINDIALOG_H
