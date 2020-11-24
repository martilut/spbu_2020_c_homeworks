#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Matrix {
    int columns;
    int strings;
    int** matrix;
};

Matrix* createMatrix(int columns, int strings)
{
    Matrix* newMatrix = (Matrix*)malloc(sizeof(Matrix));
    newMatrix->columns = columns;
    newMatrix->strings = strings;
    newMatrix->matrix = (int**)malloc(strings * sizeof(int*));
    for (int i = 0; i < strings; ++i) {
        newMatrix->matrix[i] = (int*)malloc(columns * sizeof(int));
        memset(newMatrix->matrix[i], (int)NULL, columns * sizeof(int));
    }
    return newMatrix;
}

void addValueToMatrix(Matrix* matrix, int i, int j, int value)
{
    matrix->matrix[i][j] = value;
}

Matrix* sumMatrix(Matrix* firstMatrix, Matrix* secondMatrix)
{
    if (firstMatrix->strings != secondMatrix->strings || firstMatrix->columns != secondMatrix->columns) {
        return NULL;
    }
    Matrix* resultMatrix = createMatrix(firstMatrix->columns, firstMatrix->strings);
    for (int i = 0; i < firstMatrix->strings; ++i) {
        for (int j = 0; j < firstMatrix->columns; ++j) {
            addValueToMatrix(resultMatrix, i, j, firstMatrix->matrix[i][j] + secondMatrix->matrix[i][j]);
        }
    }
    return resultMatrix;
}

Matrix* subMatrix(Matrix* firstMatrix, Matrix* secondMatrix)
{
    if (firstMatrix->strings != secondMatrix->strings || firstMatrix->columns != secondMatrix->columns) {
        return NULL;
    }
    Matrix* resultMatrix = createMatrix(firstMatrix->columns, firstMatrix->strings);
    for (int i = 0; i < firstMatrix->strings; ++i) {
        for (int j = 0; j < firstMatrix->columns; ++j) {
            addValueToMatrix(resultMatrix, i, j, firstMatrix->matrix[i][j] - secondMatrix->matrix[i][j]);
        }
    }
    return resultMatrix;
}

int getSumValues(Matrix* firstMatrix, Matrix* secondMatrix, int i, int j)
{
    int result = 0;
    for (int r = 0; r < firstMatrix->columns; ++r) {
        result += (firstMatrix->matrix[i][r] * secondMatrix->matrix[r][j]);
    }
    return result;
}

Matrix* multiplyMatrix(Matrix* firstMatrix, Matrix* secondMatrix)
{
    if (firstMatrix->columns != secondMatrix->strings) {
        return NULL;
    }
    Matrix* resultMatrix = createMatrix(firstMatrix->columns, firstMatrix->strings);
    for (int i = 0; i < firstMatrix->strings; ++i) {
        for (int j = 0; j < firstMatrix->columns; ++j) {
            int currentValue = getSumValues(firstMatrix, secondMatrix, i, j);
            addValueToMatrix(resultMatrix, i, j, currentValue);
        }
    }
    return resultMatrix;
}

void printMatrix(Matrix* matrix)
{
    for (int i = 0; i < matrix->strings; ++i) {
        for (int j = 0; j < matrix->columns; ++j) {
            printf("%d ", matrix->matrix[i][j]);
        }
        printf("\n");
    }
}

void removeMatrix(Matrix* matrix)
{
    for (int i = 0; i < matrix->strings; ++i) {
        free(matrix->matrix[i]);
    }
    free(matrix);
}