#include <QApplication>
#include <QTest>

#include "mainwindow.h"
#include "test/model/testgpoint.h"
#include "test/model/testgobject.h"

int program(int argc, char* argv[])
{
    QApplication a(argc, argv);
    MainWindowController *controller = new MainWindowController;
    MainWindow w(controller);
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

    return status;
}

int main(int argc, char *argv[])
{
    if(tests(argc, argv) == 0)
        program(argc, argv);
    else
        printf("Error in tests\n");
}
