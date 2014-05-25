#include "gpoint.h"

GPoint::GPoint(const GPoint& copy):
    _x(copy.x()),
    _y(copy.y()),
    _z(copy.z())
{}

GPoint::GPoint(const double x, const double y, const double z):
    _x(x),
    _y(y),
    _z(z)
{}

GPoint::GPoint(const Vector vector):
    _x(vector[0]),
    _y(vector[1]),
    _z(vector[2])
{}

double GPoint::x() const
{
    return this->_x;
}

double GPoint::y() const
{
    return this->_y;
}

double GPoint::z() const
{
    return this->_z;
}

const Vector GPoint::vector() const {
    const Vector vector {{this->_x, this->_y, this->_z}};
    return vector;
}

const QPointF GPoint::toQPointF() const {
    return QPointF(this->_x, this->_y);
}

const QPoint GPoint::toQPoint() const
{
    return QPoint(this->_x, this->_y);
}

const QString GPoint::toString() const
{
    return QString("{ X: %1, Y: %2, Z: %3 }")
            .arg(this->_x, 0, 'g', 20)
            .arg(this->_y, 0, 'g', 20)
            .arg(this->_z, 0, 'g', 20);
}

GPoint GPoint::operator+(const GPoint &other) const
{
    return GPoint(_x + other.x(), _y + other.y());
}

GPoint GPoint::operator-() const
{
    return GPoint(-this->_x, -this->_y);
}

bool GPoint::operator==(const GPoint &other) const
{
    const double eps = 1e-6;
    return  abs(this->_x - other.x()) < eps &&
            abs(this->_y - other.y()) < eps &&
            abs(this->_z - other.z()) < eps;
}

bool GPoint::operator!=(const GPoint &other) const
{
    return !((*this) == other);
}

GPoint::operator QPointF()
{
    return this->toQPointF();
}

GPoint::operator QString()
{
    return this->toString();
}

QDebug operator<<(QDebug b, const GPoint &point)
{
    return b << point.toString();
}
