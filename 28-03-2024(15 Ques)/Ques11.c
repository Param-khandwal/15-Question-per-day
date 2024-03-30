#include <stdio.h>
int main()
{
    int num, sum = 0, rem, sq;
    printf("Enter a number\n");
    scanf("%d", &num);

    sq = num * num;
    printf(" Square of a num %d\n",sq);

    while (sq != 0)
    {
        rem = sq % 10;
        sum = rem + sum;
        sq = sq / 10;
    }
    if (sum == num)
        printf("\nThe given number is a neon number\n");
    else
        printf("\nThe given number is not a neon number");
}