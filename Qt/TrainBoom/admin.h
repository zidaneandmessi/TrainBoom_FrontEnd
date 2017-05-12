#ifndef ADMIN_H
#define ADMIN_H

#include <QDialog>

namespace Ui {
class Admin;
}

class Admin : public QDialog
{
    Q_OBJECT

public:
    explicit Admin(QWidget *parent = 0);
    ~Admin();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Admin *ui;
};

#endif // ADMIN_H
