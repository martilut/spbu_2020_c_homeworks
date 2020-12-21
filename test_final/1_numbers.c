#include "../library/dataStructures/BinarySearchTree/AVL.h"
#include <stdio.h>

int main()
{
    BinarySearchTree* tree = createBinaryTree();

    int value = -1;

    printf("Enter numbers:\n");
    while (value != 0) {
        scanf("%d", &value);
        if (value != 0) {
            addValue(value, tree);
        }
    }

    printIncreasingValues(tree);
    removeBinaryTree(tree);

    return 0;
}
