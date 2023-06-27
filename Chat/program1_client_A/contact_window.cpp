#include "contact_window.h"
#include "ui_contact_window.h"
#include "contactbuddy.h"
#include <QSize>
#include <QDebug>

contact_Window::contact_Window(user *owner,QString RoomID,QString name,user* Friend,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::contact_Window)
{
    ui->setupUi(this);
    IP= "127.0.0.1";
    Port = "1234";
    socket = new QTcpSocket;
    this->me = owner;
    this->RoomID = RoomID;
    this->name = name;
    this->people = Friend;

    contactToServer();
    communityControl();


}

contact_Window::~contact_Window()
{
    delete ui;
}

void contact_Window::contactToServer(){


    socket->connectToHost(QHostAddress(IP),Port.toShort());
//    qDebug()<<endl<<"connect prepra"<<endl;
    connect(socket,&QTcpSocket::connected,this,&contact_Window::contactPrepra);
}

void contact_Window::contactPrepra(){
    qDebug()<<endl<<"connect success"<<endl;
    QByteArray PrePraMessage;
//    QString meMessage = me->name;
//    QString RoomMessage = RoomID+":"+name;
//    QString friendMessage = people->ID+":"+people->name;
//    QString prepraMessage = ownerMessage+","+RoomMessage+","+friendMessage;
    PrePraMessage.append(me->name);

    socket->write(PrePraMessage);
//    QString a= me->ID+QString::number(me->groupNumber+1);
    //QByteArray能否传递除Qstring以外的东西
}

void contact_Window::communityControl(){
    connect(socket,&QTcpSocket::readyRead,this,&contact_Window::ShowOnScreen);
}

void contact_Window::ShowOnScreen(){
    QString message =QString(socket->readAll());

    QStringList list = message.split(":");

    contactbuddy *buddy = new contactbuddy(list[0],list[1]);
    QListWidgetItem* item = new QListWidgetItem();

    QSize size(290, 50);
    item->setSizeHint(size);
    ui->Contact->addItem(item);

    ui->Contact->setItemWidget(item,buddy);
}

void contact_Window::SetBuddy()
{
   contactbuddy *buddy = new contactbuddy();
   QListWidgetItem* item = new QListWidgetItem();
   //新建一个项
   //由于在测试阶段我们已经建立了一个默认项，所以测试阶段我们不会对项的属性进行更改
   // 设置项的边框样式为黑色实线边框

   // 将buddy设置为列表项
   QSize size(290, 50);
   item->setSizeHint(size);
   ui->Contact->addItem(item);

   ui->Contact->setItemWidget(item,buddy);

}

void contact_Window::on_SendButton_clicked()
{
    QString message=ui->WordEdit->text();

    ui->WordEdit->clear();
    QByteArray Message;
    Message.append(me->name+":"+message+":"+RoomID);
    socket->write(Message);

}
