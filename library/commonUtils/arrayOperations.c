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

char* scanString()
{
    int size = 0;
    char* string = (char*)malloc(sizeof(char));
    char sign = '\0';
    while ((sign != ' ') && (sign != '\n')) {
        string = realloc(string, (size + 2) * sizeof(char));
        scanf("%c", &sign);
        string[size] = sign;
        ++size;
    }
    string[size - 1] = '\0';
    return string;
}