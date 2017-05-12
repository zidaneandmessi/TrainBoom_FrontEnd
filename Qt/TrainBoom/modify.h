#ifndef MODIFY_H
#define MODIFY_H

#include <QDialog>
#include <QJsonObject>

namespace Ui {
class modify;
}

class modify : public QDialog
{
    Q_OBJECT

public:
    explicit modify(QWidget *parent = 0);
    void receiveUser(QJsonObject t);
    QJsonObject sendUser();
    void setUI();
    ~modify();

private slots:
    void on_exitBtn_clicked();
    void on_regBtn_clicked();

private:
    Ui::modify *ui;
    QJsonObject usrInfo;
};

#endif // MODIFY_H
