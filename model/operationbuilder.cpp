#include "operationbuilder.h"

OperationBuilder::OperationBuilder()
{
    this->matrix = Matrix(IDENTITY);

    this->baseOperation = [&](Matrix matrix, GPoint point) -> GPoint {
        Vector vector = mult(point.vector(), matrix);
        return GPoint(vector);
    };
}

OperationBuilder &OperationBuilder::translate(const double x, const double y)
{
    this->matrix = mult(this->matrix, translationMatrix(x, y));
    return *this;
}

OperationBuilder &OperationBuilder::scale(const double scalar)
{
    this->matrix = mult(this->matrix, scalingMatrix(scalar));
    return *this;
}

OperationBuilder &OperationBuilder::rotate(const double degrees)
{
    this->matrix = mult(this->matrix, rotatingMatrix(degrees));
    return *this;
}

Operation OperationBuilder::build(const GPoint reference)
{
    double x = reference.x();
    double y = reference.y();
    this->matrix = mult(translationMatrix(-x, -y), this->matrix);
    this->matrix = mult(this->matrix, translationMatrix(x, y));
    return std::bind1st(this->baseOperation, this->matrix);
}
