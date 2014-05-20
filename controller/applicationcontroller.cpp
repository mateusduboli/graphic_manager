#include "controller/applicationcontroller.h"

ApplicationController::ApplicationController(QObject *parent):
    QObject(parent)
{
    qDebug() << "[ApplicationController] constructor";

    qDebug() << "[ApplicationController] connecting";
    connect(&this->displayFile, &GObjectListModel::rowsInserted, this, &ApplicationController::refreshScene);
    connect(this, &ApplicationController::zoomChanged, this, &ApplicationController::refreshScene);
    connect(this, &ApplicationController::centerChanged, this, &ApplicationController::refreshScene);
    connect(this, &ApplicationController::operationBuildt, this, &ApplicationController::refreshScene);
    qDebug() << "[ApplicationController] finished constructor";
}

void ApplicationController::setWindowSize(const GPoint &center, const QSize &size)
{
    qDebug() << "[ApplicationController] setting window size to: " << size;
    this->window = new GWindow(center, size);
    emit this->zoomChanged(QString::number(this->window->zoomFactor() * 100) + "%");
    emit this->centerChanged(this->window->center().toString());
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

void ApplicationController::refreshScene()
{
    qDebug() << "[ApplicationController] refreshing scene";
    this->scene.clear();
    qDebug() << "[ApplicationController] clearing scene";
    QSizeF vpSize = this->scene.sceneRect().size();
    auto vpTransformation = this->window->viewPortTransformation(vpSize);
    for(GObject object : this->displayFile.objects)
    {
        GObject transformedObject = object.transform(vpTransformation);
        QGraphicsItem *item = transformedObject.toGraphicsItem();
        this->scene.addItem(item);
        qDebug() << "[ApplicationController] Adding new object: " << item;
    }
    qDebug() << "[ApplicationController] the scene has: " << scene.items();
    qDebug() << "[ApplicationController] finished adding objects";
}

void ApplicationController::resetZoom()
{
    qDebug() << "[ApplicationController] reseting zoom";
    qDebug() << "[ApplicationController] old zoom factor: " << this->window->zoomFactor();
    this->window->clearZoomFactor();
    qDebug() << "[ApplicationController] new zoom factor: " << this->window->zoomFactor();
    emit this->zoomChanged(QString::number(this->window->zoomFactor() * 100) + "%");
}

void ApplicationController::lessZoom()
{
    qDebug() << "[ApplicationController] subtracting zoom";
    qDebug() << "[ApplicationController] old zoom factor: " << QString::number(this->window->zoomFactor());
    this->window->addZoomFactor(ZOOM_STEP);
    qDebug() << "[ApplicationController] new zoom factor: " << QString::number(this->window->zoomFactor());
    emit this->zoomChanged(QString::number(this->window->zoomFactor() * 100) + "%");
}

void ApplicationController::moreZoom()
{
    qDebug() << "[ApplicationController] adding zoom";
    qDebug() << "[ApplicationController] old zoom factor: " << QString::number(this->window->zoomFactor());
    this->window->subZoomFactor(ZOOM_STEP);
    qDebug() << "[ApplicationController] new zoom factor: " << QString::number(this->window->zoomFactor());
    emit this->zoomChanged(QString::number(this->window->zoomFactor() * 100) + "%");
}

void ApplicationController::centerPosition()
{
    qDebug() << "[ApplicationController] centering window";
    qDebug() << "[ApplicationController] old center: " << this->window->center();
    this->window->clearCenter();
    qDebug() << "[ApplicationController] new center: " << this->window->center();
    emit this->centerChanged(this->window->center().toString());
}

void ApplicationController::moveLeft()
{
    qDebug() << "[ApplicationController] moving window";
    qDebug() << "[ApplicationController] old center: " << this->window->center();
    this->window->moveCenter(GPoint(-1,0));
    qDebug() << "[ApplicationController] new center: " << this->window->center();
    emit this->centerChanged(this->window->center().toString());
}

 void ApplicationController::moveUp()
{
    qDebug() << "[ApplicationController] moving window";
    qDebug() << "[ApplicationController] old center: " << this->window->center();
    this->window->moveCenter(GPoint(0,-1));
    qDebug() << "[ApplicationController] new center: " << this->window->center();
    emit this->centerChanged(this->window->center().toString());
}

void ApplicationController::moveDown()
{
    qDebug() << "[ApplicationController] moving window";
    qDebug() << "[ApplicationController] old center: " << this->window->center();
    this->window->moveCenter(GPoint(0,1));
    qDebug() << "[ApplicationController] new center: " << this->window->center();
    emit this->centerChanged(this->window->center().toString());

}

void ApplicationController::moveRight()
{
    qDebug() << "[ApplicationController] moving window";
    qDebug() << "[ApplicationController] old center: " << this->window->center();
    this->window->moveCenter(GPoint(1,0));
    qDebug() << "[ApplicationController] new center: " << this->window->center();
    emit this->centerChanged(this->window->center().toString());
}

