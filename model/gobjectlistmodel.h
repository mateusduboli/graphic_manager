#ifndef GOBJECTLISTMODEL_H
#define GOBJECTLISTMODEL_H

#include <QAbstractListModel>
#include "gobject.h"

class GObjectListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit GObjectListModel(QObject *parent = 0);
    virtual int rowCount(const QModelIndex &parent) const;
    virtual QVariant data(const QModelIndex &index, int role) const;
    void append(const GObject &point);
    ~GObjectListModel();
    QVector<GObject> objects;
    friend QDebug operator<<(QDebug b, const GObjectListModel &model);
signals:

public slots:

};

#endif // GOBJECTLISTMODEL_H
