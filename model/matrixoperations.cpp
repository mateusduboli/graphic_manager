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
}