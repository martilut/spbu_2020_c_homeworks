#include "binarySearchTree.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct BinaryTreeNode {
    int value;
    struct BinaryTreeNode* leftChild;
    struct BinaryTreeNode* rightChild;
};

struct BinarySearchTree {
    struct BinaryTreeNode* root;
};

enum Direction { LEFT,
    RIGHT,
    NONE };

BinarySearchTree* createBinaryTree()
{
    BinarySearchTree* binaryTree = (BinarySearchTree*)malloc(sizeof(BinarySearchTree));
    binaryTree->root = NULL;
    return binaryTree;
}

BinaryTreeNode* createBinaryTreeNode(int value)
{
    BinaryTreeNode* binaryTreeNode = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
    binaryTreeNode->value = value;
    binaryTreeNode->leftChild = NULL;
    binaryTreeNode->rightChild = NULL;
    return binaryTreeNode;
}

bool isEmpty(BinarySearchTree* tree)
{
    return (tree->root == NULL);
}

bool isLeaf(BinaryTreeNode* node)
{
    return node->leftChild == NULL && node->rightChild == NULL;
}

bool existsRecursive(int value, BinaryTreeNode* currentNode)
{
    if (value == currentNode->value) {
        return true;
    }
    if (value < currentNode->value && currentNode->leftChild != NULL) {
        return existsRecursive(value, currentNode->leftChild);
    }
    if (value > currentNode->value && currentNode->rightChild != NULL) {
        return existsRecursive(value, currentNode->rightChild);
    }
    return false;
}

bool exists(int value, BinarySearchTree* binaryTree)
{
    if (isEmpty(binaryTree)) {
        return false;
    }
    return existsRecursive(value, binaryTree->root);
}

bool recursiveAddValue(BinaryTreeNode* node, BinaryTreeNode* currentNode)
{
    if (node->value == currentNode->value) {
        return false;
    }
    if (node->value < currentNode->value) {
        if (currentNode->leftChild == NULL) {
            currentNode->leftChild = node;
            return true;
        }
        return recursiveAddValue(node, currentNode->leftChild);
    } else {
        if (currentNode->rightChild == NULL) {
            currentNode->rightChild = node;
            return true;
        }
        return recursiveAddValue(node, currentNode->rightChild);
    }
}

bool addValue(int value, BinarySearchTree* binaryTree)
{
    BinaryTreeNode* node = createBinaryTreeNode(value);
    if (isEmpty(binaryTree)) {
        binaryTree->root = node;
        return true;
    }
    if (recursiveAddValue(node, binaryTree->root)) {
        return true;
    }
    free(node);
    return false;
}

bool changeParent(enum Direction d, BinaryTreeNode* parent, BinarySearchTree* tree, BinaryTreeNode* newNode)
{
    if (d == LEFT) {
        parent->leftChild = newNode;
    }
    if (d == RIGHT) {
        parent->rightChild = newNode;
    }
    if (d == NONE) {
        tree->root = newNode;
    }
    return true;
}

BinaryTreeNode* getParentMaxNode(BinaryTreeNode* node)
{
    while (node->rightChild->rightChild != NULL) {
        node = node->rightChild;
    }
    return node;
}

bool recursiveRemoveValue(BinarySearchTree* binaryTree, BinaryTreeNode* node, int value, BinaryTreeNode* parent, enum Direction d)
{
    if (node->value == value) {
        if (isLeaf(node)) {
            changeParent(d, parent, binaryTree, NULL);
        }
        if (node->leftChild != NULL && node->rightChild == NULL) {
            changeParent(d, parent, binaryTree, node->leftChild);
        }
        if (node->leftChild == NULL && node->rightChild != NULL) {
            changeParent(d, parent, binaryTree, node->rightChild);
        }
        if (node->leftChild != NULL && node->rightChild != NULL) {
            if (node->leftChild->rightChild == NULL) {
                changeParent(d, parent, binaryTree, node->leftChild);
                node->leftChild->rightChild = node->rightChild;
            } else {
                BinaryTreeNode* parentMaxNode = getParentMaxNode(node->leftChild);
                BinaryTreeNode* maxNode = parentMaxNode->rightChild;
                changeParent(d, parent, binaryTree, maxNode);
                changeParent(RIGHT, parentMaxNode, binaryTree, maxNode->leftChild);
                maxNode->leftChild = node->leftChild;
                maxNode->rightChild = node->rightChild;
            }
        }
        free(node);
        return true;
    }
    if (node->value > value && node->leftChild != NULL) {
        return recursiveRemoveValue(binaryTree, node->leftChild, value, node, LEFT);
    }
    if (node->value < value && node->rightChild != NULL) {
        return recursiveRemoveValue(binaryTree, node->rightChild, value, node, RIGHT);
    }
    return false;
}

bool removeValue(int value, BinarySearchTree* tree)
{
    if (isEmpty(tree)) {
        return false;
    }
    return recursiveRemoveValue(tree, tree->root, value, NULL, NONE);
}

void recursiveIncreasing(BinaryTreeNode* node)
{
    if (node != NULL) {
        recursiveIncreasing(node->leftChild);
        printf("%d ", node->value);
        recursiveIncreasing(node->rightChild);
    }
}

void printIncreasingValues(BinarySearchTree* binaryTree)
{
    return recursiveIncreasing(binaryTree->root);
}

void recursiveDecreasing(BinaryTreeNode* node)
{
    if (node != NULL) {
        recursiveDecreasing(node->rightChild);
        printf("%d ", node->value);
        recursiveDecreasing(node->leftChild);
    }
}

void printDecreasingValues(BinarySearchTree* binaryTree)
{
    return recursiveDecreasing(binaryTree->root);
}

void recursiveStraight(BinaryTreeNode* node)
{
    if (node != NULL) {
        printf(" (");
        printf("%d", node->value);
        recursiveStraight(node->leftChild);
        recursiveStraight(node->rightChild);
        printf(")");
    } else {
        printf(" null");
    }
}

void printStraightOrder(BinarySearchTree* binaryTree)
{
    return recursiveStraight(binaryTree->root);
}

void recursiveRemoveBinaryTree(BinarySearchTree* binaryTree, BinaryTreeNode* node, BinaryTreeNode* parent, enum Direction d)
{
    if (binaryTree->root == NULL) {
        return;
    }
    if (isLeaf(node)) {
        changeParent(d, parent, binaryTree, NULL);
        free(node);
    } else {
        if (node->leftChild != NULL) {
            recursiveRemoveBinaryTree(binaryTree, node->leftChild, node, LEFT);
        }
        if (node->rightChild != NULL) {
            recursiveRemoveBinaryTree(binaryTree, node->rightChild, node, RIGHT);
        }
    }
}

void removeBinaryTree(BinarySearchTree* binaryTree)
{
    recursiveRemoveBinaryTree(binaryTree, binaryTree->root, NULL, NONE);
    free(binaryTree);
}
