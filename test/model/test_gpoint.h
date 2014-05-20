#ifndef TESTGPOINT_H
#define TESTGPOINT_H

#include <QObject>
#include <QTest>

#include "model/gpoint.h"

class TestGPoint : public QObject
{
    Q_OBJECT
public:
    explicit TestGPoint(QObject *parent = 0)
        : QObject(parent)
    {}

private Q_SLOTS:
    void testConstructor()
    {
        GPoint point;
        QCOMPARE(point.x(), 0.0);
        QCOMPARE(point.y(), 0.0);
        QCOMPARE(point.z(), 1.0);
    }

    void testConstructorWithParameters()
    {
        double x = 2.0;
        double y = -3.5;
        double z = 2;
        GPoint point(x, y, z);
        QCOMPARE(point.x(), x);
        QCOMPARE(point.y(), y);
        QCOMPARE(point.z(), z);
    }

    void testCopyConstructor()
    {
        double x = 2.0;
        double y = -3.5;
        double z = 4;
        const GPoint expected(x, y, z);
        const GPoint actual(expected);
        QCOMPARE(expected, actual);
    }

    void testVectorConstructor()
    {
        double x = 2.0;
        double y = -3.5;
        double z = 4;
        Vector vector {{x, y, z}};
        const GPoint expected(x, y, z);
        const GPoint actual(vector);
        QCOMPARE(expected, actual);
    }

    void testCompareSucess()
    {
        double x = 2.0;
        double y = -3.5;
        double z = 4;
        GPoint point1(x, y, z);
        GPoint point2(x, y, z);
        QCOMPARE(point1, point2);
    }

    void testCompareFailure()
    {
        double x = 2.0;
        double y = -3.5;
        double z = 4;
        const GPoint reference(x, y, z);
        const GPoint diff_x(x + 1, y, z);
        const GPoint diff_y(x, y + 1, z);
        const GPoint diff_z(x, y, z + 1);
        QVERIFY(reference != diff_x);
        QVERIFY(reference != diff_y);
        QVERIFY(reference != diff_z);
    }

    void testVector()
    {
        double x = -1.0;
        double y = 9.0;
        GPoint point(x, y);
        const Vector actual = point.vector();
        double reference[] = {x, y, 1};
        QCOMPARE(actual[0], reference[0]);
        QCOMPARE(actual[1], reference[1]);
        QCOMPARE(actual[2], reference[2]);
    }

    void testToQPointF()
    {
        double x = -4.0;
        double y = 9.0;
        GPoint point(x, y);
        QPointF actual = point;
        QPointF reference(x, y);
        QCOMPARE(actual, reference);
    }

    void testoToString()
    {
        double x = -4.0;
        double y = 9.0;
        GPoint point(x, y);
        QString actual = point;
        QString expected = "{ X: -4, Y: 9, Z: 1 }";
        QCOMPARE(actual, expected);
    }

    void testQStringOperator()
    {
        QString expected("{ X: 9, Y: 2, Z: 1 }");
        GPoint point(9, 2);
        QString actual = point;
        QCOMPARE(actual, expected);
    }

};

#endif // TESTGPOINT_H
