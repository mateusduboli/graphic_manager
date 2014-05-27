#include "gwindow.h"

GWindow::GWindow(QObject* parent, const GPoint &center, const QSizeF &size):
    QObject(parent),
    _height(size.height()),
    _width(size.width()),
    _zoomFactor(1),
    _angle(0),
    _center(center)
{
    this->vpTransformation = [] (GPoint min, QSizeF windowSize, QSize viewPortSize, GPoint point) -> GPoint {
        double x = ((point.x() - min.x())/windowSize.width())*viewPortSize.width();
        double y = (1 - (point.y() - min.y())/windowSize.height())*viewPortSize.height();
        return GPoint(x, y);
    };
    this->ppcTransformation = [] (double angle, GPoint windowCenter, GPoint point) -> GPoint {
        OperationBuilder builder;
        builder.translate(-windowCenter);
        builder.rotate(-angle);
        Operation op = builder.build();
        return op(point);
    };
}

double GWindow::angle() const
{
    return this->_angle;
}

double GWindow::height() const
{
    return this->_height * this->_zoomFactor;
}

double GWindow::width() const
{
    return this->_width * this->_zoomFactor;
}

const GPoint GWindow::max() const
{
    double x = this->center().x() + this->width()/2;
    double y = this->center().y() + this->height()/2;
    return GPoint(x, y);
}

const GPoint GWindow::min() const
{
    double x = this->center().x() - this->width()/2;
    double y = this->center().y() - this->height()/2;
    return GPoint(x, y);
}

const GPoint GWindow::center() const
{
    return this->_center;
}

const QSizeF GWindow::size() const
{
    return QSizeF(this->width(), this->height());
}

void GWindow::updateFramebuffer(QVector<GObject> *displayFile)
{
    this->_framebuffer.clear();
    Operation op = bind(this->ppcTransformation, this->_angle, this->center(), placeholders::_1);
    for(GObject object : *displayFile)
    {
        this->_framebuffer.append(object.transform(op));
    }
    emit this->framebufferChanged();
}

void GWindow::clearZoomFactor()
{
    this->_zoomFactor = 1;
}

void GWindow::clearCenter()
{
    this->_center = GPoint(0,0);
}

void GWindow::rotate(const double degrees)
{
    this->_angle += degrees;
}

void GWindow::move(const GPoint movement)
{
    OperationBuilder builder;
    GPoint oa = builder.rotate(this->_angle).build()(movement);
    this->_center = this->_center + oa;
}

void GWindow::addZoomFactor(const double factor)
{
    this->_zoomFactor += factor;
}

double GWindow::zoomFactor() const
{
    return this->_zoomFactor;
}

QVector<GObject> GWindow::framebuffer() const
{
    return this->_framebuffer;
}

Operation GWindow::viewPortTransformation(const QSize viewPortSize)
{
    qDebug() <<  "[GWindow] The view port size is: " << viewPortSize;
    return bind(this->vpTransformation, this->min(), this->size(), viewPortSize, placeholders::_1);
}
