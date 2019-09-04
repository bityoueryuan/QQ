#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    port=8888;
    serverIP=new QHostAddress();
    serverIP->setAddress("192.168.43.88");
}
void MainWindow::receive_login(QString ID){
    this->show();
    ui->Nickname->setText(ID);
    nickname=ID;
    socket = new QTcpSocket(this);
    socket->connectToHost(*serverIP,port);
    connect(socket, &QTcpSocket::connected, this, &MainWindow::slotconnectedsuccess);
    //接收到服务器的信息就会触发readyRead信号
    connect(socket, &QTcpSocket::readyRead, this, &MainWindow::slotreceive);


}
void MainWindow::on_Send_clicked(){
    if(ui->Input->toPlainText()=="")
        return;
    QString msg=nickname+" : "+ui->Input->toPlainText();
    socket->write(msg.toUtf8().data());
    ui->Input->clear();

}
void MainWindow::slotconnectedsuccess(){
    QMessageBox::information(this,"","success");
    QString msg=nickname+" Enter Chat Room";
    socket->write(msg.toUtf8().data());
}
void MainWindow::slotreceive(){
    QByteArray arr=socket->readAll();
    ui->Chat->append(arr);
}
/*
void MainWindow::slotdisconnected(){

}
*/
MainWindow::~MainWindow()
{
    delete ui;
}
