#include <stdio.h>
#define size 100
int main()
{
    int arr[]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(arr[0]) ;

    // left Rotate
    // int save=arr[0];
    // for(int i=0;i<5;i++){
    //  arr[i]=arr[i+1];
    // }
    // arr[5]=save;


    // Right Rotate
    int save = arr[n-1];
    for (int i = n-1; i > 0; i--)
    {
       arr[i] =  arr[i-1];
    }
    arr[0]=save;

    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
}