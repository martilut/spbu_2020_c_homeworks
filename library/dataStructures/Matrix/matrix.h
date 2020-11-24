#ifndef SPBU_2020_C_HOMEWORKS_MATRIX_H
#define SPBU_2020_C_HOMEWORKS_MATRIX_H

typedef struct Matrix Matrix;

Matrix* createMatrix(int columns, int strings);
void addValueToMatrix(Matrix* matrix, int i, int j, int value);
Matrix* sumMatrix(Matrix* firstMatrix, Matrix* secondMatrix);
Matrix* subMatrix(Matrix* firstMatrix, Matrix* secondMatrix);
Matrix* multiplyMatrix(Matrix* firstMatrix, Matrix* secondMatrix);
void removeMatrix(Matrix* matrix);

#endif // SPBU_2020_C_HOMEWORKS_MATRIX_H
