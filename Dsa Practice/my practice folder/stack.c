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

void push(int ele)
{
    if (isFull())
    {
        printf("The stack is full you can,t enter any element");
    }
    else
    {
        s.top++;
        s.arr[s.top] = ele;
    }
}

int pop()
{
    int x = -999;
    if (isEmpty())
    {
        printf("there is no element in the stack\n");
    }
    else
    {
        x = s.arr[s.top];
        s.top--;
    }
    return x;
}

int peek()
{
    int x;
    if (isEmpty())
    {
        printf("Stack is empty.\n");
    }
    else
    {
        x = s.arr[s.top];
        printf("%d\n", x);
    }
    return x;
}

void display()
{
    if (isEmpty())
    {
        printf("Stack is empty.\n");
    }
    else
    {

        for (int i = 0; i <= s.top; i++)
        {
            printf("%d\t", s.arr[i]);
            printf("\n");
        }
    }
}

int main()
{
    int ch, ele;
    s.arr = NULL;
    s.size = 0;
    s.top = -1;
    printf("Enter the size of the stack\n");
    scanf("%d", &s.size);
    s.arr = (int *)malloc(sizeof(int) * s.size);
    printf("1.push 2.pop 3.display 4.peek 5.Exit ");
    scanf("%d", &ch);
 
    while (1)
    {
        
        switch (ch)
        {
        case 1:
            printf("Enter the element of your choice\n");
                scanf("%d", &ele);
                push(ele);
            
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
            exit(0);
            break;

        default:
            printf("Not a valid option\n");
            break;
        }
          printf("1.push 2.pop 3.display 4.peek 5.Exit ");
        scanf("%d", &ch);
      
    }

    free(s.arr);
    s.arr = NULL;
}