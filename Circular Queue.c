#include<stdio.h>
#include<stdlib.h>
#define N 10
int cq[N],front, rear;
void insertQueue(int x)
{
    if((front==0 && rear==N-1) || (front==rear+1) )
        printf("The Queue is Full\n");
    else
    {
        if(front==-1)
            front=rear=0;
        else if(rear==N-1)
            rear=0;
        else
            rear++;
        cq[rear]=x;
    }
}
void deleteQueue()
{
    if(front==-1)
        printf("Q is Empty\n");
    else
    {
        printf("The deleted element is %d\n",cq[front]);
        if(front==rear)
            front=rear=-1;
        else if(front==N-1)
            front=0;
        else
            front++;
    }
}
void displayQueue()
{
    int i;
    if(front==-1)
        printf("The Q is Empty. Nothing to display\n");
    else
    {
        printf("The elements are (Front->Rear): ");
        if(front<=rear)//Still the Queue is Linear
        {
            for(i=front;i<=rear;i++)
                printf("%d  ",cq[i]);
        }
        else//Now the queue is Circular
        {
            for(i=front;i<=N-1;i++)//Prints from Front to Last
                printf("%d  ",cq[i]);
            for(i=0;i<=rear;i++)//Prints from 0 to Rear
                printf("%d  ",cq[i]);
        }
        printf("\n");
    }
}






