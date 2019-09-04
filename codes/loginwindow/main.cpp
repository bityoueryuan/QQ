#include "widget.h"
#include "mainwindow.h"
//#include "dialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MyForm m;
    //m.show();
    Widget w;
    MainWindow m;
    //m.show();
    QObject::connect(&w,SIGNAL(show_mainwindow(QString)),&m,SLOT(receive_login(QString)));
    w.show();


    return a.exec();
}
