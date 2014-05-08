#include "operationbuilder.h"

OperationBuilder::OperationBuilder()
{
    this->matrix = Matrix{{
                   {{1, 0, 0}},
                   {{0, 1, 0}},
                   {{0, 0, 1}}
                  }};
    this->baseOperation = [&](Matrix matrix, GPoint point) -> GPoint {
        Vector pointVector = MatrixOperations::mult(point.vector(), matrix);
        GPoint newPoint(pointVector);
        return newPoint;
    };
}

OperationBuilder &OperationBuilder::translate(const double x, const double y)
{
    const Matrix translationMatrix = {{
        {{1, 0, 0}},
        {{0, 1, 0}},
        {{x, y, 1}}
    }};
    this->matrix = MatrixOperations::mult(this->matrix, translationMatrix);
    return *this;
}

Operation OperationBuilder::build()
{
    return std::bind1st(this->baseOperation, this->matrix);
}
