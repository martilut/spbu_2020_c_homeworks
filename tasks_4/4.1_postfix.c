#include "../library/commonUtils/arrayOperations.h"
#include "../library/dataStructures/Stack/stack.h"
#include <stdio.h>
#include <stdlib.h>

double makeOperation(char sign, double b, double a, int* error)
{
    switch (sign) {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        if (b == 0) {
            *error = 1;
            return 0;
        }
        return a / b;
    default:
        *error = 2;
        return 0;
    }
}

void printError(int errorCode)
{
    if (errorCode == 1) {
        printf("Incorrect input: division by zero");
    } else {
        printf("Incorrect input: unexpected sign");
    }
}

int main()
{
    int expressionLength = 0;
    printf("Enter the lenght of your expression:\n");
    scanf("%d", &expressionLength);

    Stack* stack = createStack();

    printf("Enter your expression (using spaces):\n");
    char* emptyScan = scanString(); //it scans a new line sign left by previous scanf in buffer
    free(emptyScan);

    for (int i = 0; i < expressionLength; ++i) {
        char* string = scanString();
        double converted = atof(string);
        if ((converted != 0) || (*string == '0')) {
            push(stack, createStackElement(converted));
        } else {
            int error = 0;
            double firstElement = pop(stack); // memory's got cleared in pop function
            double secondElement = pop(stack);
            double answer = makeOperation(*string, firstElement, secondElement, &error);
            if (error == 0) {
                push(stack, createStackElement(answer));
            } else {
                printError(error);
                free(string);
                removeStack(stack);
                return 0;
            }
        }
        free(string);
    }

    printf("Answer is: %.3f", pop(stack));
    removeStack(stack);

    return 0;
}