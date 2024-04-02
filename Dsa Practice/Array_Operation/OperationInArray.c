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
   createArr(&arr,5,3);
   printf("The elements are:\n");
   inputValue(&arr);
   show( &arr );
   return 0;

}