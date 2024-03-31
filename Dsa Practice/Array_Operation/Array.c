#include <stdio.h>
#include <stdlib.h>
// #define myArr[100]

int main()
{
    int *p, n, i;
    printf("Enter the number of int to be entered");
    scanf("%d", &n);
    p = (int *)malloc(n * sizeof(int));

    if (p == NULL)
    {
        printf("memory not available");
        exit(1);
    }

    for (int i = 0; i < n; i++)
    {
        printf("enter integer :  ");
        scanf("%d",&p[i]);
    }

    for (int i = 0; i < n; i++)
    {

        printf("%d\t", p[i]);
    }
}