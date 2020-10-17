#include "../library/dataStructures/List/list.c"
#include <stdio.h>

int main()
{
    List* list = createList();

    int n = 0;
    int m = 0;
    printf("Enter n and m:\n");
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; ++i) {
        insert(createListElement(i, NULL), i, list);
    }

    ListElement* element = list->tail;
    while (n > 1) {
        for (int j = 0; j < m - 1; ++j) {
            if (element->next == NULL) {
                element->next = list->head;
            }
            element = element->next;
        }
        removeNextElement(element, list);
        --n;
    }
    printf("%d", retrieve(0, list).value + 1);
    removeList(list);
    return 0;
}
