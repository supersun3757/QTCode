#include "contactbuddy.h"
#include "ui_contactbuddy.h"

contactbuddy::contactbuddy(QString Name,QString word,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::contactbuddy)
{
    ui->setupUi(this);   



    //初始化头像姓名信息
    ui->nameLabel->setText(Name);
    ui->lineLabel->setText(word);
    // 加载图片
    QPixmap pixmap(headImgPath+"/D/D_Img.jpg");

    // 设置QLabel显示图片

    ui->headImg->setPixmap(pixmap);

    // 调整QLabel的尺寸以适应图片

    ui->headImg->setScaledContents(true);
}

contactbuddy::~contactbuddy()
{
    delete ui;
}

