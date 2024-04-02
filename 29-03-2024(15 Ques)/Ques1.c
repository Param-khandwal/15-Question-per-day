//power of the  number 

#include<stdio.h>
int main(){
  int base,power,result=1;
  printf("Enter the power=\n and the base\n");
  scanf("%d %d",&base,&power);
  for(int i=1;i<=power;i++){
    result*=base;
  }
    printf("%d",result);


return 0;
}