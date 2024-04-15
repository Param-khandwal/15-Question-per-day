#include<stdio.h>

void swap(int a[],int i, int j){
    int temp=a[i];
    a[i]=a[j];
    a[j]=temp;
}

int main(){
    int n;
    printf("Enter size");
    scanf("%d",&n);

    int arr[n];
    printf("Enter the arr elem\n");
    for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
    }

    printf("Element of the array\n");
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }

    //selection sort
    int min;
    printf("swapping\n");
    for(int i=0;i<n;i++){
        min=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        swap(arr,i,min);
    }

    printf("Element of the array\n");
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
}