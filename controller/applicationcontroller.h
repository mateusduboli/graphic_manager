#ifndef APPLICATIONCONTROLLER_H
#define APPLICATIONCONTROLLER_H

#include <QGraphicsScene>
#include <QDebug>

#include "model/gobject.h"
#include "model/gpointlistmodel.h"
#include "model/gobjectlistmodel.h"
#include "model/gwindow.h"

#define ZOOM_STEP 0.05

class ApplicationController : public QObject
{
    Q_OBJECT
public:
    explicit ApplicationController(QObject *parent = 0);
    QGraphicsScene scene;
    GObjectListModel displayFile;
    GPointListModel gPointList;
    void setWindowSize(const GPoint &center, const QSize &size);
    void createPoint(const double x, const double y);
    void buildObject(const QString &name);
public slots:
    void refreshScene();
    void resetZoom();
    void lessZoom();
    void moreZoom();
    void centerPosition();
    void moveLeft();
    void moveUp();
    void moveDown();
    void moveRight();
signals:
    void zoomChanged(const QString &zoomStringValue);
    void centerChanged(const QString &centerStringValue);
private:
    GWindow *window;
};

#endif // APPLICATIONCONTROLLER_H
