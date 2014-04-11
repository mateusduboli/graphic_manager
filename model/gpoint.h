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
    GPoint();
    GPoint(const GPoint &copy);
    GPoint(const double x, const double y);
    double x() const;
    double y() const;
    const double *matrix() const;
    const QPointF toQPointF() const;
    const QString toString() const;
    GPoint operator+(const GPoint &other) const;
    bool operator==(const GPoint &other) const;
    GPoint transform(std::function<GPoint (const GPoint)> transformation);
    friend QDebug operator<<(QDebug b, const GPoint &point);
private:
    double _x;
    double _y;
};

Q_DECLARE_METATYPE(GPoint)

#endif // GPOINT_H
