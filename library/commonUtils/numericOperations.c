#include "numericOperations.h"

int min(int a, int b)
{
    return a > b ? b : a;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int compare(const void *i, const void *j)
{
  return *(int *)i - *(int *)j;
}