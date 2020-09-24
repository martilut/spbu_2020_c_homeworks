#include <stdio.h>

int main()
{
    int n, k, i, j, s;
    scanf("%d", &n);
    int simp[n];

    for (i = 0; i < n; i++) {
        simp[i] = -1;
    }
    if (n >= 2) {
        for (int num = 2; num <= n; num++) {
            k = 0;
            s = 0;
            while (simp[k] != -1) {
                if (num % simp[k] == 0) {
                    s = 1;
                    k = n - 2;
                }
                k = k + 1;
            }
            if (s == 0) {
                simp[k] = num;
            }
        }
        for (j = 0; j < n; j++) {
            if (simp[j] != -1)
                printf("%d ", simp[j]);
            else
                break;
        }
    }
}
