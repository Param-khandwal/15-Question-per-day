// Check the enter character is vowel or consonants

#include<stdio.h>
int main(){

	char ch;
	printf("Enter character of your choice\n");
	scanf("%c",&ch);
	if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'){
	printf("Enter character is vowel");
	}
	else if(ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U'){
	printf("Enter characte is vowel");
	}
	else{
	printf("Enter characte is consonants");
	}
	
	return 0;
}
