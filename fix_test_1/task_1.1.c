#include "../library/dataStructures/List/doubleList.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool isNumber(char sign)
{
    return sign >= '0' && sign <= '9';
}

int scanNumber(FILE* file)
{
    char* numberString = (char*)malloc(sizeof(char));
    int index = 0;

    while (isNumber((numberString[index] = (char)fgetc(file)))) {
        ++index;
        numberString = realloc(numberString, (index + 1) * sizeof(char));
    }

    if (numberString[index] == EOF) {
        numberString[index] = '\0';
        int endNumber = (int)atoi(numberString);
        free(numberString);
        return -1 * endNumber;
    }

    numberString[index] = '\0';
    int number = (int)atoi(numberString);
    free(numberString);
    return number;
}

int main()
{
    List* list = createList();

    FILE* file = fopen("testFile.txt", "r");

    int k = 1;
    int i = 0;

    while (k > 0){
        k = scanNumber(file);
        if (k > 0) {
            insert(createListElement(k), i, list);
            ++i;
        } else {
            insert(createListElement(-k), i, list);
            break;
        }
    }
    fclose(file);

    int size = getSize(list);
    printList(list);
    ListElement* start = head(list);
    ListElement* end = tail(list);

    for (int i = 0; i < size / 2; ++i) {
        if (getValue(start) == getValue(end)) {
            start = getNext(start);
            end = getPrevious(end);
        } else {
            printf("List is not symmetric\n");
            return 0;
        }
    }

    printf("List is symmetric\n");
    removeList(list);

    return 0;
}
