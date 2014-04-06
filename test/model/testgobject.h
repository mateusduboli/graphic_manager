#ifndef TESTGOBJECT_H
#define TESTGOBJECT_H

#include <QObject>
#include <QTest>

#include "model/gobject.h"

class TestGObject : public QObject
{
    Q_OBJECT
public:
    explicit TestGObject(QObject *parent = 0);

signals:

private Q_SLOTS:
    void testGraphicsItemEmpty();

};

#endif // TESTGOBJECT_H
