#include <stdio.h>

int main(){

    int n, i, j;
    long long int k;
    scanf("%d", &n);

    int arr[n];
    int val[n];

    for (i = 0; i < n; i++){
        scanf("%d", &arr[i]);
        val[i] = 1;
        for (j = 0; j < i; j++){
            if (arr[j] == arr[i]){
                val[i] = val[i] + 1;
                val[j] = val[j] + 1;
            }
        }
    }
    k = -2147483649;
    for (i = 0; i < n; i++){
        if (arr[i] > k && val[i] > 1)
            k = arr[i];
    }
    if (k == -2147483649)
        printf("None");
    else
        printf("%d", k);

}
