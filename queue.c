#include <stdio.h>
#include <string.h>

#define MAX 10

struct Queue {
    int front, rear, size;
    char items[MAX];
} q;

void initQueue(struct Queue* q);
void enqueue(struct Queue* q, char x);
char dequeue(struct Queue* q);
int isQueueEmpty(struct Queue* q);
int isQueueFull(struct Queue* q);
void printQueue(struct Queue* q);

int main() {
    char input[MAX];
    int i;

    initQueue(&q);

    printf("Enter a string to enqueue (max %d characters): ", MAX - 1);
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; 
    for (i = 0; i < strlen(input); i++) {
        if (isQueueFull(&q)) {
            printf("\nQueue is full, cannot enqueue more characters.\n");
            break;
        }
        enqueue(&q, input[i]);
    }

    printf("\nQueue contents:\n");
    while (!isQueueEmpty(&q)) {
        char item = dequeue(&q);
        printf("%c ", item);
    }
    printf("\n");

    return 0;
}

void initQueue(struct Queue* q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

void enqueue(struct Queue* q, char x) {
    if (isQueueFull(q)) {
        printf("\nQueue is full");
        return;
    }
    q->rear = (q->rear + 1) % MAX;
    q->items[q->rear] = x;
    q->size++;
}

char dequeue(struct Queue* q) {
    if (isQueueEmpty(q)) {
        printf("\nQueue is empty");
        return 0;
    }
    char item = q->items[q->front];
    q->front = (q->front + 1) % MAX;
    q->size--;
    return item;
}

int isQueueEmpty(struct Queue* q) {
    return q->size == 0;
}

int isQueueFull(struct Queue* q) {
    return q->size == MAX;
}

void printQueue(struct Queue* q) {
    if (isQueueEmpty(q)) {
        printf("\nQueue is empty");
        return;
    }
    printf("\nQueue elements: ");
    for (int i = 0; i < q->size; i++) {
        printf("%c ", q->items[(q->front + i) % MAX]);
    }
    printf("\n");
}
