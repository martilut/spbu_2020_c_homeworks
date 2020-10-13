#include <stdio.h>
#include <string.h>

void sortTwoArrays(int n, int m, int arrayN[], int arrayM[], int answer_array[]) {
    int indexN = 0;
    int indexM = 0;
    int indexA = 0;
    while ((indexN < n) || (indexM < m)) {
        if (arrayN[indexN] < arrayM[indexM]) {
            answer_array[indexA] = arrayN[indexN];
            ++indexA;
            ++indexN;
        }
        else {
            answer_array[indexA] = arrayM[indexM];
            ++indexA;
            ++indexM;
        }
    }
    while (indexN < n - 1) {
        answer_array[indexA] = arrayN[indexN];
        ++indexA;
        ++indexN;
    }
    while (indexM < n - 1) {
        answer_array[indexA] = arrayM[indexM];
        ++indexA;
        ++indexM;
    }
}

int main()
{
    int n = 0;
    printf("Enter the length of Vasya's stack:\n");
    scanf("%d", &n);

    int arrayV[n];
    memset(&arrayV, 0, n);

    printf("Enter Vasya's stack:\n");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arrayV[i]);
    }

    int m = 0;
    printf("Enter the lenght of Petya's stack:\n");
    scanf("%d", &m);

    int arrayP[m];
    memset(&arrayP, 0, m);

    printf("Enter Petya's stack:\n");
    for (int i = 0; i < m; ++i) {
        scanf("%d", &arrayP[i]);
    }

    int answer_array[n + m];
    memset(&answer_array, 0, n + m);
    sortTwoArrays(n, m, arrayV, arrayP, answer_array);

    for (int j = 0; j < n + m; ++j) {
        printf("%d ", answer_array[j]);
    }
}