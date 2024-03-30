// Program to calculate the average of a set of numbers entered by the user.

#include<stdio.h>
int main()
{
  int arr[5]={1,2,3,4,5};
  int sum=0;
  float avg;

  for(int i=0;i<5;i++){
    sum=sum+arr[i];
  }
   avg=sum/5;
   printf("The average of array %f",avg);

}