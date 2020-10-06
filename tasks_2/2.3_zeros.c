#include <malloc.h>

#include <stdio.h>

#include <string.h>

#include "../library/commonUtils/arrayOperations.h"

void moveZeros(int *array, int n)
{
    int zeroCounter = 0;
    for (int i = 0; i < n; ++i) {
        if (!array[i])
            zeroCounter++;
        else
            array[i - zeroCounter] = array[i];
    }
    for (int i = (n - zeroCounter); i < n; ++i) {
        array[i] = 0;
    }
}

int main()
{
    int n = 0;

    printf("Enter n:\n");
    scanf("%d", &n);

    int *array = (int *)malloc(n * sizeof(int));
    memset(array, 0, n);

    printf("Enter your array:\n");

    scanArray(array, n);
    moveZeros(array, n);
    printArray(array, n);

    free(array);
    return 0;
}