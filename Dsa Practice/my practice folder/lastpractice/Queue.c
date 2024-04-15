#include <stdio.h>
#include <stdlib.h>
struct Queue
{
    int size;
    int rear;
    int front;
    int *arr;
};

struct Queue q;

int underFlow()
{
    if (q.front == -1 && q.rear == -1)
        return 1;

    return 0;
}

int overFlow()
{
    if (q.rear == q.size - 1)
        return 1;

    return 0;
}

void enQueue(int elem)
{
    if (overFlow())
    {
        printf("queue is full");
    }
    else
    {
        if (q.front == -1)
        {
            q.front++;
        }
        // q.rear++;
        q.arr[++q.rear] = elem;
        
    }
}

int deQueue()
{
    if(underFlow()){
        printf("the queue is empty");
    }
    else{
        int elem=q.arr[q.front];
        if(q.front==q.rear){
            q.front=q.rear=-1;
        }
        else{
            q.front++;
        }
        return elem;
    }
}

void display()
{
    if (underFlow())
    {
        printf("The queue is empty");
    }
    else
    {
        for (int i = q.front; i <= q.rear; i++)
            printf("%d\t", q.arr[i]);
    }
}

int main()
{
    q.size = 0;
    q.rear = -1;
    q.front = -1;

    printf("Enter the size of the queue ");
    scanf("%d", &q.size);

    q.arr = (int *)malloc(sizeof(int) * q.size);

    // printf("%d",overFlow());

   enQueue(10);
   enQueue(20);
   enQueue(30);
    display();

    printf("Dequeued element: %d\n", deQueue());
    display();
}