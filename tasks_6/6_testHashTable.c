#include "../library/dataStructures/HashTable/hashTable.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* scanWord(FILE* testFile, char firstSign)
{
    int i = 1;
    char* word = (char*)malloc(30 * sizeof(char));
    word[0] = firstSign;
    while ((word[i] = fgetc(testFile)) != EOF) {
        if (word[i] == ' ' || word[i] == '\n') {
            word[i] = '\0';
            return word;
        } else {
            ++i;
        }
    }
    word[i] = '\0';
    return word;
}

int main()
{
    FILE* testFile = fopen("testFile.txt", "r");
    char firstSign;
    while ((firstSign = fgetc(testFile)) != EOF) {
        char* word = scanWord(testFile, firstSign);
        printf("%s\n", word);
    }
    fclose(testFile);
    return 0;
}
