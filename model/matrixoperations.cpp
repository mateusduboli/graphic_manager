#include "model/matrixoperations.h"

namespace MatrixOperations {
Matrix mult(const Matrix op1, const Matrix op2)
{
    Matrix result;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++) {
            result[i][j] = 0;
            for(int k = 0; k < 3; k++)
                result[i][j] += op1[i][k] * op2[k][j];
        }
    return result;
}

Vector mult(const Vector op1, const Matrix op2)
{
    Vector result;
    for(int i = 0; i < 3; i++) {
        result[i] = 0;
        for(int k = 0; k < 3; k++)
            result[i] += op1[k] * op2[k][i];
    }
    return result;
}

Matrix scalingMatrix(const double scalar)
{
    return Matrix {{
            {{scalar, 0, 0}},
            {{0, scalar, 0}},
            {{0, 0, 1}}
        }};
}

Matrix translationMatrix(const double x, const double y)
{
    return Matrix{{
            {{1, 0, 0}},
            {{0, 1, 0}},
            {{x, y, 1}}
        }};
}

Matrix rotatingMatrix(const double degrees)
{
    const double rad = (M_PI/180)*degrees;
    return Matrix{{
            {{cos(rad), -sin(rad), 0}},
            {{sin(rad), cos(rad), 0}},
            {{0, 0, 1}}
        }};
}


}