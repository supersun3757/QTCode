#include "mainmenu.h"
#include "ui_mainmenu.h"


MainMenu::MainMenu(user *I,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);

    //建立单元格
    me = I;
    Type ="F";
    SetFAndGList();
    //参考网站：https://www.zhangshengrong.com/p/v710KlP4XM/
    //https://blog.csdn.net/u010519432/article/details/26988515


}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::AddBuddy()
{
//   personListBuddy* buddy = new personListBuddy();
//   QListWidgetItem* item = new QListWidgetItem();
//   //新建一个项
//   //由于在测试阶段我们已经建立了一个默认项，所以测试阶段我们不会对项的属性进行更改
//   // 设置项的边框样式为黑色实线边框

//   // 将buddy设置为列表项
//   QSize size(290, 50);
//   item->setSizeHint(size);
//   ui->listWidget->addItem(item);
//   ui->listWidget->setItemWidget(item,buddy);

}

void MainMenu::SetFAndGList(){
    //建立群列表
    for (room* &Group:me->Groups) {
        personListBuddy* buddy = new personListBuddy(Group->roomName,Group->roomID);
        QListWidgetItem* item = new QListWidgetItem();
        //新建一个项
        //由于在测试阶段我们已经建立了一个默认项，所以测试阶段我们不会对项的属性进行更改
        // 将buddy设置为列表项
        QSize size(290, 50);
        item->setSizeHint(size);
        ui->Groups_listWidget->addItem(item);
        ui->Groups_listWidget->setItemWidget(item,buddy);

    }
    //建立好友列表
    for (user* &Friend:me->friends) {
        personListBuddy* buddy = new personListBuddy(Friend->name,Friend->ID);
        QListWidgetItem* item = new QListWidgetItem();
        //新建一个项
        //由于在测试阶段我们已经建立了一个默认项，所以测试阶段我们不会对项的属性进行更改
        // 将buddy设置为列表项
        QSize size(290, 50);
        item->setSizeHint(size);
        ui->Friends_listWidget->addItem(item);
        ui->Friends_listWidget->setItemWidget(item,buddy);

    }

}



void MainMenu::on_Friends_Button_clicked()
{
    QFont fontA("Microsoft YaHei", 13);

    QFont fontB("Microsoft YaHei", 15);
    fontB.setBold(true);
    Type = "F";
    ui->Friends_Button->setFont(fontB);
    ui->Group_Button->setFont(fontA);
    ui->Friends_listWidget->setHidden(false);
    ui->Groups_listWidget->setHidden(true);
    ui->Search_ListWidget->setHidden(true);
}

void MainMenu::on_Group_Button_clicked()
{
    Type ="G";
    QFont fontA("Microsoft YaHei", 13);

    QFont fontB("Microsoft YaHei", 15);
    fontB.setBold(true);
    ui->Friends_Button->setFont(fontA);
    ui->Group_Button->setFont(fontB);
    ui->Friends_listWidget->setHidden(true);
    ui->Groups_listWidget->setHidden(false);
    ui->Search_ListWidget->setHidden(true);
}



void MainMenu::on_Search_Button_clicked()
{
    ui->Friends_listWidget->setHidden(true);
    ui->Groups_listWidget->setHidden(true);
    ui->Search_ListWidget->setHidden(false);
    QString SearchID = ui->Searcg_Line->text();
    if(Type == "F"){
        for (user* Friend : me->friends){
            if(Friend->ID == SearchID){
                personListBuddy* buddy = new personListBuddy(Friend->name,Friend->ID);
                QListWidgetItem* item = new QListWidgetItem();
                //新建一个项
                //由于在测试阶段我们已经建立了一个默认项，所以测试阶段我们不会对项的属性进行更改
                // 将buddy设置为列表项
                QSize size(290, 50);
                item->setSizeHint(size);
                ui->Search_ListWidget->clear();
                ui->Search_ListWidget->addItem(item);
                ui->Search_ListWidget->setItemWidget(item,buddy);
                break;

            }
        }
    }else if(Type == "G"){
        for (room* Group : me->Groups){
            if(Group->roomID == SearchID){
                personListBuddy* buddy = new personListBuddy(Group->roomName,Group->roomID);
                QListWidgetItem* item = new QListWidgetItem();
                //新建一个项
                //由于在测试阶段我们已经建立了一个默认项，所以测试阶段我们不会对项的属性进行更改
                // 将buddy设置为列表项
                QSize size(290, 50);
                item->setSizeHint(size);
                ui->Search_ListWidget->clear();
                ui->Search_ListWidget->addItem(item);
                ui->Search_ListWidget->setItemWidget(item,buddy);
                break;
            }
        }
    }

}

