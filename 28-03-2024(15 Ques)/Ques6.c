#include <stdio.h>

int main()
{
    int rem, num, sum = 0, c;
    printf("Enter the number of your choice\n");
    scanf("%d", &num);


int originalNum=num;

    while (num != 0)
    {
        rem = num % 10;
        c = rem * rem * rem;
        sum = sum + c;
        num = num / 10;
    }
    printf("sum %d\n", sum);




    if (sum == originalNum)
        printf("Armstrong number\n");
    else
        printf("Not an Armstrong number\n");

    return 0;
}