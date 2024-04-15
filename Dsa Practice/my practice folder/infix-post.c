#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int size;
    int top;
    int *opstr;
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
        printf("Stack is full");
    }
    else
    {
        s.opstr[s.top++] = ele;
    }
}

char pop()
{
    int x = -99;
    if (isEmpty())
    {
        printf("There is no element in the stack");
    }
    else
    {
        x = s.opstr[s.top--];
    }
}

char peek()
{

    if (isEmpty())
    {
        printf("There is no element in the stack");
    }
    else
    {
        return s.opstr[s.top];
    }
}

int prec(char ch)
{

    switch (ch)
    {
    case '*':
    case '/':
        return 3;
    case '+':
    case '-':
        return 2;
    case '(':
    case '[':
    case '{':
        return 1;
        break;
    }
}

void display()
{
    for (int i = 0; i <= s.top; i++)
    {
        printf("%d", s.opstr[i]);
        printf("\n");
    }
}

int main()
{
    s.opstr = NULL;
    s.top = -1;
    
    char expr[50], ch;
    int length = 0, j = 0;


    printf("Enter the expression:");
    scanf("%s", expr);
    length = strlen(expr);

    s.size = length;
    s.opstr = (char *)malloc(s.size);

    char result[length];

    for (int i = 0; i < length; i++)
    {
        switch (ch)
        {
        case '(':
            break;
        case '[':
            break;
        case '{':
            push(ch);
            break;
        case '+':
        case '-':
        case '*':
        case '/':
            if (!isEmpty())
            {
                while (!isEmpty() && prec(peek()) >= prec(ch))
                    ;
                {
                    result[j++] = pop();
                }
                push(ch);
            }
        case ')':
        case ']':
        case '}':
            while (peek() != '(' && peek() != '[' && peek() != '{')
            {
                result[j++] = pop();
            }
            pop(); // Discard the opening bracket
            break;

        default:
            result[j++]=ch;
            break;
        }
    }

    while (!isEmpty())
    {
        result[j++] = pop();
    }

    result[j] = '\0'; // Null terminate the result string
    printf("Postfix expression: %s\n", result);

    free(s.opstr);
    return 0;
}