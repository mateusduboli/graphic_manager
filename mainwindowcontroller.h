#ifndef MAINWINDOWCONTROLLER_H
#define MAINWINDOWCONTROLLER_H

#include <QGraphicsScene>
#include "model/gobject.h"

class MainWindowController
{
public:
    MainWindowController() {}
    QGraphicsScene scene;
    QList<GObject> displayFile;
};

#endif // MAINWINDOWCONTROLLER_H
