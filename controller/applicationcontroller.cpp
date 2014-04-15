#include "controller/applicationcontroller.h"

ApplicationController::ApplicationController(QObject *parent):
    QObject(parent)
{
    qDebug() << "constructor";
    connect(&this->displayFile, &GObjectListModel::rowsInserted, this, &ApplicationController::refreshScene);
    connect(this, &ApplicationController::zoomChanged, this, &ApplicationController::refreshScene);
    connect(this, &ApplicationController::centerChanged, this, &ApplicationController::refreshScene);
}

void ApplicationController::setWindowSize(const GPoint &center, const QSize &size)
{
    qDebug() << "setting window size to: " << size;
    this->window = new GWindow(center, size);
    emit this->zoomChanged(QString::number(this->window->zoomFactor() * 100) + "%");
    emit this->centerChanged(this->window->center().toString());
}

void ApplicationController::createPoint(const double x, const double y)
{
    qDebug() << "appending point.";
    GPoint point(x,y);
    qDebug() << "poins is: " << point;
    this->gPointList.append(point);
    qDebug() << "list is: " << this->gPointList;
}

void ApplicationController::buildObject(const QString &name)
{
    qDebug() << "building object.";
    GObject *object = this->gPointList.build(name);
    qDebug() << "created object: " << *object;
    this->displayFile.append(*object);
    qDebug() << "list is now: " << this->displayFile;
}

void ApplicationController::refreshScene()
{
    qDebug() << "refreshing scene";
    this->scene.clear();
    qDebug() << "clearing scene";
    QSizeF vpSize = this->scene.sceneRect().size();
    auto vpTransformation = this->window->viewPortTransformation(vpSize);
    for(GObject object : this->displayFile.objects)
    {
        GObject transformedObject = object.transform(vpTransformation);
        QGraphicsItem *item = transformedObject.graphicsItem();
        this->scene.addItem(item);
        qDebug() << "Adding new object: " << item;
    }
    qDebug() << "the scene has: " << scene.items();
    qDebug() << "finished adding objects";
}

void ApplicationController::resetZoom()
{
    qDebug() << "reseting zoom";
    qDebug() << "old zoom factor: " << this->window->zoomFactor();
    this->window->clearZoomFactor();
    qDebug() << "new zoom factor: " << this->window->zoomFactor();
    emit this->zoomChanged(QString::number(this->window->zoomFactor() * 100) + "%");
}

void ApplicationController::lessZoom()
{
    qDebug() << "subtracting zoom";
    qDebug() << "old zoom factor: " << QString::number(this->window->zoomFactor());
    this->window->addZoomFactor(ZOOM_STEP);
    qDebug() << "new zoom factor: " << QString::number(this->window->zoomFactor());
    emit this->zoomChanged(QString::number(this->window->zoomFactor() * 100) + "%");
}

void ApplicationController::moreZoom()
{
    qDebug() << "adding zoom";
    qDebug() << "old zoom factor: " << QString::number(this->window->zoomFactor());
    this->window->subZoomFactor(ZOOM_STEP);
    qDebug() << "new zoom factor: " << QString::number(this->window->zoomFactor());
    emit this->zoomChanged(QString::number(this->window->zoomFactor() * 100) + "%");
}

void ApplicationController::centerPosition()
{
    qDebug() << "centering window";
    qDebug() << "old center: " << this->window->center();
    this->window->clearCenter();
    qDebug() << "new center: " << this->window->center();
    emit this->centerChanged(this->window->center().toString());
}

void ApplicationController::moveLeft()
{
    qDebug() << "moving window";
    qDebug() << "old center: " << this->window->center();
    this->window->moveCenter(GPoint(-1,0));
    qDebug() << "new center: " << this->window->center();
    emit this->centerChanged(this->window->center().toString());
}

 void ApplicationController::moveUp()
{
    qDebug() << "moving window";
    qDebug() << "old center: " << this->window->center();
    this->window->moveCenter(GPoint(0,-1));
    qDebug() << "new center: " << this->window->center();
    emit this->centerChanged(this->window->center().toString());
}

void ApplicationController::moveDown()
{
    qDebug() << "moving window";
    qDebug() << "old center: " << this->window->center();
    this->window->moveCenter(GPoint(0,1));
    qDebug() << "new center: " << this->window->center();
    emit this->centerChanged(this->window->center().toString());

}

void ApplicationController::moveRight()
{
    qDebug() << "moving window";
    qDebug() << "old center: " << this->window->center();
    this->window->moveCenter(GPoint(1,0));
    qDebug() << "new center: " << this->window->center();
    emit this->centerChanged(this->window->center().toString());
}

