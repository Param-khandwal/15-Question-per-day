#include<stdio.h>
int main()
{
    int arr[]={1,2,2,3,4,5,2,6};
    int index=-1;
    for(int i=0;i<8;i++){
        if(arr[i]==2)
        index=i;
    }
        printf(" Element 2 is present  at last index = %d\t ",index);
         return 0;
}