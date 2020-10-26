#include "../library/dataStructures/BinarySearchTree/binarySearchTree.h"
#include <stdio.h>

int main()
{
    int number = 4;
    int array[] = { 5, 3, 7, 2, 4, 6, 8, 1, 9 };
    BinarySearchTree* tree = createBinaryTree();

    for (int i = 0; i < 9; ++i) {
        addValue(array[i], tree);
    }

    if (exists(number, tree)) {
        printf("%d is in the tree\n", number);
    } else {
        printf("%d is not in the tree\n", number);
    }

    printIncreasingValues(tree);
    printf("\n");
    printDecreasingValues(tree);
    printf("\n");
    printStraightOrder(tree);
    printf("\n");

    removeValue(3, tree);
    printStraightOrder(tree);

    removeBinaryTree(tree);

    return 0;
}
