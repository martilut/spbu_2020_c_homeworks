#ifndef SPBU_2020_C_HOMEWORKS_DOUBLEARRAY_H
#define SPBU_2020_C_HOMEWORKS_DOUBLEARRAY_H

typedef struct DoubleArray DoubleArray;
DoubleArray* createDoubleArray(int rows, int columns);
void addToDoubleArray(DoubleArray* doubleArray, int i, int j, int value);
void printPoints(DoubleArray* doubleArray);
void printDoubleArray(DoubleArray* doubleArray);
void removeDoubleArray(DoubleArray* doubleArray);

#endif // SPBU_2020_C_HOMEWORKS_DOUBLEARRAY_H
