#include<stdio.h>
#include<stdlib.h>
typedef struct linklist
{
	int n;
	struct linklist *next;
}node;
node *head=NULL;
void create()
{
	int x;
	char ch;
	node *t,*h;
	do
	{
		printf("Enter the value: ");
		scanf("%d",&x);
		t=(node*)malloc(sizeof(node));
		t->n=x;
		t->next=NULL;
		if(head==NULL)
		{
			head=t;
			h=t;	
		}
		else
		{
			h->next=t;
			h=t;
		}
		printf("Do you want to Continue??? ");
		fflush(stdin);
		x=getchar();
	}
		while(x=='y'||x=='Y');
}
void display()
{
	node *d=head;
	if(head==NULL)
	printf("List is empty. Nothing to display.");
	else
	{
		printf("The values are: ");
		while(d!=NULL)
		{
			printf("%d ",d->n);
			d=d->next;
		}
	}
}
node*search(int x)
{
	node*s=head;
		while(s!=NULL)
		{
			if(s->n==x)
			return s;
		else
		    s=s->next;	
		}
		return NULL;
}
int count()
{
	int c=0;
	node *a=head;
	while(a!=NULL)
	{
		c++;
		a=a->next;
	}
	return c;	
}
void deletebyvalue(int x)
{
	node *p,*h;
	p=search(x);
	if(p==NULL)
	printf("Value not Found!!!");
	else
	{
		if(head->n==x||head==p)
		 head=head->next;
		else
		{
			h=head;
			while(h->next!=p)
			h=h->next;
			h->next=p->next;
		}
		free(p);
	}
}
void deletebyposition(int pos)
{
	int c=count();
	node *p=head,*h=head;
	if(pos<=0||pos>c)
	  printf("Invalid Position");
	else
	{
		if(pos==1)
		head=head->next;
		else
		{
			for(int i=1;i<=pos-2;i++)
			h=h->next;
			p=p->next;
			h->next=p->next;
		}
		free(p);
	}  
	
}
void insertatposition(int o,int pos)
{
	int n=count();
	node *t,*p;
	if(pos<1||pos==n+1)
	printf("Invalid Position!!!!");
	else
	{
		t=(node*)malloc(sizeof(node));
		t->n=o;
		if(pos==1)
		{
			t->next=head;
			head=t;
		}
		else
		{
			p=head;
			for(int i=1;i<=pos-2;i++)
			p=p->next;
			t->next=p->next;
			p->next=t;
		}
	}
}
void insertbefore(int r,int e)
{
	node *p,*h,*t;
	p=search(e);
	if(p==NULL)
	printf("NOT FOUND!!!!");
	else
	{
		t=(node*)malloc(sizeof(node));
		t->n=r;
		if(head==p)
		{
			t->next=p;
			head=t;			
		}
		else
		{
			h=head;
			while(h->next!=p)
			{
				h=h->next;
			}
			h->next=t;
			t->next=p;
		}
	}
}
void insertafter(int q,int w)
{
	node *p=search(w),*t;
	if(p==NULL)
	printf("Given value NOT FOUND!!!!!");
	else
	{
		t=(node*)malloc(sizeof(node));
		t->n=q;
		t->next=p->next;
		p->next=t;
	}
}
void reverse()
{
	node *t1,*t2,*t3;
	if(head==NULL||head->next==NULL)
	{
		return;
	}
	t1=head;
	t2=t1->next;
	t3=t2->next;
	t1->next=NULL;
	while(t2!=NULL)
	{
		t2->next=t1;
		t1=t2;
		t2=t3;
		if(t3!=NULL)
		t3=t3->next;
	}
	head=t1;
}
void menu()
{
	printf("\n");
	printf("Program on Single LinkList:\n");
	printf("1.Create.\n");
	printf("2.Display.\n");
	printf("3.Search.\n");
	printf("4.Count.\n");
	printf("5.Delete By Value.\n");
	printf("6.Delete By Position.\n");
	printf("7.Insert at Position.\n");
	printf("8.Insert Before.\n");
	printf("9.Insert After.\n");
	printf("10.Reverse.\n");
	printf("11.EXIT\n");
	printf("Enter your choice: ");
}
int main()
{
     int ch,x,n,z,o,pos,e,pos2,w,pos3;//n for count x for display z for delete by position pos and o for insert at position e and r for inster before w and pos3 for insert after
     node *b;
     while(87)
	{
		menu();
		scanf("%d",&ch);
		switch(ch)
	{
	case 1:
		create();
		system("pause");
                system("cls");
                break;
    case 2:
	     display();
		 system("pause");
		 system("cls");
		 break;            
	case 3:
	    if(head==NULL)
		printf("List is Empty. Nothing to display.");
		else
		{
			printf("Enter th value: ");
			scanf("%d",&x);
			b=search(x);
			if(b==NULL)
			printf("Searched element NOT FOUND!!!!");
			else
			printf("FOUND.");
		}
		system("pause");
		 system("cls");
		     break;
	case 4:
		n=count();
		printf("Number of node is %d \n",n);
		system("pause");
                system("cls");
				break;
	case 5:
	    printf("Enter the value you want to delete: ");
		scanf("%d",&x);
		deletebyvalue(x);
		system("pause");
		system("cls");
		break;	
    case 6:
    	printf("Enter the Position you want to delete: ");
    	scanf("%d",&z);
    	deletebyposition(z);
    	system("pause");
    	system("cls");
    	break;
    case 7:
    	printf("Enter the value: ");
    	scanf("%d",&o);
    	printf("Enter the value to insert at postion: ");
    	scanf("%d",&pos);
    	insertatposition(o,pos);
    	system("pause");
    	system("cls");
    	break;
    case 8:
    	printf("Enter the value: ");
    	scanf("%d",&e);
    	printf("Enter the value to insert before: ");
    	scanf("%d",&pos2);
    	insertbefore(e,pos2);
    	system("pause");
    	system("cls");
    	break;
    case 9:
    	printf("Enter the value: ");
    	scanf("%d",&w);
    	printf("Enter the value to insert after: ");
    	scanf("%d",&pos3);
    	insertafter(w,pos3);
    	system("pause");
    	system("cls");
    	break;
    case 10:
	    reverse();
		system("pause");
        system("cls");
        break;
	case 11:
	exit(0);		
    }
    }
}
