#include "../library/dataStructures/HashTable/hashTable.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

bool isLetter(char sign)
{
    return (sign >= 'A' && sign <= 'Z') || (sign >= 'a' && sign <= 'z');
}

const int startWordLength = 2;

void scanWord(FILE* testFile, HashTable* hashTable)
{
    int i = 0;
    char sign = (char)fgetc(testFile);
    while (sign != EOF) {
        char* word = (char*)malloc(startWordLength * sizeof(char));
        while (isLetter(sign)) {
            sign = (char)tolower(sign);
            word[i] = sign;
            ++i;
            word = realloc(word, (startWordLength + i) * sizeof(char));
            sign = (char)fgetc(testFile);
        }

        if (i > 0 && isLetter(word[0])) {
            word[i] = '\0';
            addElement(hashTable, word, 1, 1);
        }
        i = 0;
        free(word);
        sign = (char)fgetc(testFile);
    }
}

int main()
{
    HashTable* hashTable = createHashTable(37);

    FILE* testFile = fopen("testFile.txt", "r");
    scanWord(testFile, hashTable);
    fclose(testFile);

    printHashTableStatistics(hashTable);

    removeHashTable(hashTable);

    return 0;
}