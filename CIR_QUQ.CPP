#include<stdio.h>
#include<stdlib.h>
# define MAX 5
int a[MAX];
int r=-1;
int f=-1;
void addition(int n)
{
	if ((f==0 && r==MAX-1)||(f==r+1))
	{
		printf("Queue is FULL\n");
		return;
	}
	if (f==-1)
		f=r=0;
	else if(r==MAX-1)
		r=0;
	else
		r++;
	a[r] = n;
}
void del()
{
	if (f==-1)
	{
		printf("Queue is EMPTY\n");
		return;
	}
	printf("Element deleted from queue is : %d\n", a[f]);
	if(f==r)
		f=r=-1;
	else if(f==MAX-1)
		f=0;
	else
		f++;
}
void display()
{
	int i;
	if (f==-1)
		printf("Queue is empty\n");
	else
	{
		printf("Elements of the Queue are :");
		if(f<=r)//When the Q is linear
		{
			for(i=f;i<= r;i++)
				printf("%d  ",a[i]);
		}
		else//f>r, i.e., the Queue is circular
		{
			for(i=f;i<MAX;i++)
				printf("%d  ",a[i]);
			for(i=0;i<=r;i++)
				printf("%d  ",a[i]);
		}
		printf("\n");
	}
}
void menu()
{
	printf("\t\t\tCIRCULAR QUEUE\n");
	printf("\t\t1.Insert\n");
	printf("\t\t2.Delete\n");
	printf("\t\t3.Display\n");
	printf("\t\t4.Quit\n");
	printf("\tEnter your choice : ");
}
int main()
{
	int ch,x;
	while(1)//for(;;)
	{
		menu();
		scanf("%d",&ch);
		switch(ch)
		{
			case 1 :
				printf("Enter the item to be inserted ");
				scanf("%d",&x);
				addition(x);
				break;
			case 2 :
				del();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(1);
			default:
				printf("Invalid choice\n");
		}//END of switch
	}//END of while loop
	return 0;
}

