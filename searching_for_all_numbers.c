#include <stdio.h>

// Function to find the maximum element in an array
int max(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

// Function to find the minimum element in an array
int min(int arr[], int n)
{
    int min = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    return min;
}

int main()
{
    int n, i, j;

    // Input the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    // Input the elements of the array
    printf("Enter %d elements of the array:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int maximum = max(arr, n);
    int minimum = min(arr, n);

    for (j = minimum; j <= maximum; j++)
    {
        int found = 0;
        for (i = 0; i < n; i++)
        {
            if (arr[i] == j)
            {
                found = 1;
                break;
            }
        }
        if (!found)
        {
            printf("%d ", j);
        }
    }

    return 0;
}
