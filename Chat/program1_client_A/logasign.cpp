#include "logasign.h"
#include "ui_logasign.h"

logASign::logASign(user * u,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::logASign)
{
    ui->setupUi(this);
    ui->PassWord_Edit->setPlaceholderText("password");
    ui->ID_Edit->setPlaceholderText("ID");
    me = u;
}

logASign::~logASign()
{
    delete ui;
}

void logASign::on_Sign_Button_clicked()
{
    SetUser();
    emit loadOver();
}


void logASign::on_Login_Button_clicked()
{
    SetUser();
    emit loadOver();
}

void logASign::SetUser(){
    me->ID=ui->ID_Edit->text();
    me->name=ui->ID_Edit->text();
    me->password = ui->ID_Edit->text();
}


