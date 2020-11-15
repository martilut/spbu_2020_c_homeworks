#include "hashTable.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const double maxLoadFactor = 0.7;

enum CellType { EMPTY,
    USED };

struct HashElement {
    char* key;
    int valueCount;
    int insertionCount;
};

struct HashTable {
    HashElement** hashArray;
    enum CellType* types;
    int bucketCount;
    int elementCount;
    int polynomFactor;
};

HashElement* createHashElement(char* key)
{
    HashElement* element = (HashElement*)malloc(sizeof(HashElement));
    int keySize = (int)strlen(key);
    element->key = (char*)malloc((keySize + 1) * sizeof(char));
    strcpy(element->key, key);
    element->key[keySize] = '\0';
    element->valueCount = 0;
    element->insertionCount = 0;
    return element;
}

HashTable* createHashTableWithSize(int size, int polynomFactor)
{
    HashTable* hashTable = (HashTable*)malloc(sizeof(HashTable));
    hashTable->hashArray = (HashElement**)malloc(size * sizeof(HashElement*));
    hashTable->types = (enum CellType*)malloc(size * sizeof(enum CellType));
    hashTable->bucketCount = size;
    hashTable->elementCount = 0;
    hashTable->polynomFactor = polynomFactor;
    memset(hashTable->hashArray, 0, size * sizeof(HashElement*));
    memset(hashTable->types, (int)EMPTY, size * sizeof(enum CellType));
    return hashTable;
}

HashTable* createHashTable(int polynomFactor)
{
    return createHashTableWithSize(1, polynomFactor);
}

float getLoadFactor(HashTable* table)
{
    return (float)table->elementCount / (float)table->bucketCount;
}

int getHash(char* key, int polynomFactor, int module)
{
    int hash = 0;
    int length = (int)strlen(key);
    for (int i = 0; i < length; ++i) {
        hash += ((hash * polynomFactor) + (key[i] - 'a')) % module;
    }
    return hash;
}

int getIndex(int hash, int count, int bucketCount)
{
    return (hash + ((count + 1) * count / 2)) % bucketCount;
}

void addElementToHashTable(HashTable* hashTable, char* key, int valueCount, int insertionCount)
{
    int count = 1;
    int hash = getHash(key, hashTable->polynomFactor, hashTable->bucketCount);
    int index = getIndex(hash, count, hashTable->bucketCount);
    while (hashTable->types[index] == USED) {
        if (strcmp(hashTable->hashArray[index]->key, key) == 0) {
            hashTable->hashArray[index]->valueCount++;
            if (hashTable->hashArray[index]->insertionCount < count) {
                hashTable->hashArray[index]->insertionCount = count;
            }
            return;
        }
        ++count;
        index = getIndex(hash, count, hashTable->bucketCount);
    }
    hashTable->hashArray[index] = createHashElement(key);
    hashTable->hashArray[index]->valueCount = valueCount;
    hashTable->hashArray[index]->insertionCount = insertionCount;
    hashTable->types[index] = USED;
    hashTable->elementCount++;
}

void removeHashElement(HashElement* element)
{
    if (element->key != NULL) {
        free(element->key);
    }
    free(element);
}

void expandTable(HashTable* hashTable)
{
    HashElement** oldArray = hashTable->hashArray;
    enum CellType* oldTypes = hashTable->types;
    int oldSize = hashTable->bucketCount;
    int size = hashTable->bucketCount * 2;

    hashTable->hashArray = (HashElement**)malloc(sizeof(HashElement*) * size);
    hashTable->types = (enum CellType*)malloc(sizeof(enum CellType) * size);
    memset(hashTable->hashArray, 0, size * sizeof(HashElement*));
    memset(hashTable->types, EMPTY, size * sizeof(enum CellType));
    hashTable->elementCount = 0;
    hashTable->bucketCount = size;

    for (int i = 0; i < oldSize; ++i) {
        if (oldTypes[i] != USED)
            continue;
        HashElement* element = oldArray[i];
        addElementToHashTable(hashTable, element->key, element->valueCount, element->insertionCount);
        removeHashElement(element);
    }

    free(oldArray);
    free(oldTypes);
}

void addElement(HashTable* hashTable, char* key, int valueCount, int insertionCount)
{
    addElementToHashTable(hashTable, key, valueCount, insertionCount);
    if (getLoadFactor(hashTable) > maxLoadFactor) {
        expandTable(hashTable);
    }

}

