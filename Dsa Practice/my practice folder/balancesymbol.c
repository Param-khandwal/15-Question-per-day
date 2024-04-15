#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int size;
    int *arr;
    int top;
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

void push(char ele)
{
    if (isFull())
    {
        printf("stack is full\n");
    }

    else
    {
        s.arr[++s.top] = ele;
    }
}

char pop()
{
    char x;
    if (isEmpty())
    {
        printf("stck is empty\n");
    }
    else
    {
        x = s.arr[s.top--];
    }
    return x;
}

char peek()
{
    if (isEmpty())
    {
        printf("stack is empty");
    }
    else
    {
        printf("%c", s.arr[s.top]);
    }
}

void display()
{
    if (isEmpty())
    {
        printf("the stack is empty ");
    }
    else
    {
        for (int i = 0; i <= s.top; i++)
        {
            printf("%d", s.arr[i]);
        }
    }
}

int main()
{
    s.arr = NULL;
    s.top = -1;
    s.size = 0;

    char str[50], ch, x,i;
    int length = 0, flag = 0;

    printf("Enter the string :\n");
    scanf("%s", str);
    length = strlen(str);

    s.size = length;

    s.arr = (int *)malloc(sizeof(int) * s.size);

    for ( i = 0; i < length; i++)
    {
        ch = str[i];

        switch (ch)
        {
        case '(':
            push(ch);
            break;
        case '[':
            push(ch);
            break;
        case '{':
            push(ch);
            break;
        case ')':
            if(!(peek()=='(')){
                flag=1;
            }
            else{
                x=pop();
                printf("%c\n",x);
            }
            break;
    case ']':
            if(!(peek()=='(')){
                flag=1;
            }
            else{
                x=pop();
                printf("%c\n",x);
            }
            break;

            case '}':
            if(!(peek()=='{')){
                flag=1;
            }
            else{
                x=pop();
                printf("%c\n",x);
            }
            break;


        default:
        if(flag==1)
            break;
        }
    }
    if(flag==1)
        printf("unbalanced");

        else if(i==length && isEmpty)
        printf("balanced");

        else
        printf("unbalanced");
}