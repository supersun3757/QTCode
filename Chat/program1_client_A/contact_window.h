#ifndef CONTACT_WINDOW_H
#define CONTACT_WINDOW_H

#include <QWidget>
#include <QTcpSocket>
#include <QHostAddress>
#include "user.h"
#include <QObject>

namespace Ui {
class contact_Window;
}

class contact_Window : public QWidget
{
    Q_OBJECT

public:
    explicit contact_Window(user *owner,QString RoomID,QString name,user* Friend,QWidget *parent = 0);
    ~contact_Window();
    void SetBuddy();
    void contactToServer();
    void contactPrepra();
    void communityControl();

private slots:
    void on_SendButton_clicked();
    void ShowOnScreen();
private:
    Ui::contact_Window *ui;
    QString IP;
    QString Port;
    QTcpSocket * socket;
    user * me;
    QString RoomID;
    QString name;
    user* people;
};

#endif // CONTACT_WINDOW_H
