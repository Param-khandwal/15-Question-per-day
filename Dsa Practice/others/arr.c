#include<stdio.h>
int ans=0;

int sum(int num){
if(num<10){
    return num;    
}   

while(num!=0){
    int rem=num%10;
    ans=ans+rem;
    num=num/10;
    }
    printf("%d",ans);
    num=ans;
    return sum(num);

   // return ans;
}
int main(){
    int num;
    printf("Enter the number: ");
    scanf("%d",&num);
    int a=sum(num);
    printf("answer is : %d",a);

    
}