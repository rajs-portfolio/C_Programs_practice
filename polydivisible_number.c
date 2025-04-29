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
    int temp = n;
    int length = 0;
    if (n == 0)
    {
        length = 1;
    }
    else
    {
        while (n > 0)
        {
            n /= 10;
            length++;
        }
    }
    n=temp;
    int x = n;
    int i,j,k;
    while (x >= 10)
    {
        x /= 10;
    }
    if (x!=0)
    {
        
        for (i =2; i <= length; i++)
        {
            for (j = 10; i <= length; j = j + 10)
            {
                for (k = 2; i <= length; k++)
                {
                    if (i % k == 0)
                    {
                        printf("%d, the number is a polydivisible", temp);
                        return 1;
                    }
                    else
                    {
                        printf("%d, the number is not a polydivisible number", temp);
                        return 1;
                    }
                }
            }
        }
    }
    else
    {
        printf("The 1st digit of the number is 0, so it can't be polydivisble");
    }
    return 0;
}