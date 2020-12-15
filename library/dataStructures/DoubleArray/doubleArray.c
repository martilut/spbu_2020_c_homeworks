#include "doubleArray.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct DoubleArray {
    int rows;
    int columns;
    int** dArray;
};

DoubleArray* createDoubleArray(int rows, int columns)
{
    DoubleArray* doubleArray = (DoubleArray*)malloc(sizeof(DoubleArray));
    doubleArray->rows = rows;
    doubleArray->columns = columns;
    doubleArray->dArray = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; ++i) {
        doubleArray->dArray[i] = (int*)malloc(columns * sizeof(int));
        memset(doubleArray->dArray[i], 0, columns * sizeof(int));
    }
    return doubleArray;
}

void addToDoubleArray(DoubleArray* doubleArray, int i, int j, int value)
{
    doubleArray->dArray[i][j] = value;
}

int getMinInRow(DoubleArray* doubleArray, int row)
{
    int minimum = doubleArray->dArray[row][0];
    for (int i = 0; i < doubleArray->columns; ++i) {
        if (doubleArray->dArray[row][i] < minimum) {
            minimum = doubleArray->dArray[row][i];
        }
    }
    return minimum;
}

int getMaxInColumn(DoubleArray* doubleArray, int column)
{
    int maximum = doubleArray->dArray[0][column];
    for (int i = 0; i < doubleArray->rows; ++i) {
        if (doubleArray->dArray[i][column] > maximum) {
            maximum = doubleArray->dArray[i][column];
        }
    }
    return maximum;
}

void printPoints(DoubleArray* doubleArray)
{
    int* points = (int*)malloc(sizeof(int));
    int index = 0;
    for (int i = 0; i < doubleArray->rows; ++i) {
        for (int j = 0; j < doubleArray->columns; ++j) {
            int currentValue = doubleArray->dArray[i][j];
            if ((getMinInRow(doubleArray, i) == currentValue) && (getMaxInColumn(doubleArray, j) == currentValue)) {
                points[index] = currentValue;
                ++index;
                points = realloc(points, (index + 1) * sizeof(int));
            }
        }
    }
    for (int i = 0; i < index; ++i) {
        printf("%d ", points[i]);
    }
    free(points);
}

void printDoubleArray(DoubleArray* doubleArray)
{
    for (int i = 0; i < doubleArray->rows; ++i) {
        for (int j = 0; j < doubleArray->columns; ++j) {
            printf("%d ", doubleArray->dArray[i][j]);
        }
        printf("\n");
    }
}

void removeDoubleArray(DoubleArray* doubleArray)
{
    for (int i = 0; i < doubleArray->rows; ++i) {
        free(doubleArray->dArray[i]);
    }
    free(doubleArray->dArray);
    free(doubleArray);
}