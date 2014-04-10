#ifndef TESTGOBJECT_H
#define TESTGOBJECT_H

#include <QObject>
#include <QTest>

#include "model/gobject.h"

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
        QGraphicsPolygonItem *item = gObject.graphicsItem();
        QVERIFY(item != 0);
    }

    void testGraphicsItemPoint()
    {
        GObject gObject("Ponto");
        gObject.append(GPoint(0,0));
        QGraphicsPolygonItem *item = gObject.graphicsItem();

        QPolygonF reference;
        reference.append(QPointF(0,0));
        QCOMPARE(item->polygon(), reference);
    }

    void testGraphicsItemLine()
    {
        GObject gObject("Linha");
        gObject.append(GPoint(0,0));
        gObject.append(GPoint(1,1));
        QGraphicsPolygonItem *item = gObject.graphicsItem();

        QPolygonF reference;
        reference.append(QPointF(0,0));
        reference.append(QPointF(1,1));
        QCOMPARE(item->polygon(), reference);
    }

};

#endif // TESTGOBJECT_H
