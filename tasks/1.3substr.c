#include <stdio.h>

int main()
{
    int n, m, i, j;
    scanf("%d %d", &n, &m);

    int k = 0;
    char s1[n];
    char s2[m];
    scanf("%s", &s1);
    scanf("%s", &s2);
    for (i = 0; i < n; i++) {
        if (s1[i] == s2[0] && (n - i) >= m) {
            j = 1;
            while (s2[j] == s1[j + i] && (j + i) < n) {
                j = j + 1;
            }
            if (j == m)
                k = k + 1;
        }
    }
    printf("%d", k);
}
