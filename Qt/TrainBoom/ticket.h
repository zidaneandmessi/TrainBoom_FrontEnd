#ifndef TICKET_H
#define TICKET_H

#include <QDialog>

namespace Ui {
class Ticket;
}

class Ticket : public QDialog
{
    Q_OBJECT

public:
    explicit Ticket(QWidget *parent = 0);
    void receiveRouteId(QString t);
    void setUI();
    ~Ticket();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Ticket *ui;
    QString id;
};

#endif // TICKET_H
