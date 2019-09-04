#include "myform.h"
#include "ui_myform.h"

MyForm::MyForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyForm)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
    this->hide();
    this->setPalette(palette());
    connect(ui->send,SIGNAL(clicked()),this,SLOT(SenMessage()));
    //connect(socket,SIGNAL(readyRead()),this,SLOT(Receive()));
}
void MyForm::Init(QListWidgetItem* item){
    //SetRecord(item->text());
    socket=new QTcpSocket;
    socket = new QTcpSocket;
    QString HostIP="127.0.0.1";
    qint16 Port=8000;
    //已连接信号
    connect(socket,SIGNAL(connected()),this,SLOT(SlotConnect()));
    //连接出现错误信号
    connect(socket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(SlotErr(QAbstractSocket::SocketError)));
    //连接断开信号
   // connect(socket,SIGNAL(disconnected()),this,SLOT(SlotDisconnect()));
    //准备读取数据信号
    connect(socket,SIGNAL(readyRead()),this,SLOT(SlotReadData()));
    socket->connectToHost(QHostAddress(HostIP),Port);
}
void MyForm::SlotConnect(){
    QMessageBox::information(this,"connect","host connect sucess");
}

void MyForm::SlotErr(QAbstractSocket::SocketError err){
    qDebug("error is %d",err);
}

/*
void MyForm::SlotDisconnect(){

}
*/
void MyForm::SlotReadData(){
    if(socket->bytesAvailable()>0){
        QString msg;
        QByteArray data;
        data.resize(socket->bytesAvailable());
        socket->read(data.data(),data.size());
        msg=QString(data);
        ui->ChatRecord->append(msg);
    }
}

/*
void MyForm::Receive(){

    QByteArray a;
    a.resize(self.socket->pendingDatagramSize());
    self.socket->readDatagram(a.data(),a.size());
    ui->ChatRecord->setText(a);

}
*/
void MyForm::SendMessage(void){
    QTextStream in(socket);
    in<<ui->Input->toPlainText();
    ui->Input->clear();
    /*
    QString str=ui->Input->toPlainText();
    QByteArray Mess=str.toUtf8();
    QString localHostAddress =QHostAddress(QHostAddress::LocalHost).toString();
    self.socket->writeDatagram(Mess,QHostAddress(localHostAddress),10000);
    self.socket->bind(QHostAddress(localHostAddress),10000);
    */
}

MyForm::~MyForm()
{
    delete ui;
}
