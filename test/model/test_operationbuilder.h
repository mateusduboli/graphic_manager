#ifndef TEST_OPERATIONBUILDER_H
#define TEST_OPERATIONBUILDER_H

#include <QObject>
#include <QTest>

#include "model/operationbuilder.h"

class TestOperationBuilder : public QObject
{
    Q_OBJECT
public:
    explicit TestOperationBuilder(QObject *parent = 0):
        QObject(parent)
    {}

private Q_SLOTS:
    void testConstructor()
    {
        OperationBuilder* builder = new OperationBuilder;
        QVERIFY(builder != 0);
        delete builder;
    }

    void testBuild()
    {
        OperationBuilder builder;
        Operation actual = builder.build();
        // Test if is callable
        QVERIFY((bool) actual);
    }

    void testTranslateWithNoMovement()
    {
        OperationBuilder builder;
        Operation op = builder.translate(0, 0).build();

        GPoint expected(0,0);
        GPoint actual = op(expected);
        QCOMPARE(actual, expected);
    }

    void testTranslateMovingOnX()
    {
        OperationBuilder builder;
        Operation op = builder.translate(1, 0).build();
        GPoint point;

        GPoint expected(1, 0);
        GPoint actual = op(point);
        QCOMPARE(actual, expected);
    }
};
#endif // TEST_OPERATIONBUILDER_H
