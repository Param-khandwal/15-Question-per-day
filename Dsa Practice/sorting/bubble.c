#include <stdio.h>
#include <stdlib.h>

int swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
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
int  flag;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-1-i  ; j++)
        {
               flag=0;
            while (arr[j] > arr[j+1])
            {
                swap(arr, j, j+1);
                flag=1;
            }
        
        }
        if(flag==0)
        break;
    }

    printf(" element of array after sorting");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    return 0;
}