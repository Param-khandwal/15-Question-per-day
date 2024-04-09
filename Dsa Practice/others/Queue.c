#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int *arr;
    int size;
    int rear;
    int front;
};

struct queue q;

int isEmpty()
{
    if (q.rear == q.front)
    {
        return 1;
    }
    return 0;
}

int isFull()
{
    if (q.rear == q.size - 1)
    {
        return 1;
    }
    return 0;
}

int enQueue(int value)
{
    if (isFull())
    {
        printf("Queue is full ");
    }
    else
    {
        q.rear++;
        q.arr[q.rear] = value;
        printf("Enque element of %d\n", value);
    }
}

int deQueue()
{
    int x = -99;
    if (isEmpty)
    {
        printf("queue is empty not able to delete element");
    }
    else
    {
        q.front--;
        x = q.arr[q.front];
    }
    return x;
}

void display()
{
    if (isEmpty())
    {
        printf("queue is emepty");
    }
    else
    {
        for (int i = q.front+1; i <=q.rear; i++)
        {
            printf("%d", q.arr[i]);
        }
        printf("\n");
    }
}

int main()
{

    q.arr = NULL;
    q.rear = -1;
    q.front = -1;
    q.size = 0;

    printf("Enter the size of the queue");
    scanf("%d", &q.size);

    q.arr = (int *)malloc(q.size * (sizeof(int)));

    int choice, value;
    while (1)
    {
        printf("\n1.Enqueue \n2.Dequeue \n3.Display \n4.exit \n Enter your choice");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the value you want to push");
            scanf("%d", &value);
            enQueue(value);
            break;

        case 2:
            deQueue();
            break;

        case 3:
            display();
            break;

        case 4:
            printf("free");
            free(q.arr);
            exit(0);

        default:printf("Invalid choice");
            break;
        }
    }
}