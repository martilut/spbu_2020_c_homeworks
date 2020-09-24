#include <stdio.h>

int main()
{
    int n = 0, m = 0, i = 0, temp = 0;
    printf("Enter the lengths of the first and second segment:\n");
    scanf("%d %d", &m, &n);
    int d[m + n];

    printf("Enter the whole segment:\n");
    for (i = 0; i < m + n; i++) {
        scanf("%d", &d[i]);
    }
    for (i = 0; i < m / 2; i++) {
        temp = d[i];
        d[i] = d[m - i - 1];
        d[m - i - 1] = temp;
    }
    for (i = 0; i < n / 2; i++) {
        temp = d[i + m];
        d[i + m] = d[m + n - i - 1];
        d[m + n - i - 1] = temp;
    }
    for (i = 0; i < (n + m) / 2; i++) {
        temp = d[i];
        d[i] = d[n + m - i - 1];
        d[n + m - i - 1] = temp;
    }
    for (i = 0; i < m + n; i++) {
        printf("%d ", d[i]);
    }
}
