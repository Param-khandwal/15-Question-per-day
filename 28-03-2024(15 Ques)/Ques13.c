#include <stdio.h>
int main()
{
    int num, sum = 0;
    printf("Enter a number\n");
    scanf("%d", &num);

    for (int i = 1; i < num; i++)
    {
        if (num % i == 0)
        {
            printf("%d ", i);
            sum += i;
        }
    }

    if (num == sum)
        printf("\nIt is a perfect number");
    else
        printf("It is nor a perfect number");
    return 0;
}
