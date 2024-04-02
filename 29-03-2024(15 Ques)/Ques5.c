// Wap a program to calculate power witht using recursion

#include<stdio.h>
int  power(int base, int n){
    if (n == 0) 
    return 1;
   
    else
    return  base * power(base, n-1);

}
int main(){
    int  b  , p ;
    printf("Enter the Base Number : ");
    scanf("%d", &b );

    printf("Enter the Power Number : ");
    scanf("%d",&p);

    printf("%d",power(b,p));
}