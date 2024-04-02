#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr = NULL; // Pointer to dynamically allocated array
    int size = 0; // Current size of the array
    int capacity = 0; // Current capacity of the array

    int element, position;

    // Input array size
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Allocate memory for the array
    capacity = size; // Set initial capacity equal to size
    arr = (int *)malloc(capacity * sizeof(int));

    // Input array elements
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Input element to insert
    printf("Enter the element to insert: ");
    scanf("%d", &element);

    // Input position to insert
    printf("Enter the position to insert the element (0-indexed): ");
    scanf("%d", &position);

    // Check if position is valid
    if (position < 0 || position > size) {
        printf("Invalid position for insertion.\n");
        return 1; // Exit with error code
    }

    // Check if array is full, resize if needed
    if (size == capacity) {
        capacity *= 2; // Double the capacity
        arr = (int *)realloc(arr, capacity * sizeof(int));
        if (arr == NULL) {
            printf("Memory reallocation failed.\n");
            return 1; // Exit with error code
        }
    }

    // Shift elements to the right to make space for the new element
    for (int i = size; i > position; i--) {
        arr[i] = arr[i - 1];
    }

    // Insert the element at the specified position
    arr[position] = element;
    size++; // Increment the size of the array

    // Print the updated array
    printf("Array after insertion:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Free dynamically allocated memory
    free(arr);

    return 0;
}
