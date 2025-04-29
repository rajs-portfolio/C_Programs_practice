#include<stdio.h>
#include<conio.h>
int binary_search(int *,int,int,int);
void bubble(int *p,int n)
{
	int i,j,k;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(p[j]>p[j+1])
			{
				k=p[j];
				p[j]=p[j+1];
				p[j+1]=k;
			}
		}
	}
}
int main()
{
	int n,i,p,x;
	printf("Enter size of the array : ");
	scanf("%d",&n);
	int a[n];
	printf("Enter %d elements ",n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Enter the element to be searched : ");
	scanf("%d",&x);
	bubble(a,n);
	printf("The sorted array is : ");
	for(i=0;i<n;i++)
        printf("%-4d",a[i]);
	p=binary_search(a,0,n-1,x);
	if(p==-1)
		printf("NOT FOUND");
	else
		printf("FOUND in index %d",p);
	return 0;
}
int binary_search(int *a, int l,int r, int x)
{
	if(l<=r)
	{
		int m=(l+r)/2;
		if(a[m]==x)
			return m;
		if(x<a[m])
			return binary_search(a,l,m-1,x);
		else
			return binary_search(a,m+1,r,x);
	}
	return -1;
}
