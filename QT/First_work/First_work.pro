#-------------------------------------------------
#
# Project created by QtCreator 2016-09-08T13:33:20
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = First_work
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    cxtime.cpp

HEADERS  += mainwindow.h \
    reader.h \
    cxtime.h \
    newspaper.h

FORMS    += mainwindow.ui

RESOURCES += \
    res.qrc

CODECFORTR = utf-8 #or gbk
#DEFAULTCODEC = utf-8
#CODEC = utf-8
