#include<stdio.h>
#include<string.h>
int length, top;
char stack[100];
void push(char p)
{
    top++;
    stack[top]=p;
}
char pop()
{
    char x=stack[top];
    top--;
    return x;
}
int main()
{
	int i;
	char s[100];
	top=-1;
	printf("Enter a string ");
	scanf("%[^\n]s",s);//^ means Circumflex Operator
	length=strlen(s);
	for(i=0;s[i]!=NULL; i++)
        push(s[i]);
    printf("The reversed String is ");
    for(i=top;i>=0;i--)
        printf("%c",pop());
	return 0;
}






