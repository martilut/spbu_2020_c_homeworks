#include "../library/dataStructures/List/list.c"
#include <stdio.h>
#include <stdlib.h>

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
        insert(createListElement(value, NULL), i, list);
    }

    printList(list);

    //Head and Tail test
    printf("List head is: %d\n", head(list).value);
    printf("List tail is: %d\n", tail(list).value);

    //InsertElement test
    int insertElement = 0;
    int positionInsert = 0;
    printf("Enter an element to insert and its position:\n");
    scanf("%d %d", &insertElement, &positionInsert);
    if (insert(createListElement(insertElement, NULL), positionInsert, list)) {
        printList(list);
    } else {
        printf("Your element can't be insert");
    }

    //LocateElement test
    int locateElement = 0;
    printf("Enter an element to locate:\n");
    scanf("%d", &locateElement);
    int location = locate(createListElement(locateElement, NULL), list);
    if (location != -1) {
        printf("%d\n", location);
    } else {
        printf("This element is not in the list\n");
    }

    //RetrieveElement test
    int positionRetrieve = 0;
    printf("Retrieve element with position:\n");
    scanf("%d", &positionRetrieve);
    if (positionRetrieve < getSize(list) && positionRetrieve >= 0) {
        printf("%d\n", retrieve(positionRetrieve, list).value);
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

    for (int i = 0; i < size; ++i) {
        deleteElement(i, list);
    }
    free(list);

    return 0;
}