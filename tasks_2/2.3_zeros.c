#include <stdio.h>

#include "../library/commonUtils/arrayOperations.h"

void moveZeros(int array[], int n)
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

    int array[n];
    printf("Enter your array:\n");

    for (int i = 0; i < n; ++i) {
        scanf("%d", &array[i]);
    }

    moveZeros(array, n);
    printArray(array, n);

    return 0;
}