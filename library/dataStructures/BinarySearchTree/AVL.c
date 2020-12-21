#include "binarySearchTree.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct BinaryTreeNode {
    int value;
    int height;
    int valueCount;
    struct BinaryTreeNode* leftChild;
    struct BinaryTreeNode* rightChild;
} BinaryTreeNode;

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
    binaryTreeNode->height = 0;
    binaryTreeNode->valueCount = 1;
    binaryTreeNode->leftChild = NULL;
    binaryTreeNode->rightChild = NULL;
    return binaryTreeNode;
}

int getHeight(BinaryTreeNode* node)
{
    return node == NULL ? 0 : node->height;
}

int getBalanceFactor(BinaryTreeNode* node)
{
    return getHeight(node->rightChild) - getHeight(node->leftChild);
}

void updateHeight(BinaryTreeNode* node)
{
    int heightLeft = getHeight(node->leftChild);
    int heightRight = getHeight(node->rightChild);
    node->height = (heightLeft >= heightRight ? heightLeft : heightRight) + 1;
}

BinaryTreeNode* rotateRight(BinaryTreeNode* root)
{
    BinaryTreeNode* pivot = root->leftChild;
    root->leftChild = pivot->rightChild;
    pivot->rightChild = root;
    updateHeight(root);
    updateHeight(pivot);
    return pivot;
}

BinaryTreeNode* rotateLeft(BinaryTreeNode* root)
{
    BinaryTreeNode* pivot = root->rightChild;
    root->rightChild = pivot->leftChild;
    pivot->leftChild = root;
    updateHeight(root);
    updateHeight(pivot);
    return pivot;
}

BinaryTreeNode* balanceBranch(BinaryTreeNode* root)
{
    if (getBalanceFactor(root) == 2) {
        if (getBalanceFactor(root->rightChild) < 0) {
            root->rightChild = rotateRight(root->rightChild);
        }
        return rotateLeft(root);
    }
    if (getBalanceFactor(root) == -2) {
        if (getBalanceFactor(root->leftChild) > 0) {
            root->leftChild = rotateLeft(root->leftChild);
        }
        return rotateRight(root);
    }
    return root;
}

bool isEmpty(BinarySearchTree* tree)
{
    return (tree->root == NULL);
}

bool isLeaf(BinaryTreeNode* node)
{
    return node->leftChild == NULL && node->rightChild == NULL;
}

