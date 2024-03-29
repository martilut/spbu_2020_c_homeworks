#include "../library/dataStructures/List/list.h"
#include <stdio.h>

int main()
{
    List* list = createList();

    int size = 0;
    printf("Enter a size of your list:\n");
    scanf("%d", &size);

    printf("Enter your list:\n");
    for (int i = 0; i < size; ++i) {
        int value = 0;
        scanf("%d", &value);
        insert(createListElement(value), i, list);
    }

    printList(list);

    //Head and Tail test
    if (size > 0) {
        printf("List head is: %d\n", getValue(head(list)));
        printf("List tail is: %d\n", getValue(tail(list)));
    } else {
        printf("No head, no tail\n");
    }

    //InsertElement test
    int insertValue = 0;
    int positionInsert = 0;
    printf("Enter an element to insert and its position:\n");
    scanf("%d %d", &insertValue, &positionInsert);
    ListElement* insertElement = createListElement(insertValue);
    if (insert(insertElement, positionInsert, list)) {
        printList(list);
    } else {
        printf("Your element can't be insert\n");
        removeListElement(insertElement);
    }

    //RetrieveElement test
    int positionRetrieve = 0;
    int error = 0;
    printf("Retrieve element with position:\n");
    scanf("%d", &positionRetrieve);
    ListElement* element = retrieve(positionRetrieve, list, &error);
    if (error == 0) {
        printf("%d is on position %d\n", getValue(element), positionRetrieve);
    } else {
        printf("This position is incorrect\n");
    }

    //DeleteElement test
    int positionDelete = 0;
    printf("Delete element with position:\n");
    scanf("%d", &positionDelete);
    if (deleteElement(positionDelete, list)) {
        printList(list);
    } else {
        printf("This position is incorrect");
    }
    printf("\n");

    removeList(list);

    int errorLocate = 0;
    int positionLocate = 2;
    List* listLocate = createList();
    ListElement* listNumber = createListElement(1);
    for (int i = 0; i < 5; ++i) {
        insert(listNumber, i, listLocate);
        listNumber = createListElement(i + 2);
    }

    printList(listLocate);

    ListElement* previous = retrieve(positionLocate, listLocate, &errorLocate);
    if (errorLocate == 0) {
        printf("%d is on position %d", locate(getNext(previous), listLocate), positionLocate);
    } else {
        printf("This position is incorrect\n");
    }

    removeListElement(listNumber);
    removeList(listLocate);

    return 0;
}
