#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>
#include <QToolButton>
#include <QContextMenuEvent>
#include <QMenu>
#include <QPixmap>
#include <QIcon>
#include <QListWidgetItem>
#include <QMouseEvent>
#include <QApplication>
#include <QDebug>
#include <QListWidget>
#include <vector>

#include "personlistbuddy.h"
#include "user.h"
#include "contact_window.h"
namespace Ui {
class MainMenu;
}


class MainMenu : public QWidget
{
    Q_OBJECT

public:
    explicit MainMenu(user *I,QWidget *parent = 0);
    ~MainMenu();

    void AddBuddy();

    void SetFAndGList();


signals:


private slots:
    void on_Friends_Button_clicked();

    void on_Group_Button_clicked();



    void on_Search_Button_clicked();


    void on_Search_ListWidget_itemClicked(QListWidgetItem *item);


    void on_Groups_listWidget_itemClicked(QListWidgetItem *item);


    void on_Friends_listWidget_itemClicked(QListWidgetItem *item);

private:
    Ui::MainMenu *ui;

    user * me;
    QString Type;
    void Connect();
    void DeleteThis();
    QString str;

};

#endif // MAINMENU_H
