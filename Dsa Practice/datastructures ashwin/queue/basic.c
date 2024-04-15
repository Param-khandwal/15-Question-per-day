#include<stdio.h>
#include<stdlib.h>

struct __queue__ {
    int *q;
    int size;
    int front;
    int rear;
};
struct __queue__ que;
int underflow();
int overflow();
void enque(int);
int deque();
void display();
void point();
int underflow(){
    if(que.front == -1 && que.rear == -1)
    return 1;
return 0;
}

int overflow(){
    if(que.rear == que.size-1)
    return 1;
return 0;
}

void enque(int n){
    if(!overflow()){
        if(que.front == -1){
            que.front++;
            
        }que.rear++;
        que.q[que.rear]= n;
    }
    else 
    printf("\nThe queue is full");
}

int deque(){
    int x = -999;
    if(!underflow()){
        x = que.q[que.front];
        if(que.front==que.rear){
        que.front=-1;
        que.rear = -1;
        }
        else
        que.front++;
    }
    else
    printf("\nThe queue is empty");
return x;
}

void display(){
    for(int i=que.front;i<=que.rear;i++){
        printf("%d",que.q[i]);
    }
    printf("\n");
}
void point(){
    printf("Front:%d\n",que.front);
    printf("Rear:%d\n",que.rear);
}
int main(){
    que.q = NULL;
    que.size = 0;
    que.front = -1;
    que.rear = -1;
    int ch,x,y;
    printf("Enter the queue size:");
    scanf("%d",&que.size);
    que.q = (int*)malloc(que.size*sizeof(int));
    do{
    printf("Enter your choice\n 1.Enque\n 2.Deque\n 3.Display\n 4.Pointer position\n");
    scanf("%d",&x);
    switch(x){
        case 1:
        printf("Enter the element:");
        scanf("%d",&y);
        enque(y);
        break;
        case 2:
        printf("Element %d has been deleted",deque());
        break;
        case 3:
        display();
        break;
        case 4:
        point();
        break;
        default:
        printf("Not a valid operation");
    }
    }while(x!=0);
free(que.q);
que.q = NULL;
}