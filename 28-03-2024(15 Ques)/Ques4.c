#include <stdio.h>

int sum(int num)
{
    int sum1 = 0;
    for (int i = 1; i <= num; i++)
    {
        sum1 += i;
    }
    return sum1;
}

int sum2(int num){

    return (num*(num+1))/2;
}

int main()
{

    int num;
    printf("enter the num\n");
    scanf("%d", &num);

    printf("%d\n", sum(num));
    printf("%d\n",sum2(num));

    return 0;
}