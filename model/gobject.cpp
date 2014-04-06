#include "model/gobject.h"

GObject::GObject()
{
}

QGraphicsPolygonItem *GObject::graphicsItem()
{
    QVector<QPointF> qPoints;
    for(GPoint point : *this)
    {
        QPointF qPoint = point.toQPointF();
        qPoints.append(qPoint);
    }
    QPolygonF polygon(qPoints);
    QGraphicsPolygonItem *gPolygon = new QGraphicsPolygonItem(polygon);
    return gPolygon;
}


