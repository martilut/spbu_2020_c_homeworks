#include <malloc.h>

#include <stdbool.h>

#include <stdio.h>

#include <stdlib.h>

#include <time.h>

#include "../library/commonUtils/arrayOperations.h"

void getDigits(int digits[10], int lenght)
{
    for (int i = 1; i < lenght; ++i) {
        int number = rand() % 10;
        while (digits[number] > 0) {
            number = rand() % 10;
        }
        digits[number] = i + 1;
    }
}

bool markDigits(int lenght, int number, int digits[10])
{
    int temp_number = number;
    for (int i = lenght - 1; i >= 0; --i) {
        if (digits[temp_number % 10] > 0) {
            return false;
        }
        digits[temp_number % 10] = i + 1;
        temp_number /= 10;
    }
    return true;
}

void resetDigits(int digits[10])
{
    for (int i = 0; i < 10; ++i) {
        digits[i] = 0;
    }
}

void countDigits(int* bulls, int* cows, int user_digit, int user_value)
{
    if (user_digit > 0 && user_value > 0) {
        if (user_digit == user_value) {
            ++*bulls;
        }
        else {
            ++*cows;
        }
    }
}

int main()
{
    srand(time(NULL));

    int lenght = 0;

    printf("How many digits does your number have?\n");
    scanf("%d", &lenght);

    int correct_values[10] = {0};
    int digit = rand() % 9 + 1;
    correct_values[digit] = 1;
    getDigits(correct_values, lenght);

    int n = 0;
    int attempt = 0;
    int bulls = 0, cows = 0;

    while (bulls != lenght) {
        int user_values[10] = {0};

        bulls = 0;
        cows = 0;

        printf("Enter your number:\n");
        scanf("%d", &n);

        if (markDigits(lenght, n, user_values)) {
            ++attempt;
            for (int i = 0; i < 10; ++i) {
                countDigits(&bulls, &cows, user_values[i], correct_values[i]);
            }
            printf("Attempt %d: %d cows and %d bulls\n",attempt, cows, bulls);
            resetDigits(user_values);
        }
        else {
            printf("Your number must have different digits. Try again.\n");
        }
    }
    printf("You won.");
    return 0;
}