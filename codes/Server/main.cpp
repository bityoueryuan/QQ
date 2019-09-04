#include <QCoreApplication>
#include <iostream>
#include <QObject>
#include "server.h"
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Server *server;
    qint16 port=8888;
    server=new Server(port);

    return a.exec();
}
