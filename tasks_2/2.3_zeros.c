#include <stdio.h>

int main()
{
    int n = 0;
    int i = 0;
    int zeroCounter = 0;

    printf("Enter n:\n");
    scanf("%d", &n);

    int array[n];
    printf("Enter your array:\n");

    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    for (i = 0; i < n; i++) {
        if (!array[i])
            zeroCounter++;
        else
            array[i - zeroCounter] = array[i];
    }

    for (i = (n - zeroCounter); i < n; i++) {
        array[i] = 0;
    }

    for (i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
}