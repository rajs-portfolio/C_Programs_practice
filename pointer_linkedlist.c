#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *prev, *next;
};
typedef struct node *ndptr;
ndptr head = NULL;
void create()
{
    int x;
    printf("Enter value for the new node: ");
    scanf("%d", &x);

    ndptr temp = (ndptr)malloc(sizeof(struct node));
    temp->info = x;
    temp->prev = temp->next = NULL;

    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        ndptr p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
        temp->prev = p;
    }
}

void insert(int x, int pos)
{
    ndptr temp = (ndptr)malloc(sizeof(struct node));
    temp->info = x;
    temp->prev = temp->next = NULL;

    if (pos == 1)
    {
        temp->next = head;
        if (head != NULL)
        {
            head->prev = temp;
        }
        head = temp;
        return;
    }

    ndptr p = head;
    for (int i = 1; i < pos - 1 && p != NULL; i++)
    {
        p = p->next;
    }

    if (p == NULL)
    {
        printf("Invalid position.\n");
        free(temp);
        return;
    }

    temp->next = p->next;
    if (p->next != NULL)
    {
        p->next->prev = temp;
    }
    p->next = temp;
    temp->prev = p;
}

void delbyValue(int x)
{
    ndptr p = head;

    while (p != NULL && p->info != x)
    {
        p = p->next;
    }

    if (p == NULL)
    {
        printf("Node with value %d not found.\n", x);
        return;
    }

    if (p->prev != NULL)
    {
        p->prev->next = p->next;
    }
    else
    {
        head = p->next;
    }

    if (p->next != NULL)
    {
        p->next->prev = p->prev;
    }

    free(p);
    printf("Node with value %d deleted.\n", x);
}

void display()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    ndptr p = head;
    while (p != NULL)
    {
        printf("%d ", p->info);
        p = p->next;
    }
}

void menu()
{
    printf("\nDoubly Linked List Menu:\n");
    printf("1. Create node\n");
    printf("2. Insert node\n");
    printf("3. Delete node by value\n");
    printf("4. Display list\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

int main()
{
    int ch, x, pos;
    while (1)
    {
        menu();
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            create();
            break;
        case 2:
            printf("Enter value to insert: ");
            scanf("%d", &x);
            printf("Enter position: ");
            scanf("%d", &pos);
            insert(x, pos);
            break;
        case 3:
            if (head == NULL)
            { 
                printf("List is empty.\n");
                return 0;
            }
            else
            {
                printf("Enter value to delete: ");
                scanf("%d", &x);
                delbyValue(x);
            }
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid Input");
        }
    }
    return 0;
}
