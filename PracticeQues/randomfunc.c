#include <stdio.h>

#define SIZE 100

int main()
{
    int arr[SIZE], i;
    printf("Enter the number of integers (up to %d): ", SIZE);
    scanf("%d", &i);
    for(int j = 0; j < i; j++)
    {
        printf("Enter the %d th integer: ", j+1);
        scanf("%d", &arr[j]);
    }
    for(int j = 0; j < i; j++)
    {
        printf("%d ", arr[j]);
    }
    printf("\n");
    return 0;
}