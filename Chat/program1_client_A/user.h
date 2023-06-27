#ifndef USER_H
#define USER_H

#include <QWidget>
#include <vector>
#include "room.h"
class user
{
public:
    user();
    user(const user* a);
    QString ID;
    QString name;
    QString password;

    std::vector<user*> friends;
    std::vector<room*> Groups;
    QString ToString();
    void StringTo(QString str);
private:

};



#endif // USER_H
