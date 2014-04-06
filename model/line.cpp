#include "line.h"

Line::Line()
{
}

QGraphicsItem * Line::graphicsItem()
{
    QGraphicsPolygonItem * polygonItem = new QGraphicsPolygonItem;
    QPolygonF polygon;
    polygon << QPointF(10.4, 20.5) << QPointF(20.2, 30.2);
    polygonItem->setPolygon(polygon);
    return polygonItem;
}
