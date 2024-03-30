// Calculate the average of given by user  numbers also count the num  then find average


#include <stdio.h>
int main()
{
   
 double sum=0.0;double num;
 int count=0;

 printf("Enter  numbers type -1 to stop: ");
 

while(scanf("%lf",&num)==1 && num>=-1){
if(num>0){
    sum+=num;
    count++;
}
//printf("Enter a number -1 to stop\n");
}

if(count>0){
    printf("Average \n",sum/count);
}
else{
    printf("No valid inputs \n");
}

return 0;
}