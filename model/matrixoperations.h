#ifndef MATRIXOPERATIONS_H
#define MATRIXOPERATIONS_H

#include<array>
#include<cmath>

#include "model/types.h"

namespace MatrixOperations {
     Vector mult(const Vector op1, const Matrix op2);
     Matrix mult(const Matrix op1, const Matrix op2);
     const Matrix IDENTITY {{
             {{1, 0, 0}},
             {{0, 1, 0}},
             {{0, 0, 1}}
                            }};
     Matrix translationMatrix(const double x, const double y);
     Matrix scalingMatrix(const double scalar);
     Matrix rotatingMatrix(const double degrees);
}

#endif // MATRIXOPERATIONS_H
