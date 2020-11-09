#include "../library/dataStructures/HashTable/hashTable.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* scanWord(FILE* testFile, char firstSign)
{
    int i = 1;
    char* word = (char*)malloc(30 * sizeof(char));
    word[0] = firstSign;
    while ((word[i] = (char)fgetc(testFile)) != EOF) {
        if ((word[i] >= 65 && word[i] <= 90) || (word[i] >= 97 && word[i] <= 122)) {
            ++i;
        } else {
            if (word[i] == ' ' || word[i] == '\n') {
                word[i] = '\0';
                return word;
            } else {
                word[i] = '\0';
                --i;
            }
            ++i;
        }
    }
    word[i] = '\0';
    return word;
}

char* toLowerWord(char* word)
{
    for (int i = 0; i < strlen(word); ++i) {
        word[i] = (char)tolower((int)word[i]);
    }
    return word;
}

int main()
{
    HashTable* hashTable = createHashTable(37);

    FILE* testFile = fopen("testFile.txt", "r");
    char firstSign;
    while ((firstSign = (char)fgetc(testFile)) != EOF) {
        char* word = scanWord(testFile, firstSign);
        word = toLowerWord(word);
        addElement(hashTable, word, 1, 1);
    }
    fclose(testFile);

    printf("1) There are %d words in the text\n", getWordCount(hashTable));
    getMaxInsertionCount(hashTable);
    printf("3) The average number of attempts to insert an element is %d\n", getAverageInsertionCount(hashTable));
    printf("4) Load factor is %f\n", getLoadFactor(hashTable));
    printf("5) There are %d empty buckets in the hash table\n", getEmptyBucketCount(hashTable));
    printTopTenWords(hashTable);

    removeHashTable(hashTable);
    return 0;
}
