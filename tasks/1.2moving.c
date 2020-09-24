#include <stdio.h>
#include "../library/commonUtils/arrayOperations.h"

int main()
{
    int n = 0, m = 0;
    int i = 0;

    printf("Enter the lengths of the first and second segment:\n");
    scanf("%d %d", &m, &n);
    int d[m + n];

    printf("Enter the whole segment:\n");
    for (i = 0; i < m + n; i++) {
        scanf("%d", &d[i]);
    }
    for (i = 0; i < m / 2; i++) {
        swapElements(d, i, m);
    }
    for (i = 0; i < n / 2; i++) {
        swapElements(d, i + m, m + m + n);
    }
    for (i = 0; i < (n + m) / 2; i++) {
        swapElements(d, i, m + n);
    }
    for (i = 0; i < m + n; i++) {
        printf("%d ", d[i]);
    }
}