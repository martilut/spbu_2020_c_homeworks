#include "../library/analyzers/lexer.h"
#include "../library/commonUtils/arrayOperations.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void freeStates(DFAState** dfaStates)
{
    for (int i = 0; i < 8; ++i) {
        removeDFAState(dfaStates[i]);
    }
    free(dfaStates);
}

int main()
{
    DFAState** dfaStates = (DFAState**)malloc(8 * sizeof(DFAState*));
    dfaStates[0] = createDFAState(0, false);
    dfaStates[1] = createDFAState(1, false);
    dfaStates[2] = createDFAState(2, true);
    dfaStates[3] = createDFAState(3, false);
    dfaStates[4] = createDFAState(4, true);
    dfaStates[5] = createDFAState(5, false);
    dfaStates[6] = createDFAState(6, false);
    dfaStates[7] = createDFAState(7, true);

    addTransition(dfaStates[0], '+', dfaStates[1]);
    addTransition(dfaStates[0], '-', dfaStates[1]);
    addTransition(dfaStates[0], 'd', dfaStates[2]);
    addTransition(dfaStates[1], 'd', dfaStates[2]);
    addTransition(dfaStates[2], 'd', dfaStates[2]);
    addTransition(dfaStates[2], '.', dfaStates[3]);
    addTransition(dfaStates[3], 'd', dfaStates[4]);
    addTransition(dfaStates[4], 'd', dfaStates[4]);
    addTransition(dfaStates[4], 'E', dfaStates[5]);
    addTransition(dfaStates[5], '+', dfaStates[6]);
    addTransition(dfaStates[5], '-', dfaStates[6]);
    addTransition(dfaStates[5], 'd', dfaStates[7]);
    addTransition(dfaStates[6], 'd', dfaStates[7]);
    addTransition(dfaStates[7], 'd', dfaStates[7]);

    DFA* dfa = createDFA(dfaStates[0]);

    printf("Enter your string:\n");
    char* string = scanString();
    if (isStringCorrect(string, dfa)) {
        printf("It is a number\n");
    } else {
        printf("It is not a number\n");
    }

    free(string);
    freeStates(dfaStates);
    removeDFA(dfa);

    return 0;
}
