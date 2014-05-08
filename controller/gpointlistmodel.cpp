#include "gpointlistmodel.h"

GPointListModel::GPointListModel(QObject *parent) :
    QAbstractListModel(parent)
{
}

int GPointListModel::rowCount(const QModelIndex &parent) const
{
    if(parent.isValid())
        return 0;
    else
        return this->points.size();
}

QVariant GPointListModel::data(const QModelIndex &index, int role) const
{
    if(role == Qt::DisplayRole)
        return QVariant(this->points.at(index.row()).toString());
    else
        return QVariant();
}

void GPointListModel::append(const GPoint &point)
{
    int newIndex = this->points.size();
    const QModelIndex parent = this->index(newIndex - 1);
    this->beginInsertRows(parent, newIndex, newIndex);
    this->points.append(GPoint(point));
    this->endInsertRows();
}

GObject *GPointListModel::build(const QString &name)
{
    GObject *gObject = new GObject(name, this->points);
    this->points.clear();
    return gObject;
}

GPointListModel::~GPointListModel()
{
}

QDebug operator<<(QDebug b, const GPointListModel &model)
{
    return b << model.points;
}
