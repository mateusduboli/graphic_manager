﻿#include <QApplication>
#include <QTest>

#include "gui/mainwindow.h"
#include "test/model/test_gpoint.h"
#include "test/model/test_gobject.h"
#include "test/model/test_operationbuilder.h"
#include "test/model/test_matrixoperations.h"
#include "test/controller/test_gpointlistmodel.h"

int program(int argc, char* argv[])
{
    QApplication a(argc, argv);
    ApplicationController *controller = new ApplicationController;
    MainWindow w(controller);
    controller->sampleObjects();
    w.show();
    return a.exec();
}

int tests(int argc, char* argv[])
{
    int status = 0;

    TestGPoint testGPoint;
    status |= QTest::qExec(&testGPoint, argc, argv);

    TestGObject testGObject;
    status |= QTest::qExec(&testGObject, argc, argv);

    TestGPointListModel testGPointListModel;
    status |= QTest::qExec(&testGPointListModel, argc, argv);

    TestOperationBuilder testOperationBuilder;
    status |= QTest::qExec(&testOperationBuilder, argc, argv);

    TestMatrixOperations testMatrixOperations;
    status |= QTest::qExec(&testMatrixOperations, argc, argv);

    return status;
}

int main(int argc, char *argv[])
{
    if(tests(argc, argv) == 0)
        program(argc, argv);
    else
        printf("Error in tests\n");
}
