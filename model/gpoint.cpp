#include "gpoint.h"

GPoint::GPoint():
    x(0.0), y(0.0) {}

GPoint::GPoint(const GPoint& copy):
    x(copy.x), y(copy.y) {}

GPoint::GPoint(const double x, const double y):
    x(x), y(y) {}

double GPoint::getX() const
{
    return x;
}

double GPoint::getY() const
{
    return y;
}

const double *GPoint::matrix() const {
    const double *array = new double[2] {x, y};
    return array;
}

const QPointF GPoint::toQPointF() const {
    return QPointF(x, y);
}

