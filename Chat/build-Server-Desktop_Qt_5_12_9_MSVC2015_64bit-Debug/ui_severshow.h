/********************************************************************************
** Form generated from reading UI file 'severshow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEVERSHOW_H
#define UI_SEVERSHOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SeverShow
{
public:
    QListWidget *logslist;

    void setupUi(QWidget *SeverShow)
    {
        if (SeverShow->objectName().isEmpty())
            SeverShow->setObjectName(QString::fromUtf8("SeverShow"));
        SeverShow->resize(300, 600);
        logslist = new QListWidget(SeverShow);
        logslist->setObjectName(QString::fromUtf8("logslist"));
        logslist->setGeometry(QRect(0, 0, 300, 600));

        retranslateUi(SeverShow);

        QMetaObject::connectSlotsByName(SeverShow);
    } // setupUi

    void retranslateUi(QWidget *SeverShow)
    {
        SeverShow->setWindowTitle(QApplication::translate("SeverShow", "SeverShow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SeverShow: public Ui_SeverShow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEVERSHOW_H
