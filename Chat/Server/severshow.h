#ifndef SEVERSHOW_H
#define SEVERSHOW_H

#include <QWidget>
#include <QtWidgets>
#include <QTcpServer>
#include <QTcpSocket>

#define PORT 3786

QT_BEGIN_NAMESPACE
namespace Ui { class SeverShow; }
QT_END_NAMESPACE

class SeverShow : public QWidget
{
    Q_OBJECT

public:
    SeverShow(QWidget *parent = nullptr);
    ~SeverShow();
    bool init_server();
    bool get_message();
    void writtenLog(QString logString);
private:
    Ui::SeverShow *ui;
    QTcpServer *server;
    QTcpSocket *socket;

};
#endif // SEVERSHOW_H
