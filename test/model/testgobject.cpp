#include "testgobject.h"

TestGObject::TestGObject(QObject *parent) :
    QObject(parent)
{
}

void TestGObject::testGraphicsItemEmpty()
{
    GObject gObject;
    QGraphicsPolygonItem *item = gObject.graphicsItem();
    QVERIFY(item != 0);
}
