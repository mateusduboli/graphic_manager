#ifndef GWINDOW_H
#define GWINDOW_H

#include <functional>
#include <QSize>

#include "model/gpoint.h"

class GWindow
{
public:
    GWindow(const GPoint &center, const QSize &size);
    double height() const;
    double width() const;
    GPoint max() const;
    GPoint min() const;
    GPoint center() const;
    void clearZoomFactor();
    void clearCenter();
    void moveCenter(const GPoint& movement);
    void subZoomFactor(const double &zoomFactor);
    void addZoomFactor(const double &zoomFactor);
    double zoomFactor() const;
    GPoint toViewPort(const GPoint point,const QSizeF viewPortSize);
    std::function<GPoint (GPoint)> viewPortTransformation(const QSizeF viewPortSize);
private:
    double _height;
    double _width;
    double _zoomFactor;
    GPoint _center;
    std::function<GPoint (QSizeF, GPoint)> vpTransformation;
};

#endif // GWINDOW_H
