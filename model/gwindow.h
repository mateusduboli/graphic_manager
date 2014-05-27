#ifndef GWINDOW_H
#define GWINDOW_H

#include <functional>
#include <QSize>
#include <QVector>
#include <QObject>

#include "model/types.h"
#include "model/gpoint.h"
#include "model/gobject.h"
#include "model/operationbuilder.h"

using namespace std;

class GWindow : public QObject
{
    Q_OBJECT
public:
    explicit GWindow(QObject* parent = 0, const GPoint &center = GPoint(0,0), const QSizeF &size = QSizeF(100,100));
    double height() const;
    double width() const;
    double angle() const;
    double zoomFactor() const;
    const QSizeF size() const;
    const GPoint max() const;
    const GPoint min() const;
    const GPoint center() const;
    void clearZoomFactor();
    void clearCenter();
    void rotate(const double degrees);
    void move(const GPoint movement);
    void addZoomFactor(const double factor);
    void updateFramebuffer(QVector<GObject> *displayFile);
    QVector<GObject> framebuffer() const;
    Operation viewPortTransformation(const QSize viewPortSize);
signals:
    void framebufferChanged();
private:
    double _height;
    double _width;
    double _zoomFactor;
    double _angle;
    GPoint _center;
    QVector<GObject> _framebuffer;
    function<GPoint (GPoint, QSizeF, QSize, GPoint)> vpTransformation;
    function<GPoint (double, GPoint, GPoint)> ppcTransformation;
};

#endif // GWINDOW_H
