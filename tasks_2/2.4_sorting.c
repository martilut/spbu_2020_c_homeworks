#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../library/commonUtils/arrayOperations.h"
#include "../library/commonUtils/numericOperations.h"

int countDigits(long long number)
{
    int count = 0;
    while (number > 0) {
        number /= 10;
        ++count;
    }
    return count;
}

void makeDigitArray(long long number, int* array, int count)
{
    for (int i = 0; i < count; ++i) {
        array[i] = (int)(number % 10);
        number /= 10;
    }
}

void swapFirstZero(int* array)
{
    int i = 0;
    while (array[i] == 0) {
        ++i;
    }
    swapElements(array, 0, i + 1);
}

int main()
{
    long long n = 0;
    printf("Enter your number:\n");
    scanf("%lld", &n);
    int count = countDigits(n);

    int* digits = (int*)malloc(count * sizeof(int));
    memset(digits, 0, count);

    makeDigitArray(n, digits, count);

    qsort(digits, count, sizeof(int), compare);

    if (count > 1 && digits[0] == 0) {
        swapFirstZero(digits);
    }

    printf("Minimal number is ");
    for (int i = 0; i < count; ++i) {
        printf("%d", digits[i]);
    }

    free(digits);
    return 0;
}