#include "arrayOperations.h"

int swapElements(int *array, int a, int b)
{
    int temp;
    temp = array[a];
    array[a] = array[b - a - 1];
    array[b - a - 1] = temp;
};
