#include<stdio.h>
#include<stdlib.h>
typedef struct linklist
{
    int data;
    struct linklist *next;
}node;
node *head='\0';
void create()
{
    int x;
    char a;
    node *t,*h;
    do
    {
        printf("Enter a value ");
        scanf("%d",&x);
        t=(node *)malloc(sizeof(node));
        t->data=x;
        t->next='\0';
        if(head=='\0')
        {
            head=t;
            h=t;
        }
        else
        {
            h->next=t;
            h=t;
        }
        printf("Create another ? ");
        fflush(stdin);
        a=getchar();
    }
    while(a=='Y' || a=='y');
}
void display()
{
    node *k=head;
    if(head=='\0')
    {
        printf("List is Empty. Nothing to display\n");
        return;
    }
    printf("The elements are ");
    while(k!='\0')
    {
        printf("%d  ",k->data);
        k=k->next;
    }
}
node * search(int x)
{
    node *n=head;
    while(n!='\0')
    {
        if(n->data==x)
            break;
        else
            n=n->next;
    }
    return n;
}
int count()
{
    int c=0;
    node *n=head;
    while(n!='\0')
    {
        c++;
        n=n->next;
    }
    return c;
}
int main()
{
    int x,ch,n;
    node *p;
    while(25)
    {
        printf("\n");
        printf("\tProgram on Single Link List\n");
        printf("\t\t1. Create\n");
        printf("\t\t2. Display\n");
        printf("\t\t3. Search\n");
        printf("\t\t4. Count\n");
        printf("\t\t5. Exit\n");
        printf("\t\tEnter your choice ");
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
                if(head=='\0')
                    printf("List is Empty. Can't search anything\n");
                else
                {
                    printf("Enter the value to search ");
                    scanf("%d",&x);
                    p=search(x);
                    if(p=='\0')
                        printf("%d is NOT Found\n",x);
                    else
                        printf("Found\n");
                }
                system("pause");
                system("cls");
                break;
            case 5:
                exit(0);
            case 4:
                n=count();
                printf("Number of nodes is %d\n",n);
                system("pause");
                system("cls");
                break;
        }
    }
}
