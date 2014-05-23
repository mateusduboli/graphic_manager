#ifndef GWINDOW_H
#define GWINDOW_H

#include <functional>
#include <QSize>
#include <QVector>
#include <QObject>

#include "model/gpoint.h"
#include "model/gobject.h"
#include "model/types.h"

class GWindow : public QObject
{
    Q_OBJECT
public:
    explicit GWindow(QObject* parent = 0, const GPoint &center = GPoint(0,0), const QSizeF &size = QSizeF(100,100));
    double height() const;
    double width() const;
    double zoomFactor() const;
    const GPoint max() const;
    const GPoint min() const;
    const GPoint center() const;
    void clearZoomFactor();
    void clearCenter();
    void moveCenter(const GPoint& movement);
    void addZoomFactor(const double &zoomFactor);
    void updateFramebuffer(QVector<GObject> *displayFile);
    QVector<GObject> framebuffer() const;
    Operation viewPortTransformation(const QSize viewPortSize);
signals:
    void framebufferChanged();
private:
    double _height;
    double _width;
    double _zoomFactor;
    GPoint _center;
    QVector<GObject> _framebuffer;
    std::function<GPoint (QSize, GPoint)> vpTransformation;
};

#endif // GWINDOW_H
