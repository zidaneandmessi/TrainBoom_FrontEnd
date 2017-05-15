#ifndef ORDER_H
#define ORDER_H

#include <QDialog>
#include <QJsonObject>

namespace Ui {
class Order;
}

class Order : public QDialog
{
    Q_OBJECT

public:
    explicit Order(QWidget *parent = 0);
    void receiveUser(QJsonObject t);
    void setUI();
    ~Order();

private slots:
    void on_pushButton_clicked();

    void on_refundButton_clicked();

private:
    Ui::Order *ui;
    QJsonObject usrInfo;
};

#endif // ORDER_H
