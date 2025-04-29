#include<stdio.h>
#define MAX 10
void main ()
{
    int arr[3][3],sum1=0,sumr=0,i,j;
    printf ("Enter the elements: \n");
    for (i=0;i<3;i++)
    {
        for (j=0;j<3;j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    for (i=0;i<3;i++)
    {
        for (j=0;j<3;j++)
        {
            if(i==j)
            {
                sum1+= arr[i][j];
            }
            if (i+j==2)
            {
                sumr+=arr[i][j];
            }
        }
    }
    printf ("Right diagonal sum= %d \n", sumr);
    printf ("Left diagonal sum= %d \n", sum1);
}
