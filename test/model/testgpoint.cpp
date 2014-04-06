#include "test/model/testgpoint.h"

TestGPoint::TestGPoint(QObject *parent) :
    QObject(parent)
{
}

void TestGPoint::testConstructor()
{
    GPoint point;
    QCOMPARE(point.getX(), 0.0);
    QCOMPARE(point.getY(), 0.0);
}

void TestGPoint::testConstructorWithParameters()
{
    double x = 2.0;
    double y = -3.5;
    GPoint point(x, y);
    QCOMPARE(point.getX(), x);
    QCOMPARE(point.getY(), y);
}

void TestGPoint::testMatrix()
{
    double x = -1.0;
    double y = 9.0;
    GPoint point(x, y);
    const double * matrix = point.matrix();
    double reference[] = {x, y};
    QCOMPARE(matrix[0], reference[0]);
    QCOMPARE(matrix[1], reference[1]);
}

void TestGPoint::testToQPointF()
{
    double x = -4.0;
    double y = 9.0;
    GPoint point(x, y);
    QPointF reference(x, y);
    QCOMPARE(point.toQPointF(), reference);
}
