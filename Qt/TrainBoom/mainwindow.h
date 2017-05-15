#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QJsonObject>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void receiveUser(QJsonObject t);
    void receiveRoutes(QJsonObject t);
    void receiveDate(QString t);
    QJsonObject sendUser();
    QJsonObject sendRoutes();
    QString sendDate();
    void setUI();

private slots:
    void on_action_UL_triggered();
    void on_action_UM_triggered();
    void on_startButton_clicked();
    void on_queryButton_clicked();
    void on_pushButton_clicked();
    void on_orderButton_clicked();

    void on_stopButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::MainWindow *ui;
    QJsonObject usrInfo, routes;
    QString date;
};

#endif // MAINWINDOW_H
