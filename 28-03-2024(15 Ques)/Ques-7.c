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
        sum = sum*10 + rem;
        num = num / 10;
    }
    printf("sum %d\n", sum);

return 0;

}