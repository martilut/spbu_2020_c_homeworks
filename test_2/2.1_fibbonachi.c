#include <stdio.h>

int main()
{
    int position = 0;
    int firstNumber = 0;
    int secondNumber = 1;
    printf("Enter a position:\n");
    scanf("%d", &position);
    --position;
    while (position > 0) {
        int temp = firstNumber;
        firstNumber = secondNumber;
        secondNumber = firstNumber + temp;
        --position;
    }
    printf("%d", secondNumber);
    return 0;
}
