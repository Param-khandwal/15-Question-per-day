#include<stdio.h>
#include<stdlib.h>

struct node{
	int data ;
	struct node*next;
};

struct node *start;

void insertAtBeg(int ele){
	struct node*temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=ele;
	temp->next=start;
	start=temp;
}

void insertAtLast(int ele){
	struct node*temp,*curr;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=ele;
	temp->next=NULL;
	
	if(start==NULL){
		start=temp;
	}
	else{
		curr=start;
	   while(curr!=NULL){
	    curr=curr->next;
	   }
	   curr->next=temp;
	}
}

void insertafter(int ele,int selec){
	struct node*temp,*curr;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=ele;
	if(start!=NULL){
		curr=start;
		while(curr!=NULL && curr->data!=selec){
		curr=curr->next;
		}
		if(curr!=NULL){
		temp->next=curr->next;
		curr->next=temp;
		}
		else{
		printf("Element not found\n");
		}
	}	
	else{
	printf("list is empty\n");
	}
}

void insertbefore(int ele,int selec){
	struct node*temp,*curr;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=ele;
	if(start!=NULL){
	  if(start->data==selec){
	  	temp->next=start;
	  	start=temp;
	  }
	  else{
	  curr=start;
	  while(curr->next!=NULL && curr->next->data!=selec){
	  curr=curr->next;
	  }
	  if(curr->next!=NULL){
	     temp->next=curr->next;
	     curr->next=temp;
	  }
	  else{
	  printf("Element not found ");
	  }
	  }
	}
	else{
	printf("List is empty ");
	}
}

int deleteFirst(){
	int x=-999;
	struct node*temp;
	
	if(start!=NULL){
	   x=temp->data;
	   start=temp->next;
	   free(temp);
	   temp=NULL;
	}
	else{
        printf("List is empty");
    return x;
}
}

int deleteLast(){
	int x=-999;
	struct node*temp,*curr;
	
	if(start!=NULL){
		if(start->next!=NULL){
			temp=start;
			x=temp->next;
			start=NULL;
			free(temp);
		}
		else{
		curr=start;
		while(curr->next->next!=NULL){
			curr=curr->next;
		}
			x=temp->data;
			curr->next=NULL;
			free(temp);
		}
	}
	
}

int deletAtSpecfic(int sele){
	if(start!=NULL){
		if(start->data==sel){
		temp=start;
		start=temp->next;
		free(temp);
		temp=NULL;
		}
	else{
	curr=start;
	while(curr->next!=NULL && curr->next->data!=sele)
	 curr=curr->next;
	}
	if(curr->next!=NULL){
	temp=curr->next;
	curr->next=temp->next;
	free(temp);
	temp=NULL;
	}
	else {
	printf("not found");
	}
	}
	else{
	printf("lsit is empty ")
	}
}

void display(){
	struct node*curr;
	curr=start;
	while(curr!=NULL){
	printf("%d\n",curr->data);
	curr=curr->next;
	}

}

int main(){
  start=NULL;
  
  insertAtBeg(5);
//  insertafter(15,5);
insertbefore(10,5);
    insertAtBeg(15);
  display();
}