bool removeElementByKey(HashTable* hashTable, char* key)
{
    int count = 1;
    int hash = getHash(key, hashTable->polynomFactor, hashTable->bucketCount);
    int currentIndex = getIndex(hash, count, hashTable->bucketCount);
    int index = currentIndex;
    while (hashTable->types[currentIndex] == USED) {
        if (strcmp(hashTable->hashArray[currentIndex]->key, key) == 0) {
            removeHashElement(hashTable->hashArray[currentIndex]);
            hashTable->types[currentIndex] = EMPTY;
            hashTable->elementCount--;
            return true;
        }
        ++count;
        currentIndex = getIndex(hash, count, hashTable->bucketCount);
        if (currentIndex == index) {
            return false;
        }
    }
    return false;
}

void removeHashTable(HashTable* hashTable)
{
    for (int i = 0; i < hashTable->bucketCount; ++i) {
        if (hashTable->types[i]) {
            removeHashElement(hashTable->hashArray[i]);
        }
    }
    free(hashTable->hashArray);
    free(hashTable->types);
    free(hashTable);
}

int getWordCount(HashTable* hashTable)
{
    int wordCount = 0;
    for (int i = 0; i < hashTable->bucketCount; ++i) {
        if (hashTable->types[i] == USED) {
            wordCount += hashTable->hashArray[i]->valueCount;
        }
    }
    return wordCount;
}

void fillTopWordsList(int n, HashTable* hashTable, HashElement** topWords)
{
    for (int i = 0; i < hashTable->bucketCount; ++i) {
        if (hashTable->types[i] == USED) {
            HashElement* currentElement = hashTable->hashArray[i];
            int k = 0;
            while (k < n && topWords[k] != 0 && currentElement->valueCount < topWords[k]->valueCount) {
                ++k; // k is currentElement index in top words list
            }
            while (k < n - 1) { // if k is less than the last index we put currentElement there and move forward all the following elements
                HashElement* temp = topWords[k];
                topWords[k] = currentElement;
                currentElement = temp;
                ++k;
            }
            if (k == n) { // if k is greater than last index currentElement can't be in the list
                continue;
            }
            if (k == n - 1) { // if k is the last index we put currentElement there
                topWords[k] = currentElement;
                continue;
            }
        }
    }
}

void printTopWords(HashTable* hashTable)
{
    if (hashTable->elementCount == 0) {
        printf("Top words list is empty\n");
        return;
    }

    int n = 0;
    printf("Enter the amount of top words to print:\n");
    scanf("%d", &n);

    n = (n > hashTable->elementCount ? hashTable->elementCount : n);
    HashElement** topWords = (HashElement**)malloc(n * sizeof(HashElement*));
    memset(topWords, 0, n * sizeof(HashElement*));

    fillTopWordsList(n, hashTable, topWords);

    printf("%d most common words:\n", n);
    for (int i = 0; i < n; ++i) {
        printf("  %d : %s, %d times\n", i + 1, topWords[i]->key, topWords[i]->valueCount);
    }
    free(topWords);
}

void printMaxInsertionCount(HashTable* hashTable)
{
    int maxCount = 0;
    for (int i = 0; i < hashTable->bucketCount; ++i) {
        if (hashTable->types[i] == USED) {
            HashElement* element = hashTable->hashArray[i];
            if (element->insertionCount > maxCount) {
                maxCount = element->insertionCount;
            }
        }
    }
    printf("2) The maximum number of attempts to insert an element is %d\n", maxCount);
    printf("   Here's the list of words that had this amount of attempts:\n");
    for (int i = 0; i < hashTable->bucketCount; ++i) {
        if (hashTable->types[i] == USED && hashTable->hashArray[i]->insertionCount == maxCount) {
            printf("  - %s\n", hashTable->hashArray[i]->key);
        }
    }
}

int getAverageInsertionCount(HashTable* hashTable)
{
    int sum = 0;
    for (int i = 0; i < hashTable->bucketCount; ++i) {
        if (hashTable->types[i] == USED) {
            sum += hashTable->hashArray[i]->insertionCount;
        }
    }
    return sum / hashTable->elementCount;
}

int getEmptyBucketCount(HashTable* hashTable)
{
    int emptyBucketCount = 0;
    for (int i = 0; i < hashTable->bucketCount; ++i) {
        if (hashTable->types[i] == EMPTY) {
            ++emptyBucketCount;
        }
    }
    return emptyBucketCount;
}

void printHashTableStatistics(HashTable* hashTable)
{
    printf("1) There are %d words in the text\n", getWordCount(hashTable));

    if (hashTable->elementCount > 0) {
        printMaxInsertionCount(hashTable);
        printf("3) The average number of attempts to insert an element is %d\n", getAverageInsertionCount(hashTable));
    } else {
        printf("2) - 3) There were no elements to insert\n");
    }

    printf("4) Load factor is %f\n", getLoadFactor(hashTable));
    printf("5) There are %d empty buckets in the hash table\n", getEmptyBucketCount(hashTable));
    printTopWords(hashTable);
}