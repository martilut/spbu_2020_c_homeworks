#define MAX_LENGTH 100
#include "../library/dataStructures/Stack/stack.h"
#include <stdio.h>
#include <stdlib.h>

double makeOperation(char sign, double b, double a)
{
    if (sign == '+') {
        return a + b;
    }
    if (sign == '-') {
        return a - b;
    }
    if (sign == '*') {
        return a * b;
    }
    if ((sign == '/') && (b != 0)) {
        return a / b;
    } else {
        return 0;
    }
}

int main()
{
    int expressionLength = 0;
    printf("Enter the lenght of your expression:\n");
    scanf("%d", &expressionLength);

    Stack* stack = createStack();
    printf("Enter your expression:\n");
    for (int i = 0; i < expressionLength; ++i) {
        char* string = malloc(MAX_LENGTH * sizeof(char));
        scanf("%s", string);
        if (atof(string)) {
            push(stack, createStackElement(atof(string)));
        } else {
            double firstElement = getValue(pop(stack));
            double secondElement = getValue(pop(stack));
            double answer = makeOperation(*string, firstElement, secondElement);
            push(stack, createStackElement(answer));
        }
    }
    printf("Answer is: %.3f", getValue(pop(stack)));
    return 0;
}