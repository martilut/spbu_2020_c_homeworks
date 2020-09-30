#include <stdio.h>

long long recursiveFactorial(int k)
{
    if (k == 0)
        return 1;
    return k * recursiveFactorial(k - 1);
};

long long iterativeFactorial(int k)
{
    long long answer = 1;
    while (k) {
        answer *= k;
        k--;
    }
    return answer;
};

int main()
{
    int n;

    printf("Enter you number:\n");
    scanf("%d", &n);

    printf("%lld\n", recursiveFactorial(n));
    printf("%lld", iterativeFactorial(n));
    return 0;
}