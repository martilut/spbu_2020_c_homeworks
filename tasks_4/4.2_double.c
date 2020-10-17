#include <stdio.h>
#include <math.h>

union doubleBin {
  double value;
  unsigned char bytes[8];
};

int exponentToInt(int array[])
{
    int exponent = 0;
    for (int i = 1; i <= 11; ++i) {
        if (array[i] == 1) {
            exponent += exp2(10 - i + 1);
        }
    }
    return exponent;
}

double mantissaToDouble(int array[])
{
    double mantissa = 0;
    for (int i = 12; i < 64; ++i) {
        if (array[i] == 1) {
            mantissa += (1 / exp2(i - 11));
        }
    }
    return mantissa;
}

int main()
{
    union doubleBin number;
    printf("Enter your number:\n");
    scanf("%lf", &number.value);

    int binaryArray[64] = { 0 };
    int counter = 0;
    for (int i = 0; i < 8; ++i) {
        counter = 8 * (i + 1);
        for (unsigned int j = 1u << 7u; j; j >>= 1u) {
            binaryArray[64 - counter] = ((j & number.bytes[i]) > 0 ? 1 : 0);
            counter--;
        }
    }

    int exponent = exponentToInt(binaryArray);
    double mantissa = mantissaToDouble(binaryArray);
    if (exponent == 0) {
        printf("Zero has no exponential form");
    } else {
        printf("Exponential form is %c%.10lf * 2^{%d}",binaryArray[0] ? '-' : '+', 1 + mantissa, exponent - 1023);
    }
    return 0;
}
