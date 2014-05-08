#ifndef TEST_MATRIXOPERATIONS_H
#define TEST_MATRIXOPERATIONS_H

#include <QObject>
#include <QTest>

#include "model/matrixoperations.h"

class TestMatrixOperations : public QObject
{
    Q_OBJECT
public:
    explicit TestMatrixOperations(QObject *parent = 0)
        : QObject(parent)
    {}

private Q_SLOTS:
    void testMultiply()
    {
        Matrix matrix{{
                {{0, 0, 0}},
                {{0, 0, 0}},
                {{0, 0, 0}}
            }};
        Matrix actual = MatrixOperations::mult(matrix, matrix);
        Matrix expected = matrix;
        QCOMPARE(actual, expected);
    }

    void testVectorMatrix()
    {
        Vector vector{{1, 2, 3}};

        Matrix matrix{{
                {{1, 2, 3}},
                {{1, 2, 3}},
                {{1, 2, 3}}
            }};

        Vector actual = MatrixOperations::mult(vector, matrix);
        Vector expected = {{6, 12, 18}};
        QCOMPARE(actual, expected);
    }
    void testMatrixMatrix()
    {
        Matrix matrix1{{
                {{1, 2, 3}},
                {{1, 2, 3}},
                {{1, 2, 3}}
            }};

        Matrix matrix2{{
                {{3, 2, 1}},
                {{3, 2, 1}},
                {{3, 2, 1}}
            }};


        Matrix actual = MatrixOperations::mult(matrix1, matrix2);
        Matrix expected = {{
                               {{18, 12, 6}},
                               {{18, 12, 6}},
                               {{18, 12, 6}}
                           }};
        QCOMPARE(actual, expected);
    }
};

#endif // TEST_MATRIXOPERATIONS_H
