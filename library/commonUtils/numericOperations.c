#include "numericOperations.h"

int min(int a, int b)
{
    return a > b ? b : a;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int compare(const void* p1, const void* p2)
{
    int l = *(const int*)p1;
    int r = *(const int*)p2;
    return (l - r);
}