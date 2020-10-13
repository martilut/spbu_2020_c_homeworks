#include "complex_number.h"
#include <stdio.h>

struct ComplexNumber {
    float RealPart;
    float ImaginaryPart;
};

ComplexNumber sumComplexNumbers(ComplexNumber* x, ComplexNumber* y)
{
    ComplexNumber answer = {0, 0};
    answer.RealPart = x->RealPart + y->RealPart;
    answer.ImaginaryPart = x->ImaginaryPart + y->ImaginaryPart;
    return answer;
}

ComplexNumber diffComplexNumbers(ComplexNumber* x, ComplexNumber* y)
{
    ComplexNumber answer = {0, 0};
    answer.RealPart = x->RealPart - y->RealPart;
    answer.ImaginaryPart = x->ImaginaryPart - y->ImaginaryPart;
    return answer;
}

void printComplexNumber(ComplexNumber* number)
{
    printf("%f + %fi", number->RealPart, number->ImaginaryPart);
}