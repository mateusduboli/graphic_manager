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
    controller/applicationcontroller.cpp \
    model/gwindow.cpp \
    model/gviewport.cpp \
    model/operationbuilder.cpp \
    controller/gobjectlistmodel.cpp \
    controller/gpointlistmodel.cpp \
    model/matrixoperations.cpp \
    gui/edititemdialog.cpp \
    controller/operationlistmodel.cpp


HEADERS  += \
    model/gobject.h \
    model/gpoint.h \
    gui/additemdialog.h \
    gui/mainwindow.h \
    test/model/test_gobject.h \
    test/model/test_gpoint.h \
    controller/applicationcontroller.h \
    model/gwindow.h \
    model/gviewport.h \
    model/operationbuilder.h \
    controller/gpointlistmodel.h \
    controller/gobjectlistmodel.h \
    test/controller/test_gpointlistmodel.h \
    test/model/test_operationbuilder.h \
    model/matrixoperations.h \
    test/model/test_matrixoperations.h \
    model/types.h \
    gui/edititemdialog.h \
    controller/operationlistmodel.h

FORMS    += gui/mainwindow.ui \
    gui/additemdialog.ui \
    gui/edititemdialog.ui
