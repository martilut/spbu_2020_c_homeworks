#ifndef SPBU_2020_C_HOMEWORKS_HASHTABLE_H
#define SPBU_2020_C_HOMEWORKS_HASHTABLE_H
#include <stdbool.h>

typedef struct HashTable HashTable;
typedef struct HashElement HashElement;

HashElement* createHashElement(char* key);
HashTable* createHashTable(int polynomFactor);
void addElement(HashTable* hashTable, char* key, int valueCount, int insertionCount);
void removeHashTable(HashTable* hashTable);
void printHashTableStatistics(HashTable* hashTable);
bool removeElementByKey(HashTable* hashTable, char* key);

#endif // SPBU_2020_C_HOMEWORKS_HASHTABLE_H
