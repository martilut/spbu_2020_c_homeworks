#define BITS_PER_INT sizeof(int) * 8
#include <stdio.h>

void invertBits(int binaryArray[])
{
    for (int i = 0; i < BITS_PER_INT; ++i) {
        binaryArray[i] = 1 - binaryArray[i];
    }
}

void decimalToBinary(int number, int binaryArray[])
{
    for (int i = BITS_PER_INT - 1; i >= 0; --i) {
        int bit = number >> i;
        binaryArray[BITS_PER_INT - 1 - i] = bit & 1;
    }
}

int binaryToDecimal(int binaryArray[])
{
    int sign = 1;
    int decimal = 0;
    if (binaryArray[0] == 1) {
        invertBits(binaryArray);
        decimal++;
        sign = -1;
    }
    for (int i = 0; i < BITS_PER_INT; ++i) {
        if (binaryArray[BITS_PER_INT - 1 - i] == 1) {
            decimal += 1 << i;
        }
    }
    return decimal * sign;
}

void printBinaryArray(int binaryArray[])
{
    for (int i = 0; i < BITS_PER_INT; ++i) {
        printf("%d", binaryArray[i]);
    }
}

void getBinarySum(int binaryArray1[], int binaryArray2[], int binaryResult[])
{
    for (int i = BITS_PER_INT - 1; i >= 0; --i) {
        if (binaryResult[i] + binaryArray1[i] + binaryArray2[i] > 1) {
            binaryResult[i - 1] = 1;
        }
        binaryResult[i] = (binaryResult[i] + binaryArray1[i] + binaryArray2[i]) % 2;
    }
}

int main()
{
    int number1 = 0;
    int number2 = 0;
    printf("Enter your numbers:\n");
    scanf("%d %d", &number1, &number2);

    int binaryArray1[BITS_PER_INT] = { 0 };
    decimalToBinary(number1, binaryArray1);
    printf("Number %d is ", number1);
    printBinaryArray(binaryArray1);
    printf("\n");

    int binaryArray2[BITS_PER_INT] = { 0 };
    decimalToBinary(number2, binaryArray2);
    printf("Number %d is ", number2);
    printBinaryArray(binaryArray2);
    printf("\n");

    int binarySumArray[BITS_PER_INT] = { 0 };
    getBinarySum(binaryArray1, binaryArray2, binarySumArray);
    printf("Binary sum is ");
    printBinaryArray(binarySumArray);
    printf("\n");

    printf("Decimal sum is %d", binaryToDecimal(binarySumArray));

    return 0;
}