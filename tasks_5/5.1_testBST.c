#include "../library/dataStructures/BinarySearchTree/binarySearchTree.h"
#include <stdio.h>

int main()
{
    int length = 0;
    int value = 0;

    BinarySearchTree* tree = createBinaryTree();

    printf("How many numbers do you have?\n");
    scanf("%d", &length);

    if (length > 0) {
        printf("Enter numbers to add in the tree:\n");
        for (int i = 0; i < length; ++i) {
            scanf("%d", &value);
            addValue(value, tree);
        }
    }

    printIncreasingValues(tree);
    printDecreasingValues(tree);
    printStraightOrder(tree);

    // addValue check
    int number = 0;
    printf("Enter a number to add in the tree:\n");
    scanf("%d", &number);
    addValue(number, tree);

    // ifExist check
    printf("Enter a number to find in the tree:\n");
    scanf("%d", &number);
    if (exists(number, tree)) {
        printf("%d is in the tree\n", number);
    } else {
        printf("%d is not in the tree\n", number);
    }

    // removeValue check
    printf("Enter a number to remove:\n");
    scanf("%d", &number);
    removeValue(number, tree);
    printStraightOrder(tree);

    removeBinaryTree(tree);

    return 0;
}
