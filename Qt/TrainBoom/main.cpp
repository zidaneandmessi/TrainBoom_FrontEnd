#include "mainwindow.h"
#include "logindialog.h"
#include <QApplication>
#include <QJsonObject>
#include <QTime>

QJsonObject usrInfo;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    LoginDialog dlg;
    if (dlg.exec() == QDialog::Accepted)
    {
        w.receiveUser(dlg.sendUser());
        w.setUI();
        w.show();
        return a.exec();
    }
}
