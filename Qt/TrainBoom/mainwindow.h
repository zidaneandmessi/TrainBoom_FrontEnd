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
    QJsonObject sendUser();

private slots:
    void on_action_UL_triggered();
    void on_action_UM_triggered();
    void on_adminButton_clicked();
    void on_queryButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QJsonObject usrInfo, routes;
};

#endif // MAINWINDOW_H
