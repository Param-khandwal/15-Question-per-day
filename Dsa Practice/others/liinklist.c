#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *start = NULL;

void traverse()
{
    struct node *temp;
    if (start == NULL)
    {
        printf("List is Empty");
    }

    else
    {
        temp = start;
        while (temp != NULL)
        {
            printf("Data=%d\n", temp->data);
            temp = temp->next;
        }
    }
}

void insertAtBeg(int ele)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter the number you wnat to insert ");
    scanf("%d", &ele);

    temp->data = ele;
    temp->next = start;
    start = temp;
}

void insertAtEnd(int ele)
{
    struct node *temp, *head;
    temp = (struct node *)malloc(sizeof(struct node)); // newnode

    printf("Enter the number you wnat to insert ");
    scanf("%d", &ele); // take input from the user

    temp->next = 0;
    temp->data = ele;
    head = start;              // making a new  start of ll
    while (head->next != NULL) // loop will run when head will null
    {
        head = head->next;
    }
    head->next = temp; // now head is tn last and add element
}

void insertAtPosition(int pos, int ele)
{
    int i=1;
    struct node *temp, *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("\nEnter position and data :");
    scanf("%d %d", &pos, &ele);

    temp=start;
    newnode->data=ele;
    newnode->next=0;

    while(i < pos-1){
        temp=temp->next;
        i++;
    }
    newnode->next=temp->next;
    temp->next=newnode;
}
int main()
{

    traverse();
}