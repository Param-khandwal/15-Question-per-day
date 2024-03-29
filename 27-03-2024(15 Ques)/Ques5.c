#include<stdio.h>
#include<string.h>
int main()
{

int a,b,c;

	printf("Enter the value of a\n");
	scanf("%d",&a);
	printf("Enter the value of b\n");
	scanf("%d",&b);
	
	printf("Before Swapping\n a=%d and b=%d ",a,b);
	c=a; //c=10
	a=b; //a=20
	b=c; //b=10
	
	printf("After Swapping\n a=%d and b=%d ",a,b);
	

}