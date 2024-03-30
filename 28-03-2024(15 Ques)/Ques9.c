#include <stdio.h>

int fib(int n){

    if(n==0||n==1)
        return 1;
    
        return fib(n-1)+fib(n-2);
    
  
}

int main()
{
    int num;
printf("Enter any number\n");
scanf("%d",&num);
    
    for(num=1;num>0;num++){
    printf("%d\t",fib(num));
    }
return 0;



}