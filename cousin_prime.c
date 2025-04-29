#include <stdio.h>

int isPrime(int x)
{
    int i;
    for (i = 2; i <= x / 2; i++)
    {
        if (x % i == 0)
            return 0;
    }
    return 1;
}

int main()
{
    int n1, n2;

    printf("Enter two numbers: ");

    if (scanf("%d %d", &n1, &n2) != 2)
    {
        printf("Invalid input. Please enter two valid integers.\n");
        return 1;
    }

    if (n1 <= 0 || n2 <= 0)
    {
        printf("Invalid input. Please enter two positive numbers.\n");
        return 1;
    }
    int i;
    if (isPrime(n1) && isPrime(n1 + 4))
    {
        if (n2 - n1 == 4)
        {
            printf("%d & %d is a cousin prime no", n1,n2);
        }
        else
        {
            printf("Both are prime numbers but they differ by %d", n2 - n1);
        }
    }
    else
    {
        printf("Both numbers are non-prime and they differ by %d", n2 - n1);
    }
    return 0;
}
