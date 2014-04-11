#include "gpoint.h"

GPoint::GPoint():
    _x(0.0),
    _y(0.0) {}

GPoint::GPoint(const GPoint& copy):
    _x(copy.x()),
    _y(copy.y()) {}

GPoint::GPoint(const double x, const double y):
    _x(x),
    _y(y) {}

double GPoint::x() const
{
    return this->_x;
}

double GPoint::y() const
{
    return this->_y;
}

const double *GPoint::matrix() const {
    const double *array = new double[2] {this->_x, this->_y};
    return array;
}

const QPointF GPoint::toQPointF() const {
    return QPointF(this->_x, this->_y);
}

const QString GPoint::toString() const
{
    return QString("{ X: %1, Y: %2 }").arg(this->_x, 0, 'g', 2).arg(this->_y, 0, 'g', 2);
}

GPoint GPoint::operator+(const GPoint &other) const
{
    return GPoint(_x + other.x(), _y + other.y());
}

bool GPoint::operator==(const GPoint &other) const
{
    return this->_x == other.x() && this->_y == other.y();
}

GPoint GPoint::transform(std::function<GPoint (const GPoint)> transformation)
{
    return transformation(*this);
}


QDebug operator<<(QDebug b, const GPoint &point)
{
    return b << point.toString();
}
