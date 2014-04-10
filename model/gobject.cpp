#include "model/gobject.h"

GObject::GObject():
    _name("")
{
}

GObject::GObject(const QString &name):
    _name(name)
{
}

GObject::GObject(const QString &name, const QVector<GPoint> &points):
    QVector(points),
    _name(name)
{
}

GObject GObject::transform(std::function<GPoint (const GPoint)> transformation)
{
    GObject newObject(_name);
    for(int i = 0; i < this->size();i++)
    {
        newObject.append(transformation(this->data()[i]));
    }
    return newObject;
}

QGraphicsPolygonItem *GObject::graphicsItem()
{
    QPolygonF polygon;
    for(int i = 0; i < this->size();i++)
    {
        GPoint point = this->at(i);
        QPointF qPoint = point.toQPointF();
        polygon.append(qPoint);
    }
    QGraphicsPolygonItem *gPolygon = new QGraphicsPolygonItem(polygon);
    return gPolygon;
}

const QString GObject::toString() const
{
    return this->_name;
}

const QString GObject::name() const
{
    return this->_name;
}

