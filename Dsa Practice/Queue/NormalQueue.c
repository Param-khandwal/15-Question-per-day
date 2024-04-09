// Queue
#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int front;
    int rear;
    int *arr;
};
struct queue que;

int isEmpty()
{
    if (que.front == que.rear)
    {
        printf("queue is empty\n");
        return 1;
    }
    return 0;
} // end of isempty or overflow

int isFull()
{
    if (que.rear == que.size - 1)
    {
        return 1;
    }
    return 0;
}

void enQueue(int elem)
{
    if (isFull())
    {
        printf(" this queue is full\n");
    }
    else
    {
        que.rear++;
        que.arr[que.rear] = elem;
        printf("Enque element of :%d\n", elem);
    }
}

int deQueue()
{
    int x = -99;
    if (isEmpty())
    {
        printf("the queue is empty\n");
    }
    else
    {
        que.front++;
        x = que.arr[que.front];
    }
    return x;
}

void display()
{
    if (que.front == -1)
    {
        printf("Queues is empty\n");
    }
    else
    {
        printf("Queue elements\n");
        for (int i = que.front + 1; i <= que.rear; i++)
        {
            printf("%d", que.arr[i]);
        }
        printf("\n");
    }
}
int main()
{
    que.arr = NULL;
    que.size = 5;
    que.front = -1;
    que.rear = -1;
    que.arr = (int *)malloc(que.size * sizeof(int));

    enQueue(5);
    display();
    enQueue(5);
    enQueue(10);
    enQueue(15);
    display();

    int dequeued = deQueue();
    printf("Dequeued element: %d\n", dequeued);
    display();

    free(que.arr);
        return 0;
}
