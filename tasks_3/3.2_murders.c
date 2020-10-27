#include "../library/dataStructures/List/list.h"
#include <stdio.h>

int main()
{
    List* list = createList();

    int n = 0;
    int m = 0;
    printf("Enter n and m:\n");
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; ++i) {
        insert(createListElement(i), i, list);
    }

    ListElement* element = tail(list);
    while (n > 1) {
        for (int j = 0; j < m - 1; ++j) {
            if (getNext(element) == NULL) {
                changeNextInCycle(element, list);
            }
            element = getNext(element);
        }
        removeNextElement(element, list);
        --n;
    }
    int error = 0;
    printf("%d", getValue(retrieve(0, list, &error)) + 1);
    removeList(list);
    return 0;
}
