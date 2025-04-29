#include<stdio.h>
#define max 10

struct stack
 {
   int top;
   char item[max];
 }s;

int prcd(char,char);
void push(struct stack*,char);
char pop(struct stack*);
int isop(char);
int isd(char);
void str_rev(char*);

int main()
 {
   int l,i,j=0,flag=1;
   char inf[10],pre[10],h,k;
   s.top=-1;
   push(&s,')');
   printf("\nEnter the infix expression starting with a '(' : ");
   for(i=0;i<6;i++)
     scanf("%c",&inf[i]);
   for(i=5;i>=0;i--)
	{
	  if(inf[i]==')')
		push(&s,')');
	  if(isop(inf[i])||isd(inf[i]))
		pre[j++]=inf[i];
	  if(inf[i]=='(')
	   {
		 do
		  {
			h=pop(&s);
			if(h!=')')
			 pre[j++]=h;
		  }while(h!=')');
	   }
	  if(inf[i]=='+'||inf[i]=='-'||inf[i]=='*'||inf[i]=='/'||inf[i]=='$')
	   {
		 while(flag)
		  {
			k=pop(&s);
			if(prcd(k,inf[i]))
			  pre[j++]=k;
			else
			 {
			  push(&s,k);
			  flag=0;
			 }
		  }
		 push(&s,inf[i]);
		 flag=1;
	   }
	}
   
   str_rev(pre);
   return 0;
 }

void push(struct stack *s,char x)
 {
   if(s->top==9)
	{
	 printf("\nOVERFLOW");
	 return;
	}
   s->item[++s->top]=x;
 }

char pop(struct stack *s)
 {
   if(s->top==-1)
	{
	 printf("\nUNDERFLOW");
	 return 0;
	}
   return(s->item[s->top--]);
 }

int isd(char b)
 {
   return(b>='0'&&b<='9');
 }

int isop(char b)
 {
   return((b>='a'&&b<='z')||(b>='A'&&b<='Z'));
 }

int prcd(char a,char b)
 {
   if(a==')')
	 return 0;
   if(a==b)
	 return 0;
   if((a=='-'&&b=='*')||(a=='+'&&b=='*')||(a=='-'&&b=='/')||(a=='+'&&b=='/'))
	 return 0;
   if((a=='-'&&b=='$')||(a=='+'&&b=='$')||(a=='*'&&b=='$')||(a=='/'&&b=='$'))
	 return 0;
   else
	 return 1;
 }

void str_rev(char pre[10])
 {
   int i=5;
   printf("\nThe equivalent prefix expression is : ");
   for(;i>=0;i--)
     printf("%c",pre[i]);
 }
