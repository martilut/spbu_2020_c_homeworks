#include <math.h>
#include <stdio.h>

void reverseAdditionalCode(int binaryArray[])
{
    for (int i = 0; i < 32; ++ i) {
        binaryArray[i] = (binaryArray[i] == 1 ? 0 : 1);
    }
}

void decimalToBinary(int number, int binaryArray[])
{
    for (int i = 31; i >= 0; --i) {
        int bit = number >> i;
        binaryArray[31 - i] = (bit & 1 ? 1 : 0);
    }
}

int binaryToDecimal(int binaryArray[])
{
    int decimal = 0;
    if (binaryArray[0] == 1) {
        reverseAdditionalCode(binaryArray);
        decimal++;
    }
    for (int i = 0; i < 32; ++i) {
        if (binaryArray[31 - i] == 1) {
            decimal += exp2(i);
        }
    }
    return decimal;
}

void printBinaryArray(int binaryArray[])
{
    for (int i = 0; i < 32; ++i) {
        printf("%d", binaryArray[i]);
    }
}

void getBinarySum(int binaryArray1[], int binaryArray2[], int binaryResult[])
{
    for (int i = 31; i >= 0; --i) {
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

    int binaryArray1[32] = { 0 };
    decimalToBinary(number1, binaryArray1);
    printf("Number %d is ", number1);
    printBinaryArray(binaryArray1);
    printf("\n");

    int binaryArray2[32] = { 0 };
    decimalToBinary(number2, binaryArray2);
    printf("Number %d is ", number2);
    printBinaryArray(binaryArray2);
    printf("\n");

    int binarySumArray[32] = { 0 };
    getBinarySum(binaryArray1, binaryArray2, binarySumArray);
    printf("Binary sum is ");
    printBinaryArray(binarySumArray);
    printf("\n");

    printf("Decimal sum is %d", binaryToDecimal(binarySumArray));

    return 0;
}