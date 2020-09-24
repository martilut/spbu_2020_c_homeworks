#include <stdio.h>

int main()
{
    int n = 0;
    int counter = 0;
    int isComposite = 0;
    int i = 0, j = 0;

    printf("Enter your number:\n");
    scanf("%d", &n);
    int simples[n];

    for (i = 0; i < n; i++) {
        simples[i] = -1;
    }

    if (n < 2){
      printf("There are no simple numbers less than %d", n);
      return 0;
    }

    for (int num = 2; num <= n; num++) {
        counter = 0;
        isComposite = 0;
        while (simples[counter] != -1) {
            if (num % simples[counter] == 0) {
                isComposite = 1;
                counter = n - 2;
            }
            counter = counter + 1;
        }
        if (isComposite == 0) {
          simples[counter] = num;
        }
    }

    for (j = 0; j < n; j++) {
        if (simples[j] != -1)
            printf("%d ", simples[j]);
        else
            break;
    }
}