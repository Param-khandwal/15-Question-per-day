#include<stdio.h>
// #define arr [100]
int main(){

    int target=6;
    
     int arr[5]={1,2,3,4,5};

    for(int i=0;i<5;i++){
        for(int j=i+1;j<5;j++){
            if(arr[i]+arr[j]==target){
                printf("arr[i]=%d arr[j]=%d\n",arr[i],arr[j]);
            }
        }
    }
    return 0;
}
