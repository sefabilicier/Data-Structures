#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef struct Queue
{
    int front;
    int rear;
    int size;
    int items[MAX];
} Queue;

void initQueue(Queue* q)
{
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

bool enqueue(Queue* q, int value)
{
    if (q->size >= MAX)
    {
        printf("Queue is full\n");
        return false;
    }

    q->rear = (q->rear + 1) % MAX;
    q->items[q->rear] = value;
    q->size++;
    return true;
    
}

bool dequeue(Queue* q, int* value) 
{
    if (q->size <= 0) 
    {
        printf("Queue is empty\n");
        return false;
    }

    *value = q->items[q->front];
    q->front = (q->front + 1) % MAX;
    q->size--;
    return true;
}

bool top(Queue* q, int* value)
{
    if (q->size <=0)
    {
        printf("Queue is empty\n");
        return false;
    }

    *value =  q->items[q->front];
    return true;
    
}

bool isEmpty(Queue* q)
{
    return q->size == 0;
}

void printQueue(Queue* q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue contents: \n");
    for (int i = 0; i < q->size; i++)
    {
        printf("%d\n", q->items[q->front + i] % MAX);
    }
    
}

int main()
{
    Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    printQueue(&q);

    int value;
    if (dequeue(&q, &value))
    {
        printf("Dequeued: %d\n", value);
    }
    if (top(&q, &value))
    {
        printf("Front value: %d\n", value);
    }

    printQueue(&q);
       
}

