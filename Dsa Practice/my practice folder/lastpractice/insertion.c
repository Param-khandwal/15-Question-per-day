#include <stdio.h>

int main()
{
    int n;
    printf("Enter the size of the array");
    scanf("%d", &n);
    int arr[n];

    printf("Enter the element in array");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf(" element of array");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }

    // insertion  sort
    

    printf(" element of array");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
}