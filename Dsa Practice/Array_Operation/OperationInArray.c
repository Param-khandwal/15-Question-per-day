#include <stdio.h>
#include <stdlib.h>

// Traversal array
void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }
}

// Insertion array

int Insert(int arr[], int size, int element, int capacity, int index)
{
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    display(arr, size);
}