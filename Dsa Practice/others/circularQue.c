// circular queue Buffer Ring
#include <stdio.h>
#include <stdlib.h>

// #define max_size 5

struct Cque
{
    int rear;
    int front;
    int size;
    int *arr;
};
struct Cque c;

int isEmpty()
{
    if (c.front == c.rear)
    {
        return 1;
    }
    return 0;
}

int isFull()
{
    if (c.front==(c.rear+1)%c.size)
    {
        return 1;
    }
    return 0;
}

void enQueue(int ele){
    if(isFull()){
         printf("\nThe queue is full");
    }

    else{
        if(c.front==-1){
            c.front++;
        }
        c.rear=(c.rear+1)%c.size;
        c.arr[c.rear]=ele;
    }
}

int deQueue(){
    int x=-99;
    if(isEmpty()){
        printf("The is Empty nothing to delete");
    }
    else{
        x=c.arr[c.front];
        if(c.front==c.rear){
            c.front=-1;
            c.rear=-1;
        }
        else{
            c.front=(c.front+1)%c.size;
        }
    }
    return x;
}

void display(){
    for(int i=c.front;i!=c.rear;i=(i+1)%c.size){
        printf("%d",c.arr[i]);
    }
    printf("%d",c.arr[c.rear]);
    printf("\n");
}

int main()
{
    c.arr = NULL;
    c.rear = -1;
    c.front = -1;
    c.size = 0;

    printf("Enter the size of the Circluar Queue\n ");
    scanf("%d", &c.size);

    c.arr = (int *)malloc(c.size * sizeof(int));



    int choice, value;
    while (1)
    {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter your choice:");
        printf("Enter your choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter value to enqueue: ");
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
            printf("Exiting program.\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

   



    free(c.arr);
    c.arr=NULL;
    return 0;
}