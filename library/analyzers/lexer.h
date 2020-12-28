#ifndef SPBU_2020_C_HOMEWORKS_LEXER_H
#define SPBU_2020_C_HOMEWORKS_LEXER_H

#include <stdbool.h>

typedef struct Transition Transition;
typedef struct DFAState DFAState;
typedef struct DFA DFA;

Transition* createTransition(char symbol, DFAState* transitionState);
DFA* createDFA(DFAState* initialState);
DFAState* createDFAState(int id, bool isFinal);
void addTransition(DFAState* firstState, char value, DFAState* secondState);
bool isStringCorrect(char* string, DFA* dfa);
void removeDFAState(DFAState* currentState);
void removeDFA(DFA* dfa);
bool isLetter(char symbol);

#endif //SPBU_2020_C_HOMEWORKS_LEXER_H
