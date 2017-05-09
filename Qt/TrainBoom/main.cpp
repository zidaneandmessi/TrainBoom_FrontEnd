#include "mainwindow.h"
#include "logindialog.h"
#include <QApplication>
#include <QJsonObject>

QJsonObject usrInfo;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    LoginDialog dlg;
    if (dlg.exec() == QDialog::Accepted)
    {
        w.receive(dlg.send());
        w.show();
        return a.exec();
    }
    else return 0;
}
