#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QList>
#include <QTcpServer>
#include "clientsocket.h"

class Server : public QTcpServer
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = 0);
    Server(qint16 port = 0);
    QList<TcpClientSocket*> tcpclientsocketlist;
protected:
    void incomingConnection(qintptr socketDescriptor);//只要出现一个新的连接，就会自动调用这个函数
protected slots:
    void sliotupdateserver(QString, qint16);//用来处理tcpclient发过来的信号
    void slotclientdisconnect(qint16);
    void slotupdateserver(QString, qint16);

signals:
    void updateserver(QString, qint16);//发送信号给界面，让界面更新信息

};


#endif // SERVER_H
