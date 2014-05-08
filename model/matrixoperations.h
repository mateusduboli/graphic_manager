#ifndef MATRIXOPERATIONS_H
#define MATRIXOPERATIONS_H

#include<array>

#include "model/types.h"

namespace MatrixOperations {
     Vector mult(const Vector op1, const Matrix op2);
     Matrix mult(const Matrix op1, const Matrix op2);
}

#endif // MATRIXOPERATIONS_H
