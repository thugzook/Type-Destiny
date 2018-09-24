#-------------------------------------------------
#
# Project created by QtCreator 2015-04-24T16:10:45
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TypeDestiny
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    maingame.cpp \
    maingame2.cpp \
    gameover.cpp

HEADERS  += mainwindow.h \
    maingame.h \
    maingame2.h \
    gameover.h

FORMS    += mainwindow.ui \
    maingame.ui \
    maingame2.ui \
    gameover.ui

RESOURCES += \
    images.qrc \
    sounds.qrc
