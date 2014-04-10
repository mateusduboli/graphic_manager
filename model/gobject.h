#ifndef GOBJECT_H
#define GOBJECT_H

#include <QGraphicsItem>
#include <functional>

#include "model/gpoint.h"

class GObject : public QVector<GPoint>
{
public:
    GObject();
    GObject(const QString &name);
    GObject(const QString &name, const QVector<GPoint> &points);
    GObject transform(std::function<GPoint (const GPoint)> transformation);
    QGraphicsPolygonItem * graphicsItem();
    QGraphicsPolygonItem * graphicsItem(std::function<GPoint (const GPoint)> transformation);
    const QString toString() const;
    const QString name() const;
private:
    QString _name;
};

#endif // GOBJECT_H
