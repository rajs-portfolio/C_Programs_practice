#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

// Head of the DLL
struct Node *head = NULL;

// Function to create and append a new node
void append(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to display the DLL
void display()
{
    struct Node *temp = head;
    printf("Doubly Linked List: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf(" ");
}

// Function to count the number of nodes
int count()
{
    int count = 0;
    struct Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

// Function to search for a value in the DLL
int search(int value)
{
    struct Node *temp = head;
    int position = 1;
    while (temp != NULL)
    {
        if (temp->data == value)
        {
            return position;
        }
        temp = temp->next;
        position++;
    }
    return -1;
}

// Function to delete a node by value
void deleteByValue(int value)
{
    struct Node *temp = head;

    while (temp != NULL && temp->data != value)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Value not found!");
        return;
    }

    if (temp->prev != NULL)
    {
        temp->prev->next = temp->next;
    }
    else
    {
        head = temp->next;
    }

    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }

    free(temp);
    printf("Node with value %d deleted.", value);
}

// Function to delete a node by position
void deleteByPosition(int position)
{
    if (head == NULL || position <= 0)
    {
        printf("Invalid position!");
        return;
    }

    struct Node *temp = head;

    for (int i = 1; temp != NULL && i < position; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Position out of range!");
        return;
    }

    if (temp->prev != NULL)
    {
        temp->prev->next = temp->next;
    }
    else
    {
        head = temp->next;
    }

    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }

    free(temp);
    printf("Node at position %d deleted.", position);
}

// Function to insert a node at a specific position
void insertAtPosition(int data, int position)
{
    if (position <= 0)
    {
        printf("Invalid position!");
        return;
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (position == 1)
    {
        newNode->next = head;
        if (head != NULL)
        {
            head->prev = newNode;
        }
        head = newNode;
        return;
    }

    struct Node *temp = head;

    for (int i = 1; temp != NULL && i < position - 1; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Position out of range!");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
    {
        temp->next->prev = newNode;
    }

    temp->next = newNode;
}

// Main function to test the DLL
int main()
{
    int choice, data, position;

    while (1)
    {
        printf("1. Append\n 2. Display \n 3. Count\n 4. Search\n 5. Delete by Value\n");
        printf("6. Delete by Position\n 7. Insert at Position\n 8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            append(data);
            break;

        case 2:
            display();
            break;

        case 3:
            printf("Number of nodes: %d", count());
            break;

        case 4:
            printf("Enter value to search: ");
            scanf("%d", &data);
            position = search(data);
            if (position != -1) {
                printf("Value found at position: %d", position);
            } else {
                printf("Value not found!");
            }
            break;

        case 5:
            printf("Enter value to delete: ");
            scanf("%d", &data);
            deleteByValue(data);
            break;

        case 6:
            printf("Enter position to delete: ");
            scanf("%d", &position);
            deleteByPosition(position);
            break;

        case 7:
            printf("Enter data: ");
            scanf("%d", &data);
            printf("Enter position: ");
            scanf("%d", &position);
            insertAtPosition(data, position);
            break;

        case 8:
            exit(0);

        default:
            printf("Invalid choice!");
        }
    }

    return 0;
}
