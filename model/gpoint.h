#ifndef GPOINT_H
#define GPOINT_H

#include <functional>

#include <QPointF>
#include <QString>
#include <QMetaType>
#include <QDebug>

class GPoint
{
public:
    GPoint(const GPoint &copy);
    GPoint(const double x = 0, const double y = 0, const double z = 1);
    double x() const;
    double y() const;
    double z() const;
    const double *matrix() const;
    const QPointF toQPointF() const;
    const QString toString() const;
    GPoint operator+(const GPoint &other) const;
    bool operator==(const GPoint &other) const;
    bool operator!=(const GPoint &other) const;
    GPoint transform(std::function<GPoint (const GPoint)> transformation);
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
