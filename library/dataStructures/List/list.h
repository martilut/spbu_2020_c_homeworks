#ifndef SPBU_2020_C_HOMEWORKS_LIST_H
#define SPBU_2020_C_HOMEWORKS_LIST_H
#include <stdbool.h>

typedef struct List List;

typedef struct ListElement
{
  int value;
  struct ListElement* next;
} ListElement;

ListElement* createListElement(int value, ListElement* next);
List* createList();
void printList(List* list);

int getSize(List* list);
ListElement tail(List* list);
ListElement head(List* list);
bool insert(ListElement* value, int position, List* list);
int locate(ListElement* value, List* list);
ListElement retrieve(int position, List* list);
bool delete(int position, List* list);

#endif // SPBU_2020_C_HOMEWORKS_LIST_H
