#ifndef BUY_H
#define BUY_H

#include <QDialog>
#include <QJsonObject>

namespace Ui {
class Buy;
}

class Buy : public QDialog
{
    Q_OBJECT

public:
    explicit Buy(QWidget *parent = 0);
    void receiveUser(QJsonObject t);
    void receiveNo(int t);
    void receiveRoutes(QJsonObject t);
    void receiveTicketType(QString t);
    void setUI();
    int sendNum();
    void receivePrice(double t);
    ~Buy();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Buy *ui;
    QJsonObject usrInfo, routes;
    QString ticketType;
    int noIndex, Num;
    double price;
};

#endif // BUY_H
