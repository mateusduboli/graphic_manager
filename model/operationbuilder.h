#ifndef OPERATIONBUIDLER_H
#define OPERATIONBUIDLER_H

#include <QVector>
#include <functional>

#include "model/matrixoperations.h"
#include "model/gpoint.h"
#include "model/types.h"

using namespace MatrixOperations;

class OperationBuilder
{
public:
    OperationBuilder();
    OperationBuilder& translate(const double x, const double y);
    OperationBuilder& translate(const GPoint);
    OperationBuilder& scale(const double scalar);
    OperationBuilder& rotate(const double degrees);
    Operation build(const GPoint reference = GPoint(0,0));
private:
    Matrix matrix;
    std::function<GPoint (const Matrix, const GPoint)> baseOperation;
};

#endif // OPERATIONBUIDLER_H
