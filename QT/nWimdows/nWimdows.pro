#-------------------------------------------------
#
# Project created by QtCreator 2016-09-10T10:39:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = nWimdows
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    logindlg.cpp

HEADERS  += mainwindow.h \
    logindlg.h

FORMS    += mainwindow.ui \
    logindlg.ui

RESOURCES += \
    rec.qrc
