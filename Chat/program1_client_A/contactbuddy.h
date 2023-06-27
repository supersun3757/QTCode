#ifndef CONTACTBUDDY_H
#define CONTACTBUDDY_H

#include <QWidget>
#include <QObject>

namespace Ui {
class contactbuddy;
}

class contactbuddy : public QWidget
{
    Q_OBJECT

public:
    explicit contactbuddy(QString Name="张三",QString word="你好", QWidget *parent = 0);
    ~contactbuddy();

    QString headImgPath=":/data";//头像路径


private:
    Ui::contactbuddy *ui;
};

#endif // CONTACTBUDDY_H
