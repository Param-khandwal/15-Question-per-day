// Table of any number

 #include<stdio.h>
int main(){

	int table,num;
	printf("Enter any number of table you want to print");
	scanf("%d",&num);
	
	for(int i=1;i<=10;i++){
	table=num*i;
	printf("%d*%d=%d\n ",num,i,table);
	}
	








}
