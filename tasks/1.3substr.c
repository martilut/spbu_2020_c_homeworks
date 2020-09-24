#include <stdio.h>

int main()
{
    int n = 0, m = 0;
    int i = 0, j = 0;

    printf("Enter string lenghts:\n");
    scanf("%d %d", &n, &m);

    int counter = 0;
    char s1[n];
    char s2[m];

    printf("Enter the first string:\n");
    scanf("%s", &s1);
    printf("Enter the second string:\n");
    scanf("%s", &s2);

    for (i = 0; i < n; i++) {
        if (s1[i] == s2[0] && (n - i) >= m) {
            j = 1;
            while (s2[j] == s1[j + i] && (j + i) < n) {
                j = j + 1;
            }
            if (j == m)
                counter = counter + 1;
        }
    }
    printf("The second string occurs in the first string %d times", counter);
}