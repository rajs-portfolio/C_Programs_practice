#include <stdio.h>
int main()
{
    int n, i, a, low, high, mid;
    printf("Enter the number of elements: \n");
    scanf("%d", &n);
    int array[n];
    printf("Enter the elements in sorted order: \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
    printf("Enter the value to search: \n");
    scanf("%d", &a);
    low = 0;
    high = n - 1;
    mid = (low + high) / 2;
    while (low <= high)
    {
        if (array[mid] < a)
            low = mid + 1;
        else if (array[mid] == a)
        {
            printf("%d found at %d", a, mid);
            break;
        }
        else
        {
            high = mid - 1;
            mid = (low + high) / 2;
        }
    }
    if (low > high)
    {
        printf("%d is not present in the array ", a);
        return 0;
    }
}