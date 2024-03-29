// calculate the prime numbers compound interest 
// Ci=principle*pow((1+rate/100),time)
#include<stdio.h>
#include<math.h>
int main()
{        
 	int time;
        double amount,principle,rate;
	printf("Enter the time period\n");
	scanf("%d",&time);
	
	printf("Enter the principle you want to calculate CI \n");
	scanf("%lf",&principle);
	
	printf("Enter the rate you want to calculate CI \n");
	scanf("%lf",&rate);
	
	amount=principle*pow((1+rate/100),time);

	printf("Amount for the given principle is %lf",amount);

	return 0;
}
