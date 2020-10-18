#ifndef SPBU_2020_C_HOMEWORKS_LIST_H
#define SPBU_2020_C_HOMEWORKS_LIST_H
#include <stdbool.h>

typedef struct ListElement {
  int value;
  struct ListElement* next;
} ListElement;

typedef struct List {
  ListElement* head;
  ListElement* tail;
  int size;
} List;

ListElement* createListElement(int value);
List* createList();
void printList(List* list);
int getSize(List* list);

ListElement tail(List* list);
ListElement head(List* list);
bool insert(ListElement* value, int position, List* list);
int locate(ListElement* value, List* list);
ListElement retrieve(int position, List* list, int* error);
bool deleteElement(int position, List* list);
void removeList(List* list);

#endif // SPBU_2020_C_HOMEWORKS_LIST_H
