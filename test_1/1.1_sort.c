#include <stdio.h>

void sortTwoArrays(int n, int m, int arrayN[], int arrayM[], int answer_array[])
{
    int indexN = 0;
    int indexM = 0;
    int indexA = 0;
    while ((indexN < n) && (indexM < m)) {
        if (arrayN[indexN] < arrayM[indexM]) {
            answer_array[indexA] = arrayN[indexN];
            indexN++;
        } else {
            answer_array[indexA] = arrayM[indexM];
            indexM++;
        }
        indexA++;
    }
    while (indexN < n) {
        answer_array[indexA] = arrayN[indexN];
        indexA++;
        indexN++;
    }
    while (indexM < m) {
        answer_array[indexA] = arrayM[indexM];
        indexA++;
        indexM++;
    }
}

int main()
{
    int n = 0;
    printf("Enter the length of Vasya's stack:\n");
    scanf("%d", &n);

    int arrayV[n];

    printf("Enter Vasya's stack:\n");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arrayV[n - i - 1]);
    }

    int m = 0;
    printf("Enter the lenght of Petya's stack:\n");
    scanf("%d", &m);

    int arrayP[m];

    printf("Enter Petya's stack:\n");
    for (int i = 0; i < m; ++i) {
        scanf("%d", &arrayP[m - i - 1]);
    }

    int answer_array[n + m];
    sortTwoArrays(n, m, arrayV, arrayP, answer_array);

    for (int j = 0; j < n + m; ++j) {
        printf("%d ", answer_array[n + m - j - 1]);
    }
    
    return 0;
}
