#ifndef GOBJECT_H
#define GOBJECT_H

#include <QGraphicsItem>
#include <QPen>
#include <functional>

#include "model/gpoint.h"
#include "model/types.h"

class GObject : public QVector<GPoint>
{
public:
    GObject(const QString &name = "");
    GObject(const QString &name, const QVector<GPoint> &points);
    GObject transform(Operation transformation);
    const GPoint center();
    QGraphicsItem * toGraphicsItem();
    const QString toString() const;
    const QString name() const;
private:
    QString _name;
};

#endif // GOBJECT_H
