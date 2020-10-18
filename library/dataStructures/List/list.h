#ifndef SPBU_2020_C_HOMEWORKS_LIST_H
#define SPBU_2020_C_HOMEWORKS_LIST_H
#include <stdbool.h>

typedef struct List List;
typedef struct ListElement ListElement;

ListElement* createListElement(int value, ListElement* next);
List* createList();
void printList(List* list);
int getSize(List* list);

ListElement* tail(List* list);
ListElement* head(List* list);
bool insert(ListElement* value, int position, List* list);
int locate(ListElement* value, List* list);
ListElement* retrieve(int position, List* list);
bool deleteElement(int position, List* list);
void removeList(List* list);
bool removeNextElement(ListElement* element, List* list);
ListElement* getNext(ListElement* element);
void changeNextInCycle(ListElement* element, List* list);
int getValue(ListElement* element);

#endif // SPBU_2020_C_HOMEWORKS_LIST_H
