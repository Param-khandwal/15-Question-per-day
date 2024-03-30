#include<stdio.h>
int eveNum(int num)
{
    if (num > 0)
    {
        eveNum(num - 1);
        printf("%d\t", (( num * 2) + 1));
    }
}
int main()
{
    int num;
    printf("Enter a number of your choice");
    scanf("%d", &num);

    eveNum(num);
}