#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    char *items;
    int size;
    int top;
};

struct stack s;

int precedence(char);
int peek();
void push(char);
char pop();
int is_empty();
int is_full();
void display();

int precedence(char ch)
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
    default:
        return 0;
    }
}

int peek()
{
    if (!is_empty())
    {
        return s.items[s.top];
    }
    else
    {
        printf("Stack is empty\n");
        return -1;
    }
}

void push(char c)
{
    if (!is_full())
    {
        s.items[++s.top] = c;
    }
    else
    {
        printf("Stack is full\n");
    }
}

char pop()
{
    if (!is_empty())
    {
        return s.items[s.top--];
    }
    else
    {
        printf("Stack is empty\n");
        return '\0';
    }
}

int is_empty()
{
    return (s.top == -1);
}

int is_full()
{
    return (s.top == s.size - 1);
}

void display()
{
    for (int i = 0; i <= s.top; i++)
    {
        printf("%c ", s.items[i]);
    }
    printf("\n");
}

int main()
{
    s.items = NULL;
    s.top = -1;
    char expr[50], ch;
    int length = 0, j = 0;

    printf("Enter the expression: ");
    scanf("%s", expr);
    length = strlen(expr);

    s.size = length;
    s.items = (char *)malloc(s.size);

    char result[length];
    for (int i = 0; i < length; i++)
    {
        ch = expr[i];
        switch (ch)
        {
        case '(':
        case '[':
        case '{':
            push(ch);
            break;
        case '+':
        case '-':
        case '*':
        case '/':
            while (!is_empty() && precedence(peek()) >= precedence(ch))
            {
                result[j++] = pop();
            }
            push(ch);
            break;
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
            result[j++] = ch;
            break;
        }
    }

    while (!is_empty())
    {
        result[j++] = pop();
    }

    result[j] = '\0'; // Null terminate the result string
    printf("Postfix expression: %s\n", result);

    free(s.items);
    return 0;
}
