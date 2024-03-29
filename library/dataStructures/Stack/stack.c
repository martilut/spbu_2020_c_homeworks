#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

struct Stack {
    StackElement* top;
    int size;
};

struct StackElement {
    double value;
    StackElement* next;
};

Stack* createStack()
{
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

StackElement* createStackElement(double value)
{
    StackElement* element = (StackElement*)malloc(sizeof(StackElement));
    element->value = value;
    element->next = NULL;
    return element;
}

double pop(Stack* stack)
{
    if (stack->size == 0) {
        return 0;
    }
    StackElement* element = stack->top;
    double value = element->value;
    stack->top = element->next;
    stack->size--;
    free(element);
    return value;
}

void push(Stack* stack, StackElement* element)
{
    element->next = stack->top;
    stack->top = element;
    stack->size++;
}

double getValue(StackElement* element)
{
    return element->value;
}

void printStack(Stack* stack)
{
    StackElement* element = stack->top;
    while (element != NULL) {
        printf("%f ", element->value);
        element = element->next;
    }
}

void removeStack(Stack* stack)
{
    int size = stack->size;
    while (size > 0) {
        StackElement* element = stack->top;
        stack->top = element->next;
        free(element);
        --size;
    }
    free(stack);
}