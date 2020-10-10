#define ARRAY_LENGTH 10
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateNumber(int length, int digits[])
{
    int first_digit = rand() % 9 + 1;
    digits[first_digit] = 1;
    for (int i = 1; i < length; ++i) {
        int number = rand() % 10;
        while (digits[number] > 0) {
            number = rand() % 10;
        }
        digits[number] = i + 1;
    }
}

bool isCorrect(int length, int number, bool digits[])
{
    for (int i = 0; i < length; ++i) {
        if (digits[number % 10]) {
            return false;
        }
        digits[number % 10] = true;
        number /= 10;
    }
    return true;
} //checks if user's number has different digits

int getLenght(number)
{
    int lenght = 0;
    while (number > 0) {
        ++lenght;
        number /= 10;
    }
    return lenght;
}

void compareNumbers(int length, int number, int* bulls, int* cows, int digits[])
{
    int step = length;
    while (number) {
        if (digits[number % 10] > 0) {
            if (digits[number % 10] == step) {
                ++*bulls;
            }
            else {
                ++*cows;
            }
        }
        --step;
        number /= 10;
    }
}

int main()
{
    srand(time(NULL));

    int length = 0;
    int answer_digits[ARRAY_LENGTH] = { 0 };
    printf("How many digits does your number have?\n");
    scanf("%d", &length);

    generateNumber(length, answer_digits);

    int n = 0;
    int attempt = 0;
    int bulls = 0, cows = 0;

    while (bulls != length) {
        bulls = 0;
        cows = 0;

        printf("Enter your number:\n");
        scanf("%d", &n);
        bool user_digits[ARRAY_LENGTH] = { false };

        if (isCorrect(length, n, user_digits) && (getLenght(n) == length)) {
            ++attempt;
            compareNumbers(length, n, &bulls, &cows, answer_digits);
            printf("Attempt %d: %d cows and %d bulls\n", attempt, cows, bulls);
        }
        else {
            printf("Your number is incorrect. Try again.\n");
        }
    }
    printf("That's it, you won!");

    return 0;
}