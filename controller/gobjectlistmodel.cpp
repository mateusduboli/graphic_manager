#include "gobjectlistmodel.h"

GObjectListModel::GObjectListModel(QObject *parent) :
    QAbstractListModel(parent)
{
}

int GObjectListModel::rowCount(const QModelIndex &parent) const
{
    if(parent.isValid())
        return 0;
    else
        return this->objects.size();
}

QVariant GObjectListModel::data(const QModelIndex &index, int role) const
{
    if(role == Qt::DisplayRole)
        return QVariant(this->objects.at(index.row()).name());
    else
        return QVariant();
}

void GObjectListModel::append(const GObject &object)
{
    int newIndex = this->objects.size();
    const QModelIndex parent = this->index(newIndex - 1);
    this->beginInsertRows(parent, newIndex, newIndex);
    this->objects.append(GObject(object));
    this->endInsertRows();
}

QDebug operator<<(QDebug b, const GObjectListModel &model)
{
    return b << model.objects;
}

GObjectListModel::~GObjectListModel()
{
}
