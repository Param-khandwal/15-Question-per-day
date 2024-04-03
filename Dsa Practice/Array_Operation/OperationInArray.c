#include <stdio.h>
#include <stdlib.h>

struct myArray
{
    int total_size; // total size of the array
    int used_size;  // used size of the array
    int *ptr;
};

void createArr(struct myArray *a, int tsize, int usize)
{
    a->total_size = tsize;
    a->used_size = usize;
    a->ptr = (int *)malloc(tsize * sizeof(int));
} // creation of array using malloc

void show(struct myArray *a)
{

    for (int i = 0; i < a->used_size; i++)
    {
        printf("%d", (a->ptr[i]));
    }
} // end of the display function

int insertion(struct myArray *a, int n, int usize, int tsize,int element)
{
    if (usize >= tsize)
    {
        return -1;
    }
    for (int i = 0; i < a->used_size; i++)
    {
        (a->ptr)[i+1]=((a)->ptr)[i];
    }
    ((a)->ptr)[usize] = element;
    a->used_size++;
    return 1;
}

void inputValue(struct myArray *a)
{
    int n;
    for (int i = 0; i < a->used_size; i++)
    {
        printf("Enter the element %d ", i);
        scanf("%d", &n);
        (a->ptr)[i] = n;
    }
}

int main()
{
    struct myArray arr;
    createArr(&arr, 5, 3);
    printf("The elements are:\n");
    inputValue(&arr);
    insertion(&arr,5,2,4,-9);
    show(&arr);
    return 0;
}