#include "severshow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SeverShow w;
    w.show();
    return a.exec();
}
