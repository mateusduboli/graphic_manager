#ifndef TEST_GPOINTLISTMODEL_H
#define TEST_GPOINTLISTMODEL_H

#include <QObject>
#include <QTest>
#include "controller/gpointlistmodel.h"

class TestGPointListModel : public QObject
{
    Q_OBJECT
public:
    explicit TestGPointListModel(QObject *parent = 0):
        QObject(parent)
    {}

private Q_SLOTS:
    void testRowCountWithEmptyModel()
    {
        GPointListModel model;
        QCOMPARE(model.rowCount(QModelIndex()), 0);
    }
    void testRowCountWith3Elements()
    {
        GPointListModel model;
        model.append(GPoint());
        model.append(GPoint());
        model.append(GPoint());
        QCOMPARE(model.rowCount(QModelIndex()), 3);
    }
    void testData()
    {
        GPointListModel model;
        model.append(GPoint(0,0));
        model.append(GPoint(1,1));
        model.append(GPoint(2,2));
        QString expected = GPoint(1,1).toString();
        QModelIndex index = model.index(1);
        QString actual = model.data(index, Qt::DisplayRole).toString();
        QCOMPARE(actual, expected);
    }
};

#endif // TEST_GPOINTLISTMODEL_H
