#-------------------------------------------------
#
# Project created by QtCreator 2023-06-06T09:07:37
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = program1
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES +=\
    main.cpp \
    mainmenu.cpp \
    personlistbuddy.cpp \
    logasign.cpp \
    contact_window.cpp \
    contactbuddy.cpp \
    user.cpp \
    room.cpp

HEADERS  += \
    mainmenu.h \
    personlistbuddy.h \
    logasign.h \
    contact_window.h \
    contactbuddy.h \
    user.h \
    room.h

FORMS    += \
    mainmenu.ui \
    personlistbuddy.ui \
    logasign.ui \
    contact_window.ui \
    contactbuddy.ui

RESOURCES += \
    res.qrc
