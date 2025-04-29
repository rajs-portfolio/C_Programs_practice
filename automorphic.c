#include <stdio.h>

int main()
{
    int n;
    printf("Enter a number: ");
    if (scanf("%d", &n) != 1)
    {
        printf("Invalid input. Please enter a valid integer.\n");
        return 1;
    }

    if (n <= 0)
    {
        printf("Invalid input. Please enter a positive number.\n");
        return 1;
    }
    int divisor=1;
    int original = n;
    int sq = n * n;
    int temp = n;
    int length = 0;
    if (n == 0)
    {
        length = 1;
    }
    else
    {
        while (temp > 0)
        {
            temp /= 10;
            length++;
        }
    }
    for (int j = 0; j < length; j++)
    {
        divisor *= 10;
    }
    if (sq % divisor == original)
    {
        printf("It is a automorphic number");
    }
    else
    {
        printf("It is not a automorphic number");
    }
    return 0;
}