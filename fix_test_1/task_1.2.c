#include "../library/dataStructures/Matrix/matrix.h"
#include <stdio.h>

void fillMatrix(Matrix* matrix, int strings, int columns)
{
    for (int i = 0; i < strings; ++i) {
        for (int j = 0; j < columns; ++j) {
            int value = 0;
            scanf("%d", &value);
            addValueToMatrix(matrix, i, j, value);
        }
    }
}

int main()
{
    int n = 0;
    int m = 0;
    int x = 0;
    int y = 0;

    printf("Enter the amount of strings and columns int the first matrix:\n");
    scanf("%d %d", &n, &m);
    printf("Enter the first matrix:\n");
    Matrix* firstMatrix = createMatrix(n, m);
    fillMatrix(firstMatrix, n, m);

    printf("Enter the amount of strings and columns int the second matrix:\n");
    scanf("%d %d", &x, &y);
    printf("Enter the second matrix:\n");
    Matrix* secondMatrix = createMatrix(x, y);
    fillMatrix(secondMatrix, x, y);

    Matrix* sumResult = sumMatrix(firstMatrix, secondMatrix);
    if (sumResult == NULL) {
        printf("Can not be summarized\n");
    } else {
        printf("Sum is\n");
        printMatrix(sumResult);
        removeMatrix(sumResult);
    }

    Matrix* subResult = subMatrix(firstMatrix, secondMatrix);
    if (sumResult == NULL) {
        printf("Can not be substracted\n");
    } else {
        printf("Diff is\n");
        printMatrix(subResult);
        removeMatrix(subResult);
    }

    Matrix* multResult = multiplyMatrix(firstMatrix, secondMatrix);
    if (multResult == NULL) {
        printf("Can not be multipiled\n");
    } else {
        printf("Composition is\n");
        printMatrix(multResult);
        removeMatrix(multResult);
    }

    removeMatrix(firstMatrix);
    removeMatrix(secondMatrix);

    return 0;
}
