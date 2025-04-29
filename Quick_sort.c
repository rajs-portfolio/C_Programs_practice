#include<stdio.h>

void quick(int *,int,int);//Base Address, lowest index, Highest Index
int main()
{
	int i,n;
	printf("How many numbers ");
	scanf("%d",&n);
	int a[n];
	printf("Enter %d numbers ",n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	quick(a,0,n-1);
	printf("The numbers in ascending order are ");
	for(i=0;i<n;i++ )
		printf("%d ",a[i]);
	return 0;
}
void quick(int a[],int low,int up)
{
	int l,r,p,t;
	l=low;
	r=up;
	p=low;
	if(low>=up)
		return;
	while(1)
	{
		while(a[r]>=a[p] && p!=r)
			r--;
		if(p==r)
			break;
		if(a[r]<a[p])
		{
			t=a[p];
			a[p]=a[r];
			a[r]=t;
			p=r;
		}
		while(a[l]<=a[p] && l!=p)
			l++;
		if(p==l)
			break;
		if(a[l]>a[p])
		{
			t=a[p];
			a[p]=a[l];
			a[l]=t;
			p=l;
		}
	}
	quick(a,low,p-1);
	quick(a,p+1,up);
}
