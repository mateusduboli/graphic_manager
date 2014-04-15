#ifndef OPERATIONBUIDLER_H
#define OPERATIONBUIDLER_H

#include <QVector>
#include <functional>

#include "gpoint.h"

typedef std::function<GPoint (GPoint)> Operation;

class OperationBuilder
{
public:
    OperationBuilder();
    OperationBuilder* translate(const double x, const double y);
    Operation build();
private:
    double* applyTransformation(const double* transformation);
    double* transformationMatrix;
};

#endif // OPERATIONBUIDLER_H
