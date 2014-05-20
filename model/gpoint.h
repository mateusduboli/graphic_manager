#ifndef GPOINT_H
#define GPOINT_H

#include <functional>
#include <array>
#include <cmath>

#include <QPointF>
#include <QString>
#include <QMetaType>
#include <QDebug>

#include "model/types.h"

class GPoint
{
public:
    GPoint(const GPoint &copy);
    GPoint(const double x = 0, const double y = 0, const double z = 1);
    GPoint(const Vector vector);
    double x() const;
    double y() const;
    double z() const;
    const Vector vector() const;
    const QPointF toQPointF() const;
    const QString toString() const;
    GPoint operator+(const GPoint &other) const;
    bool operator==(const GPoint &other) const;
    bool operator!=(const GPoint &other) const;
    operator QString();
    operator QPointF();
    friend QDebug operator<<(QDebug b, const GPoint &point);
private:
    double _x;
    double _y;
    double _z;
};

Q_DECLARE_METATYPE(GPoint)

#endif // GPOINT_H
