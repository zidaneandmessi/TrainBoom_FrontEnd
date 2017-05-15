#ifndef QUERY_H
#define QUERY_H

#include <QDialog>
#include <QJsonObject>

namespace Ui {
class Query;
}

class Query : public QDialog
{
    Q_OBJECT

public:
    explicit Query(QWidget *parent = 0);
    QJsonObject sendRoutes();
    QString sendDate();
    ~Query();

private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();

private:
    Ui::Query *ui;
    QJsonObject routes;
    QString date;
};

#endif // QUERY_H
