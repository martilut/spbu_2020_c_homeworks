#include <stdio.h>

int recursiveFactorial(int k)
{
    if (k == 1)
        return 1;
    return k * recursiveFactorial(k - 1);
};

int iterativeFactorial(int k)
{
    int answer = 1;
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

    if (!n) {
        printf("1");
        return 0;
    }

    printf("%d\n", recursiveFactorial(n));
    printf("%d", iterativeFactorial(n));
}