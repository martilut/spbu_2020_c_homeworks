#ifndef SPBU_2020_C_HOMEWORKS_COMPLEXNUMBERS_H
#define SPBU_2020_C_HOMEWORKS_COMPLEXNUMBERS_H

typedef struct ComplexNumber ComplexNumber;

ComplexNumber sumComplexNumbers(ComplexNumber* x, ComplexNumber* y);
ComplexNumber diffComplexNumbers(ComplexNumber* x, ComplexNumber* y);
ComplexNumber multiplyComplexNumbers(ComplexNumber* x, ComplexNumber* y);
void printComplexNumber(ComplexNumber* number);

#endif // SPBU_2020_C_HOMEWORKS_COMPLEXNUMBERS_H
