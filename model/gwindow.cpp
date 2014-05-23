#include "gwindow.h"

GWindow::GWindow(QObject* parent, const GPoint &center, const QSizeF &size):
    QObject(parent),
    _height(size.height()),
    _width(size.width()),
    _zoomFactor(1),
    _center(center)
{
    this->vpTransformation = [this] (QSize viewPortSize, GPoint point) -> GPoint {
        double x = ((point.x() - this->min().x())/(this->width())) * viewPortSize.width();
        double y = (1 - (point.y() - this->min().y())/(this->height()))*viewPortSize.height();
        return GPoint(x, y);
    };
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

void GWindow::updateFramebuffer(QVector<GObject> *displayFile)
{
    this->_framebuffer.clear();
    for(GObject object : *displayFile)
    {
        this->_framebuffer.append(object);
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

void GWindow::moveCenter(const GPoint &movement)
{
    this->_center = this->_center + movement;
}

void GWindow::addZoomFactor(const double &zoomFactor)
{
    this->_zoomFactor += zoomFactor;
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
    return std::bind1st(this->vpTransformation, viewPortSize);
}
