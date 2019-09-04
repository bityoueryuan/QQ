#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMessageBox>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void login_click();
signals:
    void show_mainwindow(QString);

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
