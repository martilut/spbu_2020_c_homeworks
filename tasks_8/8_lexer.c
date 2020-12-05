#include "../library/analyzers/lexer.h"
#include "../library/commonUtils/arrayOperations.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

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
    dfaStates[2] = createDFAState(2, true);
    dfaStates[3] = createDFAState(3, false);
    dfaStates[4] = createDFAState(4, true);
    dfaStates[5] = createDFAState(5, false);
    dfaStates[6] = createDFAState(6, false);
    dfaStates[7] = createDFAState(7, true);
}

void createStatesAndTransitions(DFAState** dfaStates, char digit)
{
    DFAState* startState = dfaStates[0];
    DFAState* numberSignState = dfaStates[1];
    DFAState* intPartState = dfaStates[2];
    DFAState* dotState = dfaStates[3];
    DFAState* floatPartState = dfaStates[4];
    DFAState* EState = dfaStates[5];
    DFAState* ESignState = dfaStates[6];
    DFAState* EDegreeState = dfaStates[7];

    addTransition(startState, '+', numberSignState);
    addTransition(startState, '-', numberSignState);
    addTransition(startState, digit, intPartState);
    addTransition(numberSignState, digit, intPartState);
    addTransition(intPartState, digit, intPartState);
    addTransition(intPartState, '.', dotState);
    addTransition(dotState, digit, floatPartState);
    addTransition(floatPartState, digit, floatPartState);
    addTransition(floatPartState, 'E', EState);
    addTransition(EState, '+', ESignState);
    addTransition(EState, '-', ESignState);
    addTransition(EState, digit, EDegreeState);
    addTransition(ESignState, digit, EDegreeState);
    addTransition(EDegreeState, digit, EDegreeState);
}

int main()
{
    int stateCount = 8;
    char digit = 'd';

    DFAState** dfaStates = (DFAState**)malloc(stateCount * sizeof(DFAState*));
    fillDFAStates(dfaStates);

    createStatesAndTransitions(dfaStates, digit);

    DFA* dfa = createDFA(dfaStates[0]);

    printf("Enter your string:\n");
    char* string = scanString();
    if (isStringCorrect(string, dfa)) {
        printf("It is a number\n");
    } else {
        printf("It is not a number\n");
    }

    free(string);
    freeStates(dfaStates, stateCount);
    removeDFA(dfa);

    return 0;
}
