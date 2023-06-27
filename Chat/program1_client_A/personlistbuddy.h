#ifndef PERSONLISTBUDDY_H
#define PERSONLISTBUDDY_H

#include <QWidget>
#include <QLabel>
#include <QEvent>

//好友列表中的每一个项
namespace Ui {
class personListBuddy;
}

class personListBuddy : public QWidget
{
    Q_OBJECT

public:
    explicit personListBuddy(QString name="张三",QString ID= "123",QWidget *parent = 0);
    ~personListBuddy();

    QString headImgPath=":/data";//头像路径
//    void mousePressEvent(QMouseEvent* event) override;
    QString ToString();
    QString name;
    QString ID;
signals:
//    void LeftPush();
//    void RightPush();

private:
    Ui::personListBuddy *ui;

};

#endif // PERSONLISTBUDDY_H
