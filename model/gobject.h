#ifndef GOBJECT_H
#define GOBJECT_H

#include <QGraphicsItem>

#include "model/gpoint.h"

class GObject : public QVector<GPoint>
{
public:
    GObject();
    QGraphicsPolygonItem * graphicsItem();
};

#endif // GOBJECT_H
