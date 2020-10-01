#include <stdio.h>

#include <stdlib.h>

#include "../library/commonUtils/arrayOperations.h"

#include "../library/commonUtils/numericOperations.h"

int createCount(long long number)
{
    long long temp_number = number;
    int count = 0;
    while (temp_number) {
        temp_number /= 10;
        ++count;
    }
    return count;
}

void makeDigitArray(long long number, int array[], int count)
{
    int div = 0;
    long long temp_number = number;
    for (int i = 0; i < count; ++i) {
        div = (int)(temp_number % 10);
        array[i] = div;
        temp_number /= 10;
    }
}

void swapFirstZero(int array[])
{
    int i = 0;
    while (!array[i]) {
        ++i;
    }
    swapElements(array, 0, i + 1);
}

int main()
{
    long long n = 0;

    printf("Enter your number:\n");
    scanf("%lld", &n);

    int count = createCount(n);
    int digits[count];

    makeDigitArray(n, digits, count);

    qsort(digits, count, sizeof(int), compare);

    if (!digits[0] && count > 1) {
        swapFirstZero(digits);
    }

    printf("Minimal number is ");
    for (int i = 0; i < count; ++i) {
        printf("%d", digits[i]);
    }

    return 0;
}