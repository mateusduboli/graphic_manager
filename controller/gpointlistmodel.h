#ifndef GPOINTLISTMODEL_H
#define GPOINTLISTMODEL_H

#include <QAbstractListModel>
#include <QVector>
#include <QDebug>

#include "model/gpoint.h"
#include "model/gobject.h"

class GPointListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit GPointListModel(QObject *parent = 0);
    virtual int rowCount(const QModelIndex &parent) const;
    virtual QVariant data(const QModelIndex &index, int role) const;
    void append(const GPoint &point);
    GObject *build(const QString &name);
    ~GPointListModel();
    friend QDebug operator<<(QDebug b, const GPointListModel &model);
signals:

public slots:

private:
    QVector<GPoint> points;
};

#endif // GPOINTLISTMODEL_H
