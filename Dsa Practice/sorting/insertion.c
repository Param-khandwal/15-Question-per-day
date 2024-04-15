#include <stdio.h>
#include <stdlib.h>
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

    //insertion sort
int temp,j;
    for(int i=1;i<n;i++){
        temp=arr[i];
                j=i-1;
            while(temp<arr[j]){
                arr[j+1]=arr[j];
                j--;
            }
        arr[j+1]=temp;
    }

     printf(" element of array");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }

}