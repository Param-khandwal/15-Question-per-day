#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n1,n2,arr1[100]={0},arr2[100]={0},i,c[100];

    printf("Size of Array 1 \n");
    scanf(" %d",&n1);


        printf("Size of array 2 \n");
            scanf(" %d",&n2);


    printf("Enter the elements of array 1\n");

    for(i=0;i<n1;i++)
    {
        scanf(" %d",&arr1[i]);
    }


    printf("Enter the elements of array 2\n");

    for(i=0;i<n2;i++)
    {
        scanf(" %d",&arr2[i]);
    }


   if(n1>=n2)
   {
       for(i=0;i<n1;i++)
           c[i]=arr1[i]+arr2[i];
   }
   else
   {
       for(i=0;i<n2;i++)
           c[i]=arr1[i]+arr2[i];

   }

   printf("Array after sum\n");

if(n1>=n2)
   {
       for(i=0;i<n1;i++)
           printf("%d\n",c[i]);
   }
   else
   {
       for(i=0;i<n2;i++)
           printf("%d\n",c[i]);
   }
return 0;
}