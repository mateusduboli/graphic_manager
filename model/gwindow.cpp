#include "gwindow.h"

GWindow::GWindow(const GPoint &center, const QSize &size):
    _height(size.height()),
    _width(size.width()),
    _zoomFactor(1),
    _center(center)
{
    this->vpTransformation = [this] (QSizeF viewPortSize, GPoint point) -> GPoint {
        double x = ((point.x() - this->min().x())/(this->width())) * viewPortSize.width();
        qDebug() << "x = ((" << point.x() << "-" << this->min().x() << ")/(" << this->width() << "))*" << viewPortSize.width();
        double y = ((1 - point.y() - this->min().y())/(this->height()))*viewPortSize.height();
        qDebug() << "y = (( 1 -" << point.y() << "-" << this->min().y() << ")/(" << this->height() << "))*" << viewPortSize.height();
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

GPoint GWindow::max() const
{
    double x = this->center().x() + this->width()/2;
    double y = this->center().y() + this->height()/2;
    return GPoint(x, y);
}

GPoint GWindow::min() const
{
    double x = this->center().x() - this->width()/2;
    double y = this->center().y() - this->height()/2;
    return GPoint(x, y);
}

GPoint GWindow::center() const
{
    return this->_center;
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

void GWindow::subZoomFactor(const double &zoomFactor)
{
    this->_zoomFactor -= zoomFactor;
}

void GWindow::addZoomFactor(const double &zoomFactor)
{
    this->_zoomFactor += zoomFactor;
}

double GWindow::zoomFactor() const
{
    return this->_zoomFactor;
}

std::function<GPoint (GPoint)> GWindow::viewPortTransformation(const QSizeF viewPortSize)
{
    qDebug() <<  "The view port size is: " << viewPortSize;
    return std::bind1st(this->vpTransformation, viewPortSize);
}
