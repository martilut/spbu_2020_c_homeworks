#ifndef SPBU_2020_C_HOMEWORKS_HASHTABLE_H
#define SPBU_2020_C_HOMEWORKS_HASHTABLE_H

typedef struct HashTable HashTable;
typedef struct HashElement HashElement;

HashElement* createHashElement(char* key);
HashTable* createHashTable(int polynomFactor);
float getLoadFactor(HashTable* table);
int getHash(char* key, int polynomFactor, int module);
void addElement(HashTable* hashTable, char* key, int valueCount, int insertionCount);
int getValueCount(HashTable* hashTable, char* key);

#endif // SPBU_2020_C_HOMEWORKS_HASHTABLE_H
