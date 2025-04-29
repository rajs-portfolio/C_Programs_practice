#include<stdio.h>
void selectionSort(int *, int);//Prototype
int main()
{
	int n,i;
	printf("Enter Size of the array ");
	scanf("%d",&n);
	int a[n];
	printf("Enter %d numbers ",n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	selectionSort(a,n);
	printf("The sorted array : ");
	for(i=0;i<n;i++)
		printf("%d  ",a[i]);
	return 0;
}
void selectionSort(int *a, int n)
{
	int i,j,min,t;
	for(i=0; i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j] < a[min])
				min=j;
		}
		if(min != i)
		{
			t=a[i];
			a[i]=a[min];
			a[min]=t;
		}
	}
}
