#ifndef TESTGOBJECT_H
#define TESTGOBJECT_H

#include <QObject>
#include <QTest>

#include "model/gobject.h"
#include "model/operationbuilder.h"

class TestGObject : public QObject
{
    Q_OBJECT
public:
    explicit TestGObject(QObject *parent = 0):
        QObject(parent)
    {}

signals:

private Q_SLOTS:
    void testGraphicsItemEmpty()
    {
        GObject gObject("Nada");
        QGraphicsItem *item = gObject.toGraphicsItem();
        QVERIFY(item != 0);
    }

    void testGraphicsItemPoint()
    {
        GObject gObject("Ponto");
        gObject.append(GPoint(0,0));
        QGraphicsItem *item = gObject.toGraphicsItem();

        QVERIFY(item->contains(QPointF(0,0)));
    }

    void testGraphicsItemLine()
    {
        GObject gObject("Linha");
        gObject.append(GPoint(0,0));
        gObject.append(GPoint(1,1));
        QGraphicsItem *item = gObject.toGraphicsItem();
        QVERIFY(item->contains(QPointF(0,0)));
        QVERIFY(item->contains(QPointF(1,1)));
    }

    void testTransformation()
    {
        GObject expected;
        expected.append(GPoint(0,0));
        OperationBuilder *builder = new OperationBuilder;
        Operation operation = builder->build();
        GObject actual = expected.transform(operation);
        QCOMPARE(actual, expected);
    }

    void testToStringWithOneElement(){
        GObject object("obj");
        object.append(GPoint(0,0));
        QString actual = object.toString();
        QString expected = "obj : [{ X: 0, Y: 0, Z: 1 }, ]";
        QCOMPARE(actual, expected);
    }

    void testToStringWithTwoElements(){
        GObject object("obj");
        object.append(GPoint(0,0));
        object.append(GPoint(1,1));
        QString actual = object.toString();
        QString expected = "obj : [{ X: 0, Y: 0, Z: 1 }, { X: 1, Y: 1, Z: 1 }, ]";
        QCOMPARE(actual, expected);
    }

    void testCenterEmptyObjectShouldBeOrigin()
    {
        GObject object;

        GPoint actual = object.center();
        GPoint expected(0,0);
        QCOMPARE(actual, expected);
    }

    void testCenterOfPointShouldBeItself()
    {
        GObject object;
        object.append(GPoint(1,1));
        GPoint actual = object.center();
        GPoint expected(1,1);
        QCOMPARE(actual, expected);
    }

    void testCenterOfLineShouldBeCalculated()
    {
        GObject object;
        object.append(GPoint(1,1));
        object.append(GPoint(2,2));
        GPoint actual = object.center();
        GPoint expected(1.5,1.5);
        QCOMPARE(actual, expected);
    }
};

#endif // TESTGOBJECT_H
