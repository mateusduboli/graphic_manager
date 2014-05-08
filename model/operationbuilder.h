#ifndef OPERATIONBUIDLER_H
#define OPERATIONBUIDLER_H

#include <QVector>
#include <functional>

#include "model/matrixoperations.h"
#include "model/gpoint.h"

typedef std::function<GPoint (GPoint)> Operation;

class OperationBuilder
{
public:
    OperationBuilder();
    OperationBuilder& translate(const double x, const double y);
    Operation build();
private:
    Matrix matrix;
    std::function<GPoint (const Matrix, GPoint)> baseOperation;
};

#endif // OPERATIONBUIDLER_H
