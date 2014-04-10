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
    model/gobject.cpp \
    model/gpoint.cpp \
    gui/additemdialog.cpp \
    gui/mainwindow.cpp \
    model/gpointlistmodel.cpp \
    controller/applicationcontroller.cpp \
    model/gobjectlistmodel.cpp \
    model/gwindow.cpp \
    model/gviewport.cpp


HEADERS  += \
    model/gobject.h \
    model/gpoint.h \
    gui/additemdialog.h \
    gui/mainwindow.h \
    test/model/test_gobject.h \
    test/model/test_gpoint.h \
    model/gpointlistmodel.h \
    test/model/test_gpointlistmodel.h \
    controller/applicationcontroller.h \
    model/gobjectlistmodel.h \
    model/gwindow.h \
    model/gviewport.h

FORMS    += mainwindow.ui \
    additemdialog.ui
