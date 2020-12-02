#include "lexer.h"
#include "../commonUtils/numericOperations.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct Transition {
    char symbol;
    DFAState* transitionState;
};

struct DFAState {
    int id;
    bool isFinal;
    int transitionsSize;
    int transitionAllocationSize;
    Transition** transitions;
};

struct DFA {
    DFAState* initialState;
    DFAState* failState;
};

Transition* createTransition(char symbol, DFAState* transitionState)
{
    Transition* transition = (Transition*)malloc(sizeof(Transition));
    transition->symbol = symbol;
    transition->transitionState = transitionState;

    return transition;
}

DFA* createDFA(DFAState* initialState)
{
    DFA* dfa = (DFA*)malloc(sizeof(DFA));
    dfa->initialState = initialState;
    dfa->failState = createDFAState(-1, false);

    return dfa;
}

DFAState* createDFAState(int id, bool isFinal)
{
    DFAState* dfaState = (DFAState*)malloc(sizeof(DFAState));
    dfaState->id = id;
    dfaState->isFinal = isFinal;
    dfaState->transitionsSize = 0;
    dfaState->transitionAllocationSize = 1;
    dfaState->transitions = (Transition**)calloc(1, sizeof(Transition*));
    return dfaState;
}

void expandTransition(DFAState* dfaState)
{
    dfaState->transitions = realloc(dfaState->transitions, dfaState->transitionAllocationSize * 2 * sizeof(Transition*));
    memset(dfaState->transitions + dfaState->transitionAllocationSize, 0, dfaState->transitionAllocationSize * sizeof(Transition*));
    dfaState->transitionAllocationSize *= 2;
}

void addTransition(DFAState* firstState, char value, DFAState* secondState)
{
    Transition* newTransition = createTransition(value, secondState);
    if (firstState->transitionAllocationSize == firstState->transitionsSize) {
        expandTransition(firstState);
    }
    firstState->transitions[firstState->transitionsSize] = newTransition;
    firstState->transitionsSize++;
}

bool isStringCorrect(char* string, DFA* dfa)
{
    DFAState* currentState = dfa->initialState;
    for (int i = 0; i < strlen(string); ++i) {
        char currentSymbol = string[i];
        if (isDigit(currentSymbol)) {
            currentSymbol = 'd';
        }
        bool isSymbolFound = false;
        for (int j = 0; j < currentState->transitionsSize; ++j) {
            if (currentState->transitions[j]->symbol == currentSymbol) {
                currentState = currentState->transitions[j]->transitionState;
                isSymbolFound = true;
                break;
            }
        }
        if (!isSymbolFound) {
            currentState = dfa->failState;
        }
    }
    return currentState->isFinal;
}

void removeDFAState(DFAState* currentState)
{
    for (int i = 0; i < currentState->transitionAllocationSize; ++i) {
        free(currentState->transitions[i]);
    }
    free(currentState->transitions);
    free(currentState);
}

void removeDFA(DFA* dfa)
{
    removeDFAState(dfa->failState);
    free(dfa);
}
