#include "model/gobject.h"

GObject::GObject(const QString &name):
    _name(name)
{
}

GObject::GObject(const QString &name, const QVector<GPoint> &points):
    QVector(points),
    _name(name)
{
}

GObject GObject::transform(Operation transformation)
{
    GObject newObject(_name);
    for(GPoint point : *this)
    {
        newObject.append(transformation(point));
    }
    return newObject;
}

const GPoint GObject::center()
{
    double centerX = 0;
    double centerY = 0;
    for(GPoint point : *this){
        centerX += point.x();
        centerY += point.y();
    }
    if(this->size() > 0) {
        centerX /= this->size();
        centerY /= this->size();
    }
    return GPoint(centerX, centerY);
}

QGraphicsItem *GObject::toGraphicsItem()
{
    // If size equals one, draw point
    if (this->size() == 1)
    {
        GPoint point = this->at(0);
        qreal x = point.x();
        qreal y = point.y();
        return new QGraphicsEllipseItem(x, y, 1, 1);
    }

    QPolygonF polygon;
    for(int i = 0; i < this->size();i++)
    {
        GPoint point = this->at(i);
        QPointF qPoint = point;
        polygon.append(qPoint);
    }
    QGraphicsPolygonItem *gPolygon = new QGraphicsPolygonItem(polygon);
    return gPolygon;
}

const QString GObject::toString() const
{
    QString result = this->_name;
    result.append(" : [");
    for(GPoint point : *this) {
        result.append(point.toString());
        result.append(", ");
    }
    result.append("]");
    return result;
}

const QPolygon GObject::toQPolygon() const
{
    QPolygon polygon;
    for(GPoint point : *this)
    {
        polygon.append(point.toQPoint());
    }
    return polygon;
}

const QString GObject::name() const
{
    return this->_name;
}

