//Write a function to print a given number in binary format.
#include<stdio.h>

int bin(int n){
    int size = sizeof(int) * 8;
    for(int i=size-1;i>=0;i--){
        if((n>>i) & 1)
        printf("1");
        else
        printf("0");
    }

}
int main(){
 int num;   
    scanf("%d",num);

    bin(num);
    return 0;

}