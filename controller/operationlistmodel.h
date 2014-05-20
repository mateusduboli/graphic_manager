#ifndef OPERATIONLISTMODEL_H
#define OPERATIONLISTMODEL_H

#include <QAbstractListModel>

#include "model/types.h"
#include "model/operationbuilder.h"

class OperationListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit OperationListModel(QObject *parent = 0);
    virtual int rowCount(const QModelIndex &parent) const;
    virtual QVariant data(const QModelIndex &index, int role) const;
    void append(const QString operation);
    Operation build(const GPoint center);
    ~OperationListModel();
    friend QDebug operator<<(QDebug b, const OperationListModel &model);
    void appendOperationTranslate(const double x, const double y);
    void appendOperationScale(const double factor);
    void appendOperationRotate(const double degrees);
    void clear();
private:
    QVector<QString> operations;
    OperationBuilder builder;
    const QString OP_TRANSLATE = QString("Traslate : { X : %1, Y : %2 }");
    const QString OP_ROTATE = QString("Rotate : %1 ");
    const QString OP_SCALE = QString("Scale : %1 ");
};

#endif // OPERATIONLISTMODEL_H