void MainMenu::Connect(){
    QStringList list =str.split(":");
    QString name = list[0];
    QString ID =list[1];
    user* b = new user();
    b->name=name;
    b->ID=ID;

    if(Type == "F"){
        contact_Window* FWindow =new contact_Window(me,"00001",name,b);
        FWindow->show();
    }else if(Type == "G"){
        contact_Window* GWindow =new contact_Window(me,"00002",name,b);
        GWindow->show();
    }

}

void MainMenu::DeleteThis(){
    QStringList list =str.split(":");
    QString name = list[0];
    QString ID =list[1];
    if(Type == "F"){

         for(int i=0;i<me->friends.size();i++){
             if(me->friends[i]->ID == ID){
                 me->friends.erase(me->friends.begin()+i);
                 break;
             }
         }

        for(int i=0;i< ui->Friends_listWidget->count();i++){
            QListWidgetItem* item=ui->Friends_listWidget->item(i);
            personListBuddy* a= qobject_cast<personListBuddy*>(ui->Friends_listWidget->itemWidget(item));
            if(a->ID==ID){
                item= ui->Friends_listWidget->takeItem(i);
                delete item;
                delete a;
                break;
            }

        }
    }else if(Type == "G"){

        for(int i=0;i<me->Groups.size();i++){

            if(me->Groups[i]->roomID == ID){
                me->Groups.erase(me->Groups.begin()+i);
                break;
            }
        }



        for(int i=0;i< ui->Groups_listWidget->count();i++){
            QListWidgetItem* item=ui->Groups_listWidget->item(i);
            personListBuddy* a= qobject_cast<personListBuddy*>(ui->Groups_listWidget->itemWidget(item));
            if(a->ID==ID){
                item= ui->Groups_listWidget->takeItem(i);
                delete item;
                delete a;
            }

        }

    }


}

void MainMenu::on_Search_ListWidget_itemClicked(QListWidgetItem *item)
{
    QMenu* menu = new QMenu(this);
    QAction* action_build = new QAction("通讯", this);
    QAction* action_delete = new QAction("删除", this);
    menu->addAction(action_build);
    menu->addAction(action_delete);
    personListBuddy* a= qobject_cast<personListBuddy*>(ui->Search_ListWidget->itemWidget(item));
    str=a->ToString();

    connect(action_build, &QAction::triggered,this,&MainMenu::Connect);
    connect(action_delete, &QAction::triggered,this,&MainMenu::DeleteThis);
    menu->popup(QCursor::pos());
}



void MainMenu::on_Groups_listWidget_itemClicked(QListWidgetItem *item)
{
    QMenu* menu = new QMenu(this);
    QAction* action_build = new QAction("通讯", this);
    QAction* action_delete = new QAction("删除", this);
    menu->addAction(action_build);
    menu->addAction(action_delete);
    personListBuddy* a= qobject_cast<personListBuddy*>(ui->Groups_listWidget->itemWidget(item));
    str=a->ToString();

    connect(action_build, &QAction::triggered,this,&MainMenu::Connect);
    connect(action_delete, &QAction::triggered,this,&MainMenu::DeleteThis);
    menu->popup(QCursor::pos());
}



void MainMenu::on_Friends_listWidget_itemClicked(QListWidgetItem *item)
{
    QMenu* menu = new QMenu(this);
    QAction* action_build = new QAction("通讯", this);
    QAction* action_delete = new QAction("删除", this);
    menu->addAction(action_build);
    menu->addAction(action_delete);

    personListBuddy* a= qobject_cast<personListBuddy*>(ui->Friends_listWidget->itemWidget(item));

    str=a->ToString();

    connect(action_build, &QAction::triggered,this,&MainMenu::Connect);
    connect(action_delete, &QAction::triggered,this,&MainMenu::DeleteThis);
    menu->popup(QCursor::pos());

}
