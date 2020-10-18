#include "../library/dataStructures/List/list.h"
#include <stdio.h>

int main()
{
    List* list = createList();

    int size = 0;
    printf("Enter a size of your list:\n");
    scanf("%d", &size);
    if (size == 0) {
        int errorZero = 0;
        insert(createListElement(6), 0, list);
        insert(createListElement(2), 0, list);
        printList(list);
        printf("%d\n", retrieve(0, list, &errorZero).value);
        deleteElement(1, list);
        printList(list);
        removeList(list);
        return 0;
    }

    printf("Enter your list:\n");
    for (int i = 0; i < size; ++i) {
        int value = 0;
        scanf("%d", &value);
        insert(createListElement(value), i, list);
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
    if (insert(createListElement(insertElement), positionInsert, list)) {
        printList(list);
    } else {
        printf("Your element can't be insert\n");
    }

    //RetrieveElement test
    int positionRetrieve = 0;
    int error = 0;
    printf("Retrieve element with position:\n");
    scanf("%d", &positionRetrieve);
    ListElement element = retrieve(positionRetrieve, list, &error);
    if (error == 0) {
        printf("%d\n", element.value);
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
        printf("This position is incorrect\n");
    }

    removeList(list);

    int errorLocate = 0;
    List* listLocate = createList();
    for (int i = 0; i < 5; ++i) {
        insert(createListElement(i + 1), i, listLocate);
    }
    ListElement previous = retrieve(2, listLocate, &errorLocate);
    if (errorLocate == 0) {
        printf("%d", locate(previous.next, listLocate));;
    } else {
        printf("This position is incorrect\n");
    }

    removeList(listLocate);

    return 0;
}
