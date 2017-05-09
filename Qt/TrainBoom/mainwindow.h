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
    void receive(QJsonObject t);

private slots:
    void on_pushButton_clicked();
    void on_action_UL_triggered();

private:
    Ui::MainWindow *ui;
    QJsonObject usrInfo;
};

#endif // MAINWINDOW_H
