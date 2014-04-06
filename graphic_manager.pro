#-------------------------------------------------
#
# Project created by QtCreator 2014-04-02T20:12:56
#
#-------------------------------------------------

QT       += core gui testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = graphic_manager
TEMPLATE = app
CONFIG += c++11


SOURCES += main.cpp\
        mainwindow.cpp \
    mainwindowcontroller.cpp \
    additemdialog.cpp \
    model/gobject.cpp \
    model/line.cpp \
    model/gpoint.cpp \
    test/model/testgpoint.cpp \
    test/model/testgobject.cpp

HEADERS  += mainwindow.h \
    mainwindowcontroller.h \
    additemdialog.h \
    model/gobject.h \
    model/line.h \
    model/gpoint.h \
    test/model/testgpoint.h \
    test/model/testgobject.h

FORMS    += mainwindow.ui \
    additemdialog.ui
