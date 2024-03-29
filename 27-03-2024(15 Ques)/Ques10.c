// Calcul;ate the LCm of two numbers
#include<stdio.h>
#include<math.h>
int main(void)
{ 
        int a,b,x,y;
	printf("Enter the two number which you want to take lcm a and b");
	scanf("%d%d",&a,&b);
	//a=10 b=12 lcm=60
		
	x=a;  // x=10
	y=b;  // y=12
	
		while(a!=b){
		if(a<b)
		a=a+x;
		else
		b=b+y;     
  		}
	 printf("LCM of two number is %d %d %d",x,y,a);



}
