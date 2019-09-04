#ifndef MYFORM_H
#define MYFORM_H
#include <QWidget>
#include <QListWidget>
#include <QTcpSocket>
#include <QHostAddress>
#include <QMessageBox>
namespace Ui {
class MyForm;
}
class MyForm : public QWidget
{
    Q_OBJECT

public:
    explicit MyForm(QWidget *parent = 0);
    ~MyForm();

private slots:
    void SlotConnect();
    void SlotErr(QAbstractSocket::SocketError);
    //void SlotDisconnect();
    void SlotReadData();
    void Init(QListWidgetItem*);
    void SendMessage();
    //void Receive();
signals:

private:
    Ui::MyForm *ui;
    QTcpSocket *socket;
    void SetRecord(QString);
public:
    //void Init(QString);
};

#endif // MYFORM_H
