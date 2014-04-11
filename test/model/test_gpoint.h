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
        GPoint point(0,0);
        QCOMPARE(point.x(), 0.0);
        QCOMPARE(point.y(), 0.0);
    }

    void testConstructorWithParameters()
    {
        double x = 2.0;
        double y = -3.5;
        GPoint point(x, y);
        QCOMPARE(point.x(), x);
        QCOMPARE(point.y(), y);
    }

    void testCopyConstructor()
    {
        double x = 2.0;
        double y = -3.5;
        const GPoint expected(x, y);
        const GPoint actual(expected);
        QCOMPARE(expected, actual);
    }

    void testMatrix()
    {
        double x = -1.0;
        double y = 9.0;
        GPoint point(x, y);
        const double * matrix = point.matrix();
        double reference[] = {x, y};
        QCOMPARE(matrix[0], reference[0]);
        QCOMPARE(matrix[1], reference[1]);
    }

    void testToQPointF()
    {
        double x = -4.0;
        double y = 9.0;
        GPoint point(x, y);
        QPointF reference(x, y);
        QCOMPARE(point.toQPointF(), reference);
    }

    void testoToString()
    {
        double x = -4.0;
        double y = 9.0;
        GPoint actual(x, y);
        QString expected = "{ X: -4, Y: 9 }";
        QCOMPARE(actual.toString(), expected);
    }
};

#endif // TESTGPOINT_H
