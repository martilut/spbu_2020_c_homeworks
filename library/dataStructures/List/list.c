#include "list.h"
#include <stdio.h>
#include <stdlib.h>

struct ListElement {
    int value;
    struct ListElement* next;
};

struct List {
    ListElement* head;
    ListElement* tail;
    int size;
};

ListElement* tail(List* list)
{
    return list->tail;
}

ListElement* head(List* list)
{
    return list->head;
}

int getSize(List* list)
{
    return list->size;
}

int getValue(ListElement* element)
{
    if (element == NULL) {
        return NULL;
    }
    return element->value;
}

ListElement* getNext(ListElement* element)
{
    return element->next;
}

ListElement* createListElement(int value)
{
    ListElement* element = (ListElement*)malloc(sizeof(ListElement));
    element->value = value;
    element->next = NULL;
    return element;
}

List* createList()
{
    List* list = (List*)malloc(sizeof(List));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

void printList(List* list)
{
    printf("List: ");
    ListElement* element = list->head;
    while (element != NULL) {
        printf("%d ", element->value);
        element = element->next;
    }
    printf("\n");
}

bool insert(ListElement* value, int position, List* list)
{
    if (position < 0 || position > list->size) {
        return false;
    }
    ListElement* previous = list->head;
    if (position == 0) {
        if (list->tail == NULL) {
            list->tail = value;
        }
        list->head = value;
        value->next = previous;
    } else {
        for (int i = 0; i < position - 1; ++i) {
            previous = previous->next;
        }
        if (previous == list->tail) {
            previous->next = value;
            list->tail = value;
        } else {
            value->next = previous->next;
            previous->next = value;
        }
    }
    list->size++;
    return true;
}

int locate(ListElement* value, List* list)
{
    int counter = 0;
    ListElement* element = list->head;
    while (element != NULL && element != value) {
        ++counter;
        element = element->next;
    }
    if (counter == list->size) {
        return -1;
    }
    return counter;
}

ListElement* retrieve(int position, List* list, int* error)
{
    if (position < 0 || position >= list->size) {
        *error = 1;
        return list->head;
    }
  
    ListElement* element = list->head;
    while (position > 0) {
        --position;
        element = element->next;
    }
    return element;
}

bool deleteElement(int position, List* list)
{
    if (position < 0 || position >= list->size) {
        return false;
    }

    ListElement* previous = list->head;

    if (position == 0) {
        if (list->head == list->tail) {
            list->tail = NULL;
        }
        list->head = list->head->next;
        free(previous);
    } else {
        while (position > 1) {
            --position;
            previous = previous->next;
        }
        ListElement* element = previous->next;
        if (element == list->tail) {
            previous->next = NULL;
            list->tail = previous;
            free(element);
        } else {
            previous->next = element->next;
            free(element);
        }
    }
    list->size--;
    return true;
}

bool removeNextElement(ListElement* previous, List* list)
{
    if (locate(previous, list) == -1) {
        return false;
    }
    if (previous->next == NULL) {
        previous->next = list->head;
    }

    ListElement* element = previous->next;

    if (previous->next == list->tail) {
        list->tail = previous;
    }
    if (previous->next == list->head) {
        list->head = list->head->next;
    }
    previous->next = element->next;
    free(element);
    list->size--;
    return true;
}

void removeListElement(ListElement* element)
{
    free(element);
}

void removeList(List* list)
{
    int size = list->size;
    for (int i = 0; i < size; ++i) {
        deleteElement(0, list);
    }
    free(list);
}

ListElement* getNext(ListElement* element)
{
    return element->next;
}

void changeNextInCycle(ListElement* element, List* list)
{
    element->next = list->head;
}

int getValue(ListElement* element)
{
    return element->value;
}
