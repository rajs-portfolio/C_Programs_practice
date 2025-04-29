#include<stdio.h>
int binarySearch(int *,int,int);

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
	printf("Enter the element to search : ");
	scanf("%d",&x);
	bubble(a,n);
	printf("The sorted array is : ");
	for(i=0;i<n;i++)
        printf("%-4d",a[i]);
	p=binarySearch(a,x,n);
	if(p==-1)
		printf("NOT FOUND");
	else
        printf("FOUND in index %d",p);
	return 0;
}
int binarySearch(int *a, int item,int n)
{
	int l,r,m;
	l=0;
	r=n-1;
	m=(l+r)/2;
	while(l<=r)
	{
		if(item==a[m])
			return m;
		if(item > a[m])
			l=m+1;
		else
			r=m-1;
		m=(l+r)/2;
	}
	return -1;
}
