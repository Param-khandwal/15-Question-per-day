#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int size;
    int top;
    int *arr;
};
struct stack s;

int isEmpty()
{
    if (s.top == -1)
        return 1;

    return 0;
}

int isFull()
{
    if (s.top == s.size - 1)
        return 1;

    return 0;
}

void push(int elem){
    if(isFull()){
        printf("stack is full");
    }
    else{
        s.arr[++s.top]=elem;
    }
}

int pop(){
    int x=-999;
    if(isEmpty()){
        printf("there is no element in the stack");
    }
    else{
        x=s.arr[s.top];
        s.top--;
    }
    return x;
}

void display(){
    if(isEmpty()){
        printf("stack is empty");
    }
    else{
    printf("Element of the stack\n");
     for(int i=0;i<=s.top;i++){
        printf("%d\t",s.arr[i]);
     }
    }
}

int main()
{
    s.size = 0;
    s.top = -1;

    printf("Enter the size of the stack : ");
    scanf("%d", &s.size);

    s.arr = (int *)malloc(sizeof(int) * s.size);

   push(45);
   pop();
   display();
}