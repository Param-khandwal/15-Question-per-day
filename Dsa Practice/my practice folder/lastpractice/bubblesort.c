#include <stdio.h>

void swap(int a[], int i, int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}
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

    // bubble sort
    int flag;
    for (int i = 0; i < n-1; i++)
    {  flag=0;
        for (int j = 0; j < n-1-i; j++)
        {
            if (arr[j] > arr[j+1])
            {
                swap(arr, j, j+1);
                flag=1;
            }
        }
    }

    printf(" element of array");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
}