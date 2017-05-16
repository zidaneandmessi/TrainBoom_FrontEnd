#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QJsonObject>
#include <QMediaPlaylist>
#include <QMediaPlayer>

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
    void playMusic();

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

    void on_tableWidget_doubleClicked(const QModelIndex &index);

    void on_pushButton_4_clicked();

    void on_actionfootoredo_triggered();

    void on_actionzidaneandmessi_triggered();

    void on_actionCreeperLin_triggered();

    void on_actionWillYoung_triggered();

private:
    Ui::MainWindow *ui;
    QJsonObject usrInfo, routes;
    QString date;
    QMediaPlaylist *defaultPlaylist;
    QMediaPlayer *music;
};

#endif // MAINWINDOW_H
