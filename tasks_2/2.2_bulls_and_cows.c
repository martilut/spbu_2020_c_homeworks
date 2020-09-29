#include <stdio.h>

#include <stdlib.h>

#include <time.h>

int getDigit(int array[])
{
    int number = rand() % 10;
    while (array[number] == -1) {
        number = rand() % 10;
    }
    return number;
};

int main()
{

    srand(time(NULL));

    int attempt = 0;
    int n = 0, i = 0;
    int cows = 0, bulls = 0;
    int values[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int number[] = {0, 0, 0, 0};

    number[0] = rand() % 9 + 1;
    values[number[0]] = -1;

    for (i = 1; i < 4; i++) {
        number[i] = getDigit(values);
        values[number[i]] = -1;
    }

    printf("Enter your number:\n");

    while (bulls != 4) {
        scanf("%d", &n);

        cows = 0;
        bulls = 0;

        for (i = 0; i < 4; i++) {
            if (values[n / 1000] == -1) {
                if (n / 1000 == number[i])
                    bulls++;
                else
                    cows++;
            }
            n = (n % 1000) * 10;
        }

        attempt++;
        printf("Attempt %d: %d cows and %d bulls\n", attempt, cows, bulls);
    }

    printf("That's it, you won!");
}
