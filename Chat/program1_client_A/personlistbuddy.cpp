#include "personlistbuddy.h"
#include "ui_personlistbuddy.h"
#include <QPainter>
#include<QDebug>


personListBuddy::personListBuddy(QString name,QString ID,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::personListBuddy)
{
    ui->setupUi(this);
    this->name=name;
    this->ID=ID;
    //初始化头像姓名信息
    ui->nameLabel->setText(name);
    ui->numberLabel->setText(ID);
    // 加载图片
    QPixmap pixmap(headImgPath+"/D/D_Img.jpg");

    // 设置QLabel显示图片

    ui->headImg->setPixmap(pixmap);

    // 调整QLabel的尺寸以适应图片

    ui->headImg->setScaledContents(true);
}

personListBuddy::~personListBuddy()
{
    delete ui;
}

QString personListBuddy::ToString()
{
    QString answer = this->name+":"+this->ID;

    return answer;
}

//void personListBuddy::mousePressEvent(QMouseEvent* event){
//    if (event->button() == Qt::LeftButton)
//    {
//        emit LeftPush();
//        // 左键按下时的操作
//    }
//    else if (event->button() == Qt::RightButton)
//    {
//        emit RightPush();
//        // 右键按下时的操作
//    }
//}

