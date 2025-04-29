#include<stdio.h>
#include<stdlib.h>
#define S 4
int q[S],front, rear;
void insertQueue(int x)//x is the value to be inserted
{
    if(rear==S-1)//TEST CASE
        printf("Queue is Full. Can't insert\n");
    else
    {
        if(front==-1)//1st element to be inserted
            front=rear=0;
        else
            rear++;
        q[rear]=x;
    }
}
void deleteQueue()
{
    if(front==-1)
        printf("The queue is Empty\n");
    else
    {
        printf("The deleted element is %d\n",q[front]);
        if(front==rear)//That is the Queue contains only ONE element
            front=rear=-1;
        else
            front++;
    }
}
void displayQueue()
{
    int i;
    if(front==-1)
        printf("Queue is Empty. Nothing to display\n");
    else
    {
        printf("Elements of the Queue are ");
        for(i=front;i<=rear;i++)
            printf("%d  ",q[i]);
        printf("\n");
    }
}
void menu()
{
    printf("\t\t\tProgram on Linear Queue\n");
    printf("\t\t\t  1. Insertion\n");
    printf("\t\t\t  2. Deletion\n");
    printf("\t\t\t  3. Display\n");
    printf("\t\t\t  4. Exit\n");
    printf("\t\t  Enter your choice ");
}
int main()
{
    int ch,a;
    front=rear=-1;
    while(1)
    {
        menu();
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter the value to insert ");
                scanf("%d",&a);
                insertQueue(a);
                break;
            case 2:
                deleteQueue();
                break;
            case 3:
                displayQueue();
                break;
            case 4:
                exit(0);
        }//End of switch
    }//End of while
}























