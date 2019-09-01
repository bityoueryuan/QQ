#include "friendlist.h"
#include "ui_friendlist.h"

FriendList::FriendList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FriendList)
{
    ui->setupUi(this);
}

FriendList::~FriendList()
{
    delete ui;
}

void FriendList::on_toolButton_clicked()
{
    Chat *win = new Chat;   //show new window
    win->show();
    this->close();
}
