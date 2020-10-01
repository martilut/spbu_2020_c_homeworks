#include <stdio.h>

void fillArray(int array[], int n)
{
    for (int i = 0; i < n; ++i) {
        array[i] = 0;
    }
}

void decompose(int number, int term, int index, int array[])
{
    if (number < 0) {
        return;
    }
    if (!number) {
        for (int k = 0; k < index; ++k) {
            printf("%d ", array[k]);
        }
        printf("\n");
    }
    
    else {
        if (number >= term) {
            array[index] = term;
            decompose(number - term, term, index + 1, array);
        }
        if (term > 1) {
            decompose(number, term - 1, index, array);
        }
    }
}

int main()
{
    int n = 0;

    printf("Enter your n:\n");
    scanf("%d", &n);

    int terms[n];
    fillArray(terms, n);

    decompose(n, n, 0, terms);

    return 0;
}