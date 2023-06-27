 #include "logasign.h"
#include "mainmenu.h"
#include "personlistbuddy.h"
#include "contactbuddy.h"
#include "contact_window.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    user me;
//    logASign load(&me);
    MainMenu menu(&me);

//    load.show();
//    QObject::connect(&load,SIGNAL(loadOver()), &a,SLOT(quit()));
//    //当调用 app.quit() 时，Qt 的事件循环将被终止，QCoreApplication::exec() 函数将返回，
//    //并且 main() 函数中的执行流将继续执行下一步代码（如果有的话）

    menu.show();

    return a.exec();
}


