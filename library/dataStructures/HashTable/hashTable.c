#include "hashTable.h"
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
    element->key = (char*)malloc(sizeof(char) * keySize);
    strcpy(element->key, key);
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
    memset(hashTable->types, EMPTY, size * sizeof(enum CellType));
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
    int length = strlen(key);
    for (int i = 0; i < length; ++i) {
        hash += ((hash * polynomFactor) + (key[i] - 'A')) % module;
    }
    return hash;
}

int getIndex(int hash, int count, int bucketCount)
{
    return (hash + ((count + 1) * count / 2)) % bucketCount;
}

int getValueCount(HashTable* hashTable, char* key)
{
    int count = 1;
    int hash = getHash(key, hashTable->polynomFactor, hashTable->bucketCount);
    int index = getIndex(hash, count, hashTable->bucketCount);
    while (hashTable->types[index] == USED) {
        if (index == hash) {
            return -1;
        }
        if (strcmp(hashTable->hashArray[index]->key, key) == 0) {
            return hashTable->hashArray[index]->valueCount;
        }
        index = getIndex(hash, count, hashTable->bucketCount);
    }
    return 0;
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
        index = getIndex(hash, count, hashTable->bucketCount);
        ++count;
    }
    hashTable->hashArray[index] = createHashElement(key);
    hashTable->hashArray[index]->valueCount = valueCount;
    hashTable->hashArray[index]->insertionCount = insertionCount;
    hashTable->types[index] = USED;
    hashTable->elementCount++;
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