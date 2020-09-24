#include <stdio.h>

int main()
{
    int n = 0;
    printf("Enter n:\n");
    scanf("%d", &n);

    int x = n / 2;
    int y = n / 2;
    int border_1 = x - 1;
    int border_2 = x + 1;
    int arr[n][n];

    printf("Enter your array:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    printf("%d ", arr[x][y]);

    for (int k = 0; k < n / 2; k++) {
        while (x < border_2 + k) {
            x = x + 1;
            printf("%d ", arr[x][y]);
        }
        while (y < border_2 + k) {
            y = y + 1;
            printf("%d ", arr[x][y]);
        }
        while (x > border_1 - k) {
            x = x - 1;
            printf("%d ", arr[x][y]);
        }
        while (y > border_1 - k) {
            y = y - 1;
            printf("%d ", arr[x][y]);
        }
        while (x < border_2 + k) {
            x = x + 1;
            printf("%d ", arr[x][y]);
        }
    }
}