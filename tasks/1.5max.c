#include <stdio.h>

int main()
{
    int MIN_INT = -2147483648;
    int n = 0;
    int maxElement = 0;
    int i = 0, j = 0;

    printf("Enter array lenght:\n");
    scanf("%d", &n);

    int arr[n]; //contains elements
    int val[n]; //val[i] is a number of times arr[i] occurs in arr

    printf("Enter your array:\n");

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        val[i] = 1;
        for (j = 0; j < i; j++) {
            if (arr[j] == arr[i]) {
                val[i] = val[i] + 1;
                val[j] = val[j] + 1;
            }
        }
    }

    maxElement = MIN_INT;
    for (i = 0; i < n; i++) {
        if (arr[i] > maxElement && val[i] > 1)
            maxElement = arr[i];
    }
    if (maxElement == MIN_INT)
        printf("There's no element that occurs more than 1 time in the array");
    else
        printf("%d", maxElement);
}