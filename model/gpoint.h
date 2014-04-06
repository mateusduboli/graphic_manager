#ifndef GPOINT_H
#define GPOINT_H

#include <QPointF>

class GPoint
{
public:
    GPoint();
    GPoint(const GPoint &copy);
    GPoint(const double x, const double y);
    double getX() const;
    double getY() const;
    const double *matrix() const;
    const QPointF toQPointF() const;
private:
    double x;
    double y;
};

#endif // GPOINT_H
