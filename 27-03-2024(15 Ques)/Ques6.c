#include<stdio.h>
#include<string.h>
int main()
{

int a,b;

	printf("Enter the value of a\n");
	scanf("%d",&a); // 10
	printf("Enter the value of b\n");
	scanf("%d",&b); //20
	
	
	printf("Before Swapping\n a=%d and b=%d ",a,b);
	a=a+b; //a=10+20=30
	b=a-b; //b=30-10=20  
	a=a-b; //a=30-20=10
	
	printf("After Swapping\n a=%d and b=%d ",a,b);
	
	  
	}
