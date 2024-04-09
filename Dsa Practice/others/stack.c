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
    {
        return 1;
    }
    return 0;
}

int isFull()
{
    if (s.top == s.size - 1)
    {
        return 1;
    }
    return 0;
}

void push(int value)
{
    if (!isFull())
    {
        s.top++;
        s.arr[s.top] = value;
    }

    else
    {
        printf("\n stack is full you can't push item ");
    }
}

int pop()
{
    if (!isEmpty())
    {
        int del = s.arr[s.top];
        s.top--;
        printf("pop %d from the stack \n", del);
        return del;
    }
}

char peek()
{
    char x;
    if (!isEmpty())
    {
        x = s.arr[s.top];
    }
    else
        printf("The stack is empty\n");
    return x;
}

void display()
{
    if (isEmpty())
    {
        printf("Stack is empty \n");
        return;
    }
    printf("Stack Contents\n");
    for (int i = 0; i <= s.top; i++)
    {

        printf("%d\n", s.arr[i]);
    }
    printf("\n");
}
int main()
{

    s.arr = NULL;
    s.top = -1;
    s.size = 0;
    printf("Enter the size of the stack\n");
    scanf("%d", &s.size);

    s.arr = (int *)malloc(s.size * sizeof(int));

    int choice, value;
    while (1)
    {
        printf("\n1.Push \n2.Pop \n3.Display \n4.Exit \nEnter your choice");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("enter the value to push");
            scanf("%d", &value);
            push(value);
            break;

        case 2:
            pop();
            break;

        case 3:
            display();
            break;

        case 4:
            peek();
            break;

        case 5:
            printf("free");
            free(s.arr);
            exit(0);

        default:
            printf("Invalid choice");
            break;
        }
    }
    return 0;
}