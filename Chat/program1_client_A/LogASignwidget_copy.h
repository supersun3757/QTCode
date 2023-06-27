#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class LogASignwidget;
}

class LogASignwidget : public QWidget
{
    Q_OBJECT

public:
    explicit LogASignwidget(QWidget *parent = 0);
    ~LogASignwidget();

private:
    Ui::LogASignwidget *ui;
};

#endif // WIDGET_H