BinaryTreeNode* balanceTree(BinaryTreeNode* currentNode)
{
    if (isLeaf(currentNode)) {
        updateHeight(currentNode);
        return currentNode;
    }
    if (currentNode->leftChild != NULL) {
        currentNode->leftChild = balanceTree(currentNode->leftChild);
    }
    if (currentNode->rightChild != NULL) {
        currentNode->rightChild = balanceTree(currentNode->rightChild);
    }
    updateHeight(currentNode);
    return balanceBranch(currentNode);
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

bool recursiveAddValue(int value, BinaryTreeNode* currentNode)
{
    if (value == currentNode->value) {
        (currentNode->valueCount)++;
        return false;
    }
    if (value < currentNode->value) {
        if (currentNode->leftChild == NULL) {
            currentNode->leftChild = createBinaryTreeNode(value);
            return true;
        }
        return recursiveAddValue(value, currentNode->leftChild);
    } else {
        if (currentNode->rightChild == NULL) {
            currentNode->rightChild = createBinaryTreeNode(value);
            return true;
        }
        return recursiveAddValue(value, currentNode->rightChild);
    }
}

bool addValue(int value, BinarySearchTree* binaryTree)
{
    if (isEmpty(binaryTree)) {
        binaryTree->root = createBinaryTreeNode(value);
        updateHeight(binaryTree->root);
        return true;
    }
    if (recursiveAddValue(value, binaryTree->root)) {
        binaryTree->root = balanceTree(binaryTree->root);
        return true;
    }
    return false;
}

bool changeParent(BinarySearchTree* tree, BinaryTreeNode* parent, BinaryTreeNode* newNode, enum Direction direction)
{
    if (direction == LEFT) {
        parent->leftChild = newNode;
    }
    if (direction == RIGHT) {
        parent->rightChild = newNode;
    }
    if (direction == NONE) {
        tree->root = newNode;
    }
    return true;
}

BinaryTreeNode* getParentOfMaxNode(BinaryTreeNode* node)
{
    while (node->rightChild->rightChild != NULL) {
        node = node->rightChild;
    }
    return node;
}

bool recursiveRemoveValue(int value, BinarySearchTree* binaryTree, BinaryTreeNode* node, BinaryTreeNode* parent, enum Direction direction)
{
    if (value == node->value) {
        if (isLeaf(node)) {
            changeParent(binaryTree, parent, NULL, direction);
        }
        if (node->leftChild != NULL && node->rightChild == NULL) {
            changeParent(binaryTree, parent, node->leftChild, direction);
        }
        if (node->leftChild == NULL && node->rightChild != NULL) {
            changeParent(binaryTree, parent, node->rightChild, direction);
        }
        if (node->leftChild != NULL && node->rightChild != NULL) {
            if (node->leftChild->rightChild == NULL) {
                changeParent(binaryTree, parent, node->leftChild, direction);
                node->leftChild->rightChild = node->rightChild;
            } else {
                BinaryTreeNode* parentOfMaxNode = getParentOfMaxNode(node->leftChild);
                BinaryTreeNode* maxNode = parentOfMaxNode->rightChild;
                changeParent(binaryTree, parent, maxNode, direction);
                changeParent(binaryTree, parentOfMaxNode, maxNode->leftChild, RIGHT);
                maxNode->leftChild = node->leftChild;
                maxNode->rightChild = node->rightChild;
            }
        }
        free(node);
        return true;
    }
    if (node->value > value && node->leftChild != NULL) {
        return recursiveRemoveValue(value, binaryTree, node->leftChild, node, LEFT);
    }
    if (node->value < value && node->rightChild != NULL) {
        return recursiveRemoveValue(value, binaryTree, node->rightChild, node, RIGHT);
    }
    return false;
}

bool removeValue(int value, BinarySearchTree* tree)
{
    if (isEmpty(tree)) {
        return false;
    }
    if (recursiveRemoveValue(value, tree, tree->root, NULL, NONE)) {
        tree->root = balanceTree(tree->root);
        return true;
    }
    return false;
}

void recursiveIncreasing(BinaryTreeNode* node)
{
    if (node != NULL) {
        recursiveIncreasing(node->leftChild);
        printf("Number: %d Value count: %d\n", node->value, node->valueCount);
        recursiveIncreasing(node->rightChild);
    }
}

void printIncreasingValues(BinarySearchTree* binaryTree)
{
    if (isEmpty(binaryTree)) {
        printf("Binary tree is empty");
    } else {
        recursiveIncreasing(binaryTree->root);
    }
    printf("\n");
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
    if (isEmpty(binaryTree)) {
        printf("Binary tree is empty");
    } else {
        recursiveDecreasing(binaryTree->root);
    }
    printf("\n");
}

void recursiveStraight(BinaryTreeNode* node)
{
    if (node != NULL) {
        printf("(%d ", node->value);
        recursiveStraight(node->leftChild);
        recursiveStraight(node->rightChild);
        printf(")");
    } else {
        printf(" null");
    }
}

void printStraightOrder(BinarySearchTree* binaryTree)
{
    if (isEmpty(binaryTree)) {
        printf("( )");
    } else {
        recursiveStraight(binaryTree->root);
    }
    printf("\n");
}

void recursiveRemoveBinaryTree(BinarySearchTree* binaryTree, BinaryTreeNode* node)
{
    if (binaryTree->root == NULL) {
        return;
    }
    BinaryTreeNode* leftChild = node->leftChild;
    BinaryTreeNode* rightChild = node->rightChild;
    free(node);
    if (leftChild != NULL) {
        recursiveRemoveBinaryTree(binaryTree, leftChild);
    }
    if (rightChild != NULL) {
        recursiveRemoveBinaryTree(binaryTree, rightChild);
    }
}

void removeBinaryTree(BinarySearchTree* binaryTree)
{
    recursiveRemoveBinaryTree(binaryTree, binaryTree->root);
    free(binaryTree);
}
