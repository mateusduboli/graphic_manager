#ifndef APPLICATIONCONTROLLER_H
#define APPLICATIONCONTROLLER_H

#include <QGraphicsScene>
#include <QDebug>

#include "model/gobject.h"
#include "model/gwindow.h"

#include "controller/gobjectlistmodel.h"
#include "controller/gpointlistmodel.h"
#include "controller/operationlistmodel.h"

#define ZOOM_STEP 0.05

class ApplicationController : public QObject
{
    Q_OBJECT
public:
    explicit ApplicationController(QObject *parent = 0);
    QGraphicsScene scene;
    GObject *selected; //TODO Move selected to EditItemDialog
    GObjectListModel displayFile;
    GPointListModel gPointList;
    OperationListModel operationList;
    void setWindowSize(const GPoint &center, const QSize &size);
    void createPoint(const double x, const double y);
    void editObject(const QModelIndex &index);
    void buildObject(const QString &name);
    void buildOperation();
    void createOperationScale(const double factor);
    void createOperationRotate(const double degrees);
    void createOperationTranslate(const double x, const double y);
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
    void selectedObjectChanged(const QString &name);
    void operationBuildt(const GObject* object);
private:
    GWindow *window;
};

#endif // APPLICATIONCONTROLLER_H
