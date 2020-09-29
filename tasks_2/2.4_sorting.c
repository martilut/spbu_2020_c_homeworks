#include <stdio.h>

#include <stdlib.h>

#include "../library/commonUtils/arrayOperations.h"

#include "../library/commonUtils/numericOperations.h"

int main()
{
    int number = 0, temp_number = 0;
    int i = 0, count = 1;

    printf("Enter your number:\n");
    scanf("%d", &number);
    temp_number = number;

    while (temp_number /= 10)
        count++;

    int digits[count];

    for (i = 0; i < count; i++) {
        digits[i] = number % 10;
        number /= 10;
    }

    qsort(digits, count, sizeof(int), compare);

    i = 0;
    if (!digits[0] && count > 1) {
        while (!digits[i])
            i++;
        swapElements(digits, 0, i + 1); // swaps digits[a] and digits[b - a - 1]
    }

    printf("Minimum number is ");
    for (i = 0; i < count; i++) {
        printf("%d", digits[i]);
    }
}