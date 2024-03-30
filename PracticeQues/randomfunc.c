#include <stdio.h>
int add(int a, int b)
{
    return (a + b);
}
int sub(int a, int b)
{
    if (a > b)
        return (a - b);
    else
        return (b - a);
}
int mul(int a, int b)
{
    return (a * b);
}

int div(int a, int b)
{
    if (b == 0)
        return -1;
    else
        return (a / b);
}

int mod(int a, int b)
{
    return (a % b);
}

int main()
{

    int x , y,res ;
    char ch;
    printf("Enter the first number\n");
    scanf("%d",&x);
    printf("Enter the second number\n");
    scanf("%d",&y);
    printf("Enter your choice:\n '+'\n '-'\n '*'\n '/'\n ");
    scanf("%c",&ch);
    switch (ch)
    {
    case '+':   res=add(x,y);
                printf(" %d ", res);
                 break;

    case '-':    printf(" %d ", sub(x, y));
                 break;

    case '*':
        printf(" %d ", mul(x, y));
        break;

    case '/':
        printf(" %d ", div(x, y));
        break;

    case '%':
        printf(" %d ", mod(x, y));
        break;
    default:
        printf("\nInvalid Input!!!\n");
    }
    return 0;
}