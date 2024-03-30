
#include <stdio.h>
int main()
{

    int num1, num2, num3;
    printf("Enter the first number");
    scanf("%d", &num1);
    printf("Enter the second number");
    scanf("%d", &num2);
    printf("Enter the third number");
    scanf("%d", &num3);



    if (num1 > num2 && num1 > num3)
    {
        printf("%d is greater \n", num1);
    }
    else if (num2 > num1 && num2 > num3) 
    {
        printf("%d is greater \n", num2);
    }
    else if (num3 > num2 && num3 > num1) 
    {
        printf("%d is greater \n", num3);
    }
    else
    {
        printf("All are equal");
    }

    if(num1 < num2 && num1 < num3)
    {
        printf("%d is smaller \n", num1);
    }
    else if (num2 < num1 && num2 < num3)
    {
        printf("%d is smaller \n", num2);
    }
    else if (num3 < num2 && num3 < num1)
    {
        printf("%d issmaller \n", num3);
    }
    else
    {
        printf("All are equal");
    }



    return 0;
}
 //////////other method

/*
#include <stdio.h>

int main()
{
    int num1, num2, num3;
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);
    printf("Enter the third number: ");
    scanf("%d", &num3);

    // Check for the largest and smallest numbers
    if (num1 > num2)
    {
        if (num1 > num3)
        {
            printf("%d is the largest and %d is the smallest \n", num1, (num2 > num3) ? num2 : num3);
        }
        else
        {
            printf("%d is the largest and %d is the smallest \n", num3, (num1 < num2) ? num1 : num2);
        }
    }
    else
    {
        if (num2 > num3)
        {
            printf("%d is the largest and %d is the smallest \n", num2, (num1 > num3) ? num1 : num3);
        }
        else
        {
            printf("%d is the largest and %d is the smallest \n", num3, (num1 < num2) ? num1 : num2);
        }
    }

    return 0;
}


*/