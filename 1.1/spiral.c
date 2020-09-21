#include <stdio.h>

int main() {

    int n;
    scanf("%d", &n);

    int x = n / 2;
    int y = n / 2;
    int b1 = x - 1;
    int b2 = x + 1;
    int arr[n][n];

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            scanf("%d", &arr[i][j]);
        }
    }

    printf("%d ", arr[x][y]);

    for (int k = 0; k < n / 2; k++){
        while (x < b2 + k){
            x = x + 1;
            printf("%d ", arr[x][y]);
        }
        while (y < b2 + k){
            y = y + 1;
            printf("%d ", arr[x][y]);
        }
        while (x > b1 - k){
            x = x - 1;
            printf("%d ", arr[x][y]);
        }
        while (y > b1 - k){
            y = y - 1;
            printf("%d ", arr[x][y]);
        }
        while (x < b2 + k){
            x = x + 1;
            printf("%d ", arr[x][y]);
        }
    }
}
