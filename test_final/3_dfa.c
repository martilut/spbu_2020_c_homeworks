#include "../library/analyzers/lexer.h"
#include "../library/commonUtils/arrayOperations.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void freeStates(DFAState** dfaStates, int stateCount)
{
    for (int i = 0; i < stateCount; ++i) {
        removeDFAState(dfaStates[i]);
    }
    free(dfaStates);
}

void fillDFAStates(DFAState** dfaStates)
{
    dfaStates[0] = createDFAState(0, false);
    dfaStates[1] = createDFAState(1, false);
    dfaStates[2] = createDFAState(2, false);
    dfaStates[3] = createDFAState(3, false);
    dfaStates[4] = createDFAState(4, false);
    dfaStates[5] = createDFAState(5, true);
}

void addFirstTransition(DFAState* firstState, DFAState* secondState, char digit, char letter)
{
    addTransition(firstState, letter, secondState);
    addTransition(firstState, digit, secondState);
    addTransition(firstState, '.', secondState);
    addTransition(firstState, '_', secondState);
    addTransition(firstState, '%', secondState);
    addTransition(firstState, '+', secondState);
    addTransition(firstState, '-', secondState);
}

void addSecondTransition(DFAState* firstState, DFAState* secondState, char digit, char letter)
{
    addTransition(firstState, letter, secondState);
    addTransition(firstState, digit, secondState);
    addTransition(firstState, '-', secondState);
}

void createStatesAndTransitions(DFAState** dfaStates, char digit, char letter)
{
    DFAState* startState = dfaStates[0];
    DFAState* symbolState = dfaStates[1];
    DFAState* aState = dfaStates[2];
    DFAState* letterOrDigitState = dfaStates[3];
    DFAState* dotState = dfaStates[4];
    DFAState* finalState = dfaStates[5];

    addFirstTransition(startState, symbolState, digit, letter);
    addFirstTransition(symbolState, symbolState, digit, letter);
    addTransition(symbolState, '@', aState);
    addSecondTransition(aState, letterOrDigitState, digit, letter);
    addSecondTransition(letterOrDigitState, letterOrDigitState, digit, letter);
    addTransition(letterOrDigitState, '.', dotState);
    addSecondTransition(dotState, letterOrDigitState, digit, letter);
    addTransition(letterOrDigitState, 'e', finalState);
}

int main()
{
    int stateCount = 6;
    char digit = 'd';
    char letter = 'l';

    DFAState** dfaStates = (DFAState**)malloc(stateCount * sizeof(DFAState*));
    fillDFAStates(dfaStates);

    createStatesAndTransitions(dfaStates, digit, letter);

    DFA* dfa = createDFA(dfaStates[0]);

    printf("Enter your string:\n");
    char* string = scanString();
    int length = strlen(string);
    string = realloc(string, (length + 2) * sizeof(char));
    string[length] = 'e';
    string[length + 1] = '\0';

    if (isStringCorrect(string, dfa) && isLetter(string[length - 1])) {
        printf("String is correct\n");
    } else {
        printf("String is incorrect\n");
    }

    free(string);
    freeStates(dfaStates, stateCount);
    removeDFA(dfa);

    return 0;
}
