#include "widget.h"
#include "mainwindow.h"
#include "ui_widget.h"
#include <QFile>
#include <QTextStream>
#include <QUrl>
#include <QDesktopServices>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->account->setPlaceholderText(tr("请输入用户名"));
    ui->password->setPlaceholderText(tr("请输入密码"));
    ui->groupBox->setStyleSheet("#groupBox{border: none;}");
    connect(ui->login_button,SIGNAL(clicked()),this,SLOT(login_click()));
}
bool login_judge(QString a,QString p){
    a="D:/IMS/database/account/"+a;
    if(QFile::exists(a)){
        QFile file(a+"/password.txt");
        file.open(QIODevice::ReadOnly);
        QTextStream in(&file);
        QString str=in.readLine();
        return str==p;
    }
    else
        return false;
}

void Widget::login_click(){
    if(true||login_judge(ui->account->text(),ui->password->text())){
        this->close();
        emit show_mainwindow(ui->account->text());
    }
    else{
        QMessageBox::information(this,"",tr("无效的用户名或密码，请重新输入"));
        ui->password->clear();
        ui->account->clear();
    }
}
Widget::~Widget()
{
    delete ui;
}
