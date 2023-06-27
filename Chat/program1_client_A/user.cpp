#include "user.h"

user::user()
{
    ID ="23456";
    name = "李四";
    password = "abcd";
    user * temple_user_1 = new user(this);
    temple_user_1->name="张三";
    temple_user_1->ID="12345";
    user * temple_user_2 = new user(this);
    temple_user_2->name="王五";
    temple_user_2->ID="34567";


    QString RoomID_2 = "00002";
    QString RoomName_2 = "群聊";
    room * temple_room_2 = new room(RoomID_2,RoomName_2);

    friends.push_back(temple_user_1);
    friends.push_back(temple_user_2);
    Groups.push_back(temple_room_2);

}

user::user(const user* a){
    ID = a->ID;
    name = a->name;
    password = a->password;

}

QString user::ToString(){
    return ID+":"+name+":"+password+":";

}

void user::StringTo(QString str){
    QStringList list = str.split(":");
    ID= list[0];
    name = list[1];
    password = list[2];

}
