#include "controller/applicationcontroller.h"

ApplicationController::ApplicationController(QObject *parent):
    QObject(parent)
{
    qDebug() << "[ApplicationController] constructor";

    qDebug() << "[ApplicationController] connecting";
    connect(&this->displayFile, &GObjectListModel::rowsInserted, this, &ApplicationController::refreshWindow);
    connect(this, &ApplicationController::operationBuildt, this, &ApplicationController::refreshWindow);

    qDebug() << "[ApplicationController] finished constructor";
}

void ApplicationController::sampleObjects()
{
    qDebug() << "[ApplicationController] creating sample objects";
    this->displayFile.append(GObject("X axis", {{
                                                    GPoint(0,-200),
                                                    GPoint(0,200)
                                                }}));
    this->displayFile.append(GObject("Y axis", {{
                                                    GPoint(-200,0),
                                                    GPoint(200,0)
                                                }}));
    this->displayFile.append(GObject("Sample square", {{
                                                           GPoint(-10,-10),
                                                           GPoint(10,-10),
                                                           GPoint(10,10),
                                                           GPoint(-10,10)
                                                       }}));
    emit this->refreshWindow();
}

void ApplicationController::refreshWindow()
{
    qDebug() << "[ApplicationController] refreshing window ";
    this->window.updateFramebuffer(&this->displayFile.objects);
    emit this->zoomChanged(QString::number(this->window.zoomFactor() * 100) + "%");
    emit this->centerChanged(this->window.center().toString());
}

void ApplicationController::createOperationScale(const double factor)
{
    qDebug() << "[ApplicationController] creating operation scale with factor: " << factor;
    this->operationList.appendOperationScale(factor);
}

void ApplicationController::createOperationRotate(const double degrees)
{
    qDebug() << "[ApplicationController] creating operation rotate with degrees: " << degrees;
    this->operationList.appendOperationRotate(degrees);
}

void ApplicationController::createOperationTranslate(const double x, const double y)
{
    qDebug() << "[ApplicationController] creating operation translate with movement: { x: " << x << ", y: " << y;
    this->operationList.appendOperationTranslate(x, y);
}

void ApplicationController::createPoint(const double x, const double y)
{
    qDebug() << "appending point.";
    GPoint point(x,y);
    qDebug() << "poins is: " << point;
    this->gPointList.append(point);
    qDebug() << "list is: " << this->gPointList;
}

void ApplicationController::editObject(const QModelIndex &index)
{
    this->selected = &this->displayFile.objects[index.row()];
    qDebug() << "[ApplicationController] Editing object : " << *this->selected;
    emit selectedObjectChanged(this->selected->name());
}

void ApplicationController::buildObject(const QString &name)
{
    qDebug() << "[ApplicationController] building object.";
    GObject *object = this->gPointList.build(name);
    qDebug() << "[ApplicationController] created object: " << *object;
    this->displayFile.append(*object);
    qDebug() << "[ApplicationController] list is now: " << this->displayFile;
}

void ApplicationController::buildOperation()
{
    qDebug() << "[ApplicationController] building operation";
    Operation op = this->operationList.build(this->selected->center());
    (*this->selected) = this->selected->transform(op);
    emit operationBuildt(this->selected);
}

void ApplicationController::resetZoom()
{
    qDebug() << "[ApplicationController] reseting zoom";
    this->window.clearZoomFactor();
    qDebug() << "[ApplicationController] zoom factor: " << this->window.zoomFactor();
    this->refreshWindow();
}

void ApplicationController::lessZoom()
{
    qDebug() << "[ApplicationController] zooming out";
    this->window.addZoomFactor(ZOOM_STEP);
    qDebug() << "[ApplicationController] zoom factor: " << QString::number(this->window.zoomFactor());
    this->refreshWindow();
}

void ApplicationController::moreZoom()
{
    qDebug() << "[ApplicationController] zooming in";
    this->window.addZoomFactor(-ZOOM_STEP);
    qDebug() << "[ApplicationController] zoom factor: " << QString::number(this->window.zoomFactor());
    this->refreshWindow();
}

void ApplicationController::centerPosition()
{
    qDebug() << "[ApplicationController] centering window";
    this->window.clearCenter();
    qDebug() << "[ApplicationController] center: " << this->window.center();
    this->refreshWindow();
}

void ApplicationController::moveLeft()
{
    qDebug() << "[ApplicationController] moving window left";
    this->window.moveCenter(GPoint(-1,0));
    qDebug() << "[ApplicationController] center: " << this->window.center();
    this->refreshWindow();
}

 void ApplicationController::moveUp()
{
    qDebug() << "[ApplicationController] moving window up";
    this->window.moveCenter(GPoint(0,-1));
    qDebug() << "[ApplicationController] center: " << this->window.center();
    this->refreshWindow();
}

void ApplicationController::moveDown()
{
    qDebug() << "[ApplicationController] moving window down";
    this->window.moveCenter(GPoint(0,1));
    qDebug() << "[ApplicationController] center: " << this->window.center();
    this->refreshWindow();
}

void ApplicationController::moveRight()
{
    qDebug() << "[ApplicationController] moving window right";
    this->window.moveCenter(GPoint(1,0));
    qDebug() << "[ApplicationController] center: " << this->window.center();
    this->refreshWindow();
}

void ApplicationController::rotateClock(const double degrees)
{
    qDebug() << "[ApplicationController] rotating window";
    this->window.rotate(degrees);
    this->refreshWindow();
}

void ApplicationController::rotateCounterClock(const double degrees)
{
    qDebug() << "[ApplicationController] rotating window";
    this->window.rotate(-degrees);
    this->refreshWindow();
}

