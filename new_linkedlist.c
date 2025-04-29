#include <stdio.h>
#include <stdlib.h>

typedef struct linklist
{
	int n;
	struct linklist *next;
} node;

node *head = NULL;

void create()
{
    int x;
    char a;
    node *t, *h;
    do
    {
        printf("Enter a value: ");
        scanf("%d", &x);
        
        t = (node *)malloc(sizeof(node));  
        t->n = x;
        t->next = NULL;  
        
        if (head == NULL)  
        {
            head = t;
            h = t;
        }
        else
        {
            h->next = t;
            h = t;
        }

        printf("Create another? (Y/N): ");
        while (getchar() != '\n'); 
		fflush(stdin); 
        a = getchar();
    }
    while (a == 'Y' || a == 'y');
}

void display()
{
	node *d = head;
	if (head == NULL)
		printf("The list is Empty.\n");
	else
	{
		printf("The Values are: ");
		while (d != NULL)
		{
			printf("%d ", d->n);
			d = d->next;
		}
		printf("\n");
	}
}

node *search(int x)
{
	node *s = head;
	while (s != NULL)
	{
		if (s->n == x)
			return s;
		s = s->next;
	}
	return NULL;
}

int count()
{
	int c = 0;
	node *z = head;
	while (z != NULL)
	{
		c++;
		z = z->next;
	}
	return c;
}

void delbyValue(int a)
{
	node *p, *h;
	p = search(a);
	if (p == NULL)
		printf("Value %d not found.\n", a); // Added format specifier
	else
	{
		if (head == p)
			head = head->next;
		else
		{
			h = head;
			while (h->next != p)
				h = h->next;
			h->next = p->next;
		}
		free(p);
	}
}

void delbyPos(int pos)
{
	int c = count(), i;
	node *h = head, *p = head;
	if (pos <= 0 || pos > c)
		printf("Invalid Position\n");
	else
	{
		if (pos == 1)
			head = head->next;
		else
		{
			for (i = 1; i <= pos - 2; i++)
				h = h->next;
			p = h->next;
			h->next = p->next;
		}
		free(p);
	}
}

void insertatPosition(int x, int pos)
{
	int c = count(), i;
	node *t, *p;
	if (pos < 1 || pos > c + 1)
		printf("Invalid Position.\n");
	else
	{
		t = (node *)malloc(sizeof(node));
		t->n = x;
		if (pos == 1)
		{
			t->next = head;
			head = t;
		}
		else
		{
			p = head;
			for (i = 1; i <= pos - 2; i++)
				p = p->next;
			t->next = p->next;
			p->next = t;
		}
	}
}

void insertBefore(int x, int a)
{
	node *p, *h, *t;
	p = search(a);
	if (p == NULL)
		printf("NOT FOUND.\n");
	else
	{
		t = (node *)malloc(sizeof(node));
		t->n = x;
		if (head == p)
		{
			t->next = p;
			head = t;
		}
		else
		{
			h = head;
			while (h->next != p)
				h = h->next;
			h->next = t;
			t->next = p;
		}
	}
}

void insertAfter(int x, int a)
{
	node *p, *t;
	p = search(a);
	if (p == NULL)
		printf("NOT FOUND.\n");
	else
	{
		t = (node *)malloc(sizeof(node));
		t->n = x;
		t->next = p->next;
		p->next = t;
	}
}

void reverse()
{
	node *a1, *a2, *a3;
	if (head == NULL || head->next == NULL)
	{
		return;
	}
	a1 = head;
	a2 = a1->next;
	a3 = a2->next;
	a1->next = NULL;
	while (a2 != NULL)
	{
		a2->next = a1;
		a1 = a2;
		a2 = a3;
		if (a3 != NULL)
			a3 = a3->next;
	}
	head = a1;
}

void menu()
{
	printf("\n");
	printf("Program on single Linked List:-- \n");
	printf("1. Create \n");
	printf("2. Display \n");
	printf("3. Search \n");
	printf("4. Count \n");
	printf("5. Delete By Value\n");
	printf("6. Delete By Position\n");
	printf("7. Insert At Position\n");
	printf("8. Insert Before\n");
	printf("9. Insert After\n");
	printf("10. Reverse\n");
	printf("11. Exit \n");
	printf("Enter your choice: ");
}

int main()
{
	int n, ch, x, pos;
	node *b;
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
			display();
			break;
		case 3:
			if (head == NULL)
				printf("List is empty. Nothing to display.\n");
			else
			{
				printf("Enter the value to search: ");
				scanf("%d", &x);
				b = search(x);
				if (b == NULL)
					printf("%d Element is not Found. \n", x);
				else
					printf("Found \n");
			}
			break;
		case 4:
			n = count();
			printf("Number of nodes is %d \n", n);
			break;
		case 5:
			printf("Enter value to delete: ");
			scanf("%d", &x);
			delbyValue(x);
			break;
		case 6:
			printf("Enter position to delete: ");
			scanf("%d", &pos);
			delbyPos(pos);
			break;
		case 7:
			printf("Enter value to insert: ");
			scanf("%d", &x);
			printf("Enter position: ");
			scanf("%d", &pos);
			insertatPosition(x, pos);
			break;
		case 8:
			printf("Enter value to insert: ");
			scanf("%d", &x);
			printf("Enter the value before which to insert: ");
			scanf("%d", &pos);
			insertBefore(x, pos);
			break;
		case 9:
			printf("Enter value to insert: ");
			scanf("%d", &x);
			printf("Enter the value after which to insert: ");
			scanf("%d", &pos);
			insertAfter(x, pos);
			break;
		case 10:
			reverse();
			break;
		case 11:
			exit(0);
		}
	}
}
