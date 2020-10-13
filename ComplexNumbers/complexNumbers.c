#include "complexNumbers.h"
#include <stdio.h>
#include <stdlib.h>

struct ComplexNumber {
    float RealPart;
    float ImaginaryPart;
};

ComplexNumber* createComplexNumber(float realPart, float imaginaryPart)
{
    ComplexNumber* number = (ComplexNumber*)malloc(sizeof(ComplexNumber));
    number->RealPart = realPart;
    number->ImaginaryPart = imaginaryPart;
    return number;
}

ComplexNumber sumComplexNumbers(ComplexNumber* x, ComplexNumber* y)
{
    ComplexNumber answer = { 0, 0 };
    answer.RealPart = x->RealPart + y->RealPart;
    answer.ImaginaryPart = x->ImaginaryPart + y->ImaginaryPart;
    return answer;
}

ComplexNumber diffComplexNumbers(ComplexNumber* x, ComplexNumber* y)
{
    ComplexNumber answer = { 0, 0 };
    answer.RealPart = x->RealPart - y->RealPart;
    answer.ImaginaryPart = x->ImaginaryPart - y->ImaginaryPart;
    return answer;
}

ComplexNumber multiplyComplexNumbers(ComplexNumber* x, ComplexNumber* y)
{
    ComplexNumber answer = { 0, 0 };
    answer.RealPart = x->RealPart * y->RealPart - x->ImaginaryPart + y->ImaginaryPart;
    answer.ImaginaryPart = x->RealPart * y->ImaginaryPart + x->ImaginaryPart * y->RealPart;
    return answer;
}

ComplexNumber divComplexNumbers(ComplexNumber* x, ComplexNumber* y)
{
    ComplexNumber answer = { 0, 0 };
    answer.RealPart = (x->RealPart * y->RealPart + x->ImaginaryPart * y->ImaginaryPart) / (y->RealPart * y->RealPart + y->ImaginaryPart * y->ImaginaryPart);
    answer.ImaginaryPart = (x->ImaginaryPart * y->realPart - y->ImaginaryPart * x->realPart) / (y->RealPart * y->RealPart + y->ImaginaryPart * y->ImaginaryPart);
    return answer;
}

void printComplexNumber(ComplexNumber* number)
{
    printf("%f + %fi", number->RealPart, number->ImaginaryPart);
}
