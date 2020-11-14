#include "../library/dataStructures/HashTable/hashTable.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

bool isLetter(char sign)
{
    if ((sign >= 'A' && sign <= 'Z') || (sign >= 'a' && sign <= 'z')) {
        return true;
    } else {
        return false;
    }
}

const int startWordLength = 3;

char* scanWord(FILE* testFile, char firstSign)
{
    int i = 1;
    char* word = (char*)malloc(startWordLength * sizeof(char));
    if (isLetter(firstSign)) {
        firstSign = (char)tolower((int)firstSign);
        word[0] = firstSign;
    } else {
        return NULL;
    }
    while ((word[i] = (char)fgetc(testFile)) != EOF) {
        if (isLetter(word[i])) {
            word[i] = (char)tolower((int)word[i]);
            ++i;
        } else {
          word[i] = '\0';
          if (isLetter(word[0])) {
              return word;
          } else {
              return NULL;
          }
        }
        word = realloc(word, (startWordLength + i) * sizeof(char));
    }
    word[i] = '\0';
    if (isLetter(word[0])) {
        return word;
    } else {
        return NULL;
    }
}

int main()
{
    HashTable* hashTable = createHashTable(37);

    FILE* testFile = fopen("testFile.txt", "r");
    char firstSign = '\0';
    while ((firstSign = (char)fgetc(testFile)) != EOF) {
        char* word = scanWord(testFile, firstSign);
        printf("%s\n", word);
        if (word != NULL) {
            addElement(hashTable, word, 1, 1);
        }
    }
    fclose(testFile);

    printf("1) There are %d words in the text\n", getWordCount(hashTable));
    printMaxInsertionCount(hashTable);
    printf("3) The average number of attempts to insert an element is %d\n", getAverageInsertionCount(hashTable));
    printf("4) Load factor is %f\n", getLoadFactor(hashTable));
    printf("5) There are %d empty buckets in the hash table\n", getEmptyBucketCount(hashTable));

    int n = 0;
    printf("Enter the amount of top words to print:\n");
    scanf("%d", &n);
    printTopWords(hashTable, n);

    removeHashTable(hashTable);

    return 0;
}