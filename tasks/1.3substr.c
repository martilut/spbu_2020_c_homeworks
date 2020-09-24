#include <stdio.h>

int main()
{
    int len_s1 = 0, len_s2 = 0;
    int i = 0, j = 0;

    printf("Enter string lenghts:\n");
    scanf("%d %d", &len_s1, &len_s2);

    int counter = 0;
    char s1[len_s1];
    char s2[len_s2];

    printf("Enter the first string:\n");
    scanf("%s", &s1);
    printf("Enter the second string:\n");
    scanf("%s", &s2);

    for (i = 0; i < len_s1; i++) {
        if (s1[i] == s2[0] && (len_s1 - i) >= len_s2) {
            j = 1;
            while (s2[j] == s1[j + i] && (j + i) < len_s1) {
                j = j + 1;
            }
            if (j == len_s2)
                counter = counter + 1;
        }
    }
    printf("The second string occurs in the first string %d times", counter);
}