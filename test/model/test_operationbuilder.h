#ifndef TEST_OPERATIONBUILDER_H
#define TEST_OPERATIONBUILDER_H

#include <QObject>
#include <QTest>

#include "model/operationbuilder.h"
#include "model/gobject.h"

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

    void testTranslatePointXOnCenter()
    {
        OperationBuilder builder;
        Operation op = builder.translate(1, 0).build();
        GPoint point(0, 0);

        GPoint expected(1, 0);
        GPoint actual = op(point);
        QCOMPARE(actual, expected);
    }

    void testTranslatePointYOnCenter()
    {
        OperationBuilder builder;
        Operation op = builder.translate(0, 1).build();
        GPoint point(0, 0);

        GPoint expected(0, 1);
        GPoint actual = op(point);
        QCOMPARE(actual, expected);
    }

    void testTranslatePointXOutOfCenter()
    {
        OperationBuilder builder;
        Operation op = builder.translate(1, 0).build();
        GPoint point(2, 0);

        GPoint expected(3, 0);
        GPoint actual = op(point);
        QCOMPARE(actual, expected);
    }

    void testTranslatePointYOutOfCenter()
    {
        OperationBuilder builder;
        Operation op = builder.translate(0, 1).build();
        GPoint point(0, 2);

        GPoint expected(0, 3);
        GPoint actual = op(point);
        QCOMPARE(actual, expected);
    }

    void testTranslatePointXandYOutOfCenterWithSameDistance()
    {
        OperationBuilder builder;
        Operation op = builder.translate(1, 1).build();
        GPoint point(1, 1);

        GPoint expected(2, 2);
        GPoint actual = op(point);
        QCOMPARE(actual, expected);
    }

    void testTranslatePointXandYOutOfCenterWitDifferentDistance()
    {
        OperationBuilder builder;
        Operation op = builder.translate(1, 2).build();
        GPoint point(2, 1);

        GPoint expected(3, 3);
        GPoint actual = op(point);
        QCOMPARE(actual, expected);
    }

    void testScallingPointByOneOnCenter()
    {
        OperationBuilder builder;
        Operation op = builder.scale(1).build();
        GPoint point(0, 0);

        GPoint expected(0, 0);
        GPoint actual = op(point);
        QCOMPARE(actual, expected);
    }

    void testScallingPointByOneOutOfCenter()
    {
        OperationBuilder builder;
        Operation op = builder.scale(1).build();
        GPoint point(1, 1);

        GPoint expected(1, 1);
        GPoint actual = op(point);
        QCOMPARE(actual, expected);
    }

    void testScallingPointByTwoOutOfCenter()
    {
        OperationBuilder builder;
        Operation op = builder.scale(2).build();
        GPoint point(1, 1);

        GPoint expected(2, 2);
        GPoint actual = op(point);
        QCOMPARE(actual, expected);
    }

    void testScallingObjectByTwoOutOfCenter()
    {
        GObject object;
        object.append(GPoint(0,0));
        object.append(GPoint(0,1));
        object.append(GPoint(1,1));
        object.append(GPoint(1,0));

        OperationBuilder builder;
        Operation op = builder.scale(2).build(object.center());

        GObject actual = object.transform(op);
        GObject expected;
        expected.append(GPoint(-0.5,-0.5));
        expected.append(GPoint(-0.5,1.5));
        expected.append(GPoint(1.5,1.5));
        expected.append(GPoint(1.5, -0.5));
        QCOMPARE(actual, expected);
    }

    void testRotatingOrigin()
    {
        GPoint point(0, 0);
        OperationBuilder builder;
        Operation op = builder.rotate(0).build();

        GPoint actual = op(point);
        GPoint expected = GPoint(0, 0);
        QCOMPARE(actual, expected);
    }

    void testRotatingPoint()
    {
        GPoint point(1, 5);
        OperationBuilder builder;
        Operation op = builder.rotate(90).build();

        GPoint actual = op(point);
        GPoint expected = GPoint(5.0, -1.0);
        QCOMPARE(actual, expected);
    }
};
#endif // TEST_OPERATIONBUILDER_H
