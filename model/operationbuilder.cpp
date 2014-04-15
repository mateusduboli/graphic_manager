#include "operationbuilder.h"

OperationBuilder::OperationBuilder()
{
    this->transformationMatrix = new double[9]{1, 0, 0, 0, 1, 0, 0, 0, 1};
}

OperationBuilder *OperationBuilder::translate(const double x, const double y)
{
    const double translationMatrix[9] = {1, 0, 0, 0, 1, 0, x, y, 1};
    this->transformationMatrix = applyTransformation(translationMatrix);
    return this;
}

Operation OperationBuilder::build()
{
    return [&](GPoint point) -> GPoint { return point; };
}

double* OperationBuilder::applyTransformation(const double *transformation)
{
    double* matrix = new double[9];
    double* op1 = this->transformationMatrix;
    double* op2 = transformation;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++) {
            int index = i * 3 + j;
            this->matrix[index] =
                    op1[0 + j] * op2[i * 3 + 0] +
                    op1[3 + j] * op2[i * 3 + 1] +
                    op1[6 + j] * op2[i * 3 + 2];
        }
    return matrix;
}
