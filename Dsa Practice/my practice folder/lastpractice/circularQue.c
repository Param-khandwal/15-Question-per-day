#include <stdio.h>
#include <stdlib.h>
struct Queue
{
    int size;
    int rear;
    int front;
    int *arr;
};
struct Queue cq;

int underFlow()
{
    if (cq.front == cq.rear)
        return 1;

    return 0;
}
int overFlow()
{
    if (cq.front == (cq.rear + 1) % cq.size)
        return 1;

    return 0;
}
void enQueue(int elem)
{
    if (overFlow())
    {
        printf("You cannot enter any element ");
    }
    else
    {
        if (cq.front == -1)
        {
            cq.front++;
        }
        cq.rear=(cq.rear+1)%cq.size;
        cq.arr[cq.rear]=elem;
    }
}
int deQueue() {
  int x=-999;
  if(overFlow()){
    printf("queue is empty");
  }
  else{
    x=cq.arr[cq.front];
    if(cq.front==cq.rear){
        cq.front=-1;
        cq.rear=-1;
    }
    else{
        cq.front=(cq.front+1)%cq.size;
    }
    return x;
  }


}

void display()
{
}

int main()
{
    cq.size = 0;
    cq.rear = -1;
    cq.front = -1;

    printf("Enter the size of the queue ");
    scanf("%d", &cq.size);

    cq.arr = (int *)malloc(sizeof(int) * cq.size);
}