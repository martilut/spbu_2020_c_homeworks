#ifndef SPBU_2020_C_HOMEWORKS_BINARYSEARCHTREE_H
#define SPBU_2020_C_HOMEWORKS_BINARYSEARCHTREE_H
#include <stdbool.h>

typedef struct BinarySearchTree BinarySearchTree;

BinarySearchTree* createBinaryTree();
bool exists(int value, BinarySearchTree* binaryTree);
bool addValue(int value, BinarySearchTree* binaryTree);
bool removeValue(int value, BinarySearchTree *tree);
void printIncreasingValues(BinarySearchTree* binaryTree);
void printDecreasingValues(BinarySearchTree* binaryTree);
void printStraightOrder(BinarySearchTree* binaryTree);
void removeBinaryTree(BinarySearchTree* binaryTree);

#endif // SPBU_2020_C_HOMEWORKS_BINARYSEARCHTREE_H
