#include "../library/dataStructures/DoubleArray/doubleArray.h"
#include <stdio.h>

int main()
{
    int rows = 0;
    int columns = 0;
    printf("How many rows and columns does your array have?\n");
    scanf("%d %d", &rows, &columns);
    DoubleArray* doubleArray = createDoubleArray(rows, columns);
    printf("Enter your array:\n");
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            int value = 0;
            scanf("%d", &value);
            addToDoubleArray(doubleArray, i, j, value);
        }
    }

    printDoubleArray(doubleArray);
    printf("\n");
    printPoints(doubleArray);

    removeDoubleArray(doubleArray);
    return 0;
}
