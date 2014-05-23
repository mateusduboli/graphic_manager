#ifndef GVIEWPORT_H
#define GVIEWPORT_H

#include <QWidget>
#include <QPainter>

#include "model/types.h"
#include "model/gobject.h"
#include "model/gwindow.h"

class GViewport : public QWidget
{
    Q_OBJECT
public:
    explicit GViewport(QWidget *parent = 0);
    void setWindow(GWindow* window);
signals:

public slots:

protected:
    void paintEvent(QPaintEvent *event);
    GWindow* window;
};

#endif // GVIEWPORT_H
