#include "numericOperations.h"

int min(int a, int b)
{
    return a > b ? b : a;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int compare(const int* i, const int* j)
{
    return *i - *j;
}