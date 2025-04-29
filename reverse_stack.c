#include<stdio.h>
#include<stdlib.h>
#define MAX 15
int a[MAX],top;
int b[MAX];
void push(int x)
{
	if(top==MAX-1)
	{
		printf("Stack is Full. Can't Push\n");
	}
	else
	{
		top++;
		a[top]=x;
	}
}
	
void pop()
{
	if(top==-1)
	{
		printf("The Stack is Empty. Can't pop\n");
	}
	else
	{
		printf("The popped element is %d",a[top]);
		top--;
	}
}
void reverse() {
	int j = 0,i;
	for(i = top; i >= 0; i--) {
		b[j++] = a[i];
	}
	printf("Reversed Stack: ");
	for(i = 0; i < j; i++) {
		printf("%d ", b[i]);
	}
	printf("\n");
}

void display()
{
	int i;
	if(top==-1)
	{
		printf("Empty Stack. Nothing to display");
	}
	else
	{
		printf("The elements of the Stack are ");
		for(i=0;i<=top;i++)
			printf("%d ",a[i]);
	}
}
void menu()
{
	printf("\n");
	printf("\t\t\t PROGRAM ON Stack\n");
	printf("\t\t\t   1. PUSH\n");
	printf("\t\t\t   2. POP\n");
	printf("\t\t\t   3. DISPLAY\n");
	printf("\t\t\t   4. REVERSE\n");
	printf("\t\t\t   5. EXIT\n");
	printf("Enter your choice ");
}
int main()
{
	int ch,m;
	top=-1;
	while(875)
	{
		menu();
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nEnter the number to push ");
				scanf("%d",&m);
				push(m);
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			case 4:
				reverse();
				break;
			case 5:
			 	exit(0);
			default:
				printf("\nInvalid choice \n");
				break;
		}
	}
	return 0;
}
