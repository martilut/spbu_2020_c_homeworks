#include <stdio.h>

#include <stdlib.h>

#include "arrayOperations.h"

void swapElements(int array[], int a, int b)
{
    int temp = array[a];
    array[a] = array[b - a - 1];
    array[b - a - 1] = temp;
};

void scanArray(int array[], int n)
{
    for (int i = 0; i < n; ++i) {
        scanf("%d", &array[i]);
    }
}

void printArray(int array[], int n)
{
    for (int i = 0; i < n; ++i) {
        printf("%d ", array[i]);
    }
};