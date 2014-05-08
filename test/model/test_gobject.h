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
        QGraphicsItem *item = gObject.graphicsItem();
        QVERIFY(item != 0);
    }

    void testGraphicsItemPoint()
    {
        GObject gObject("Ponto");
        gObject.append(GPoint(0,0));
        QGraphicsItem *item = gObject.graphicsItem();

        QVERIFY(item->contains(QPointF(0,0)));
    }

    void testGraphicsItemLine()
    {
        GObject gObject("Linha");
        gObject.append(GPoint(0,0));
        gObject.append(GPoint(1,1));
        QGraphicsItem *item = gObject.graphicsItem();
        QVERIFY(item->contains(QPointF(0,0)));
        QVERIFY(item->contains(QPointF(1,1)));
    }

    void testTranslation()
    {
        GObject point;
        point.append(GPoint(0,0));
        OperationBuilder *builder = new OperationBuilder;
        Operation operation = builder->translate(0, 1).build();
        GObject translated = point.transform(operation);
        QCOMPARE(translated.at(0), GPoint(0, 1));
    }

};

#endif // TESTGOBJECT_H
