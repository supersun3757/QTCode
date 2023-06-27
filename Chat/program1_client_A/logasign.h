#ifndef LOGASIGN_H
#define LOGASIGN_H

#include <QWidget>
#include"user.h"
namespace Ui {
class logASign;
}

class logASign : public QWidget
{
    Q_OBJECT

public:
    explicit logASign(user * u,QWidget *parent = 0);
    ~logASign();

signals:
    void loadOver();

private slots:
    void on_Sign_Button_clicked();

    void on_Login_Button_clicked();

private:
    void SetUser();
    user * me;
    Ui::logASign *ui;
};

#endif // LOGASIGN_H
