
//Write a function to print a given character for a given number of times
#include<stdio.h>

 void print_char(int n, char c){
    while(n--){
        printf("%c", c);
    }
 }
int main(){
    int n; char c;
    printf("Enter a number how many times you want to print character \n" );
    scanf("%d", &n);
    printf("\nEnter a character:\n ");
    scanf(" %c",&c);
    print_char(n,c);
}