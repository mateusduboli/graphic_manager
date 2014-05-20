#include "operationlistmodel.h"

OperationListModel::OperationListModel(QObject *parent) :
    QAbstractListModel(parent)
{
}

int OperationListModel::rowCount(const QModelIndex &parent) const
{
    if(parent.isValid())
        return 0;
    else
        return this->operations.size();
}

QVariant OperationListModel::data(const QModelIndex &index, int role) const
{
    if(role == Qt::DisplayRole)
        return QVariant(this->operations.at(index.row()));
    else
        return QVariant();
}

Operation OperationListModel::build(const GPoint center)
{
    qDebug() << "[OperationBuilder] build";
    return this->builder.build(center);
}

OperationListModel::~OperationListModel()
{ }

void OperationListModel::appendOperationTranslate(const double x, const double y)
{
    int newIndex = this->operations.size();
    const QModelIndex parent = this->index(newIndex - 1);
    this->beginInsertRows(parent, newIndex, newIndex);
    this->operations.append(OP_TRANSLATE.arg(x).arg(y));
    this->builder.translate(x, y);
    this->endInsertRows();
}

void OperationListModel::appendOperationScale(const double factor)
{
    int newIndex = this->operations.size();
    const QModelIndex parent = this->index(newIndex - 1);
    this->beginInsertRows(parent, newIndex, newIndex);
    this->operations.append(OP_SCALE.arg(factor));
    this->builder.scale(factor);
    this->endInsertRows();
}

void OperationListModel::appendOperationRotate(const double degrees)
{
    int newIndex = this->operations.size();
    const QModelIndex parent = this->index(newIndex - 1);
    this->beginInsertRows(parent, newIndex, newIndex);
    this->operations.append(OP_ROTATE.arg(degrees));
    this->builder.rotate(degrees);
    this->endInsertRows();

}

void OperationListModel::clear()
{
    this->operations.clear();
    this->builder = OperationBuilder();
}

