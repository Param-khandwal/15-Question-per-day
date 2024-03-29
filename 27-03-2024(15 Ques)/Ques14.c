//print   all alphabet a to z 
 #include<stdio.h>
int main(){

	int ch;
	printf("Enter your choice which alphabet you want to print\n 1-Lowercase 2-Uppercase\n");
	scanf("%d",&ch);
//	printf("All aplhabets\n");
	
	switch(ch)
	case1:	
	      for(int i=65;i<=90;i++){
            	printf("%c\t   ",i);
	       }
		
		
	case2:	
	      for(int j=97;j<=122;j++){
            	printf("%c\t  ",j);
	       }
	
		
return 0;







}
