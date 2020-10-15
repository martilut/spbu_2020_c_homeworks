#ifndef SPBU_2020_C_HOMEWORKS_STACK_H
#define SPBU_2020_C_HOMEWORKS_STACK_H

typedef struct Stack Stack;
typedef struct StackElement StackElement;

Stack* createStack();
StackElement* createStackElement(double value);

StackElement* pop(Stack* stack);
void push(Stack* stack, StackElement* element);
void removeStack(Stack* stack);

double getValue(StackElement* element);
void printStack(Stack* stack);

#endif // SPBU_2020_C_HOMEWORKS_STACK_H
