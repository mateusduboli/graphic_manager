#ifndef LINE_H
#define LINE_H

#include "gobject.h"

class Line : public GObject
{
public:
    Line();
    virtual QGraphicsItem * graphicsItem();
};

#endif // LINE_H
