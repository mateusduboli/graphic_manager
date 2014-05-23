#include "gviewport.h"

GViewport::GViewport(QWidget *parent) :
    QWidget(parent)
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
}

void GViewport::setWindow(GWindow* window)
{
    this->window = window;
    QObject::connect(window, SIGNAL(framebufferChanged()), this, SLOT(update()));
}

void GViewport::paintEvent(QPaintEvent*/*event*/)
{
    qDebug() << "[GViewport] paintevent";
    QPainter painter(this);
    Operation op = this->window->viewPortTransformation(this->size());
    for(GObject object : this->window->framebuffer())
    {
        painter.drawPolygon(object.transform(op).toQPolygon());
    }
}
