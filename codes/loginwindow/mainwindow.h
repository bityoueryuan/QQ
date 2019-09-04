#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QTcpSocket>
#include <QHostAddress>
#include "ui_mainwindow.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void receive_login(QString);
    //void on_pushButtonEnter_clicked();
    void slotconnectedsuccess();//用来处理连接成功的信号
    void slotreceive();//接收服务器传过来的信息
    void on_Send_clicked();
    //void slotdisconnected();//用来处理离开聊天室的信号
signals:

private:
    Ui::MainWindow *ui;
    QTcpSocket *socket;
    QString nickname;
    int port;
    QHostAddress *serverIP;
};
#endif // MAINWINDOW_H
