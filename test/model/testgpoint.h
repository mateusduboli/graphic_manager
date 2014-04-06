#ifndef TESTGPOINT_H
#define TESTGPOINT_H

#include <QObject>
#include <QTest>

#include "model/gpoint.h"

class TestGPoint : public QObject
{
    Q_OBJECT
public:
    explicit TestGPoint(QObject *parent = 0);

private Q_SLOTS:
    void testConstructor();
    void testConstructorWithParameters();
    void testMatrix();
    void testToQPointF();
};

#endif // TESTGPOINT_H
