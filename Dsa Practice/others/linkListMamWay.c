#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *start;

void insertAtBeg(int elem)
{
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = elem;
    new_node->next = start;
    start = new_node;
}

void insertEnd(int elem)
{
    struct node *current, *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = elem;
    temp->next = NULL;

    if (start == NULL)
    {
        start = temp;
    }
    else
    {
        current = start;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = temp; // Update the next pointer of the last node to point to the new node
    }
}

void insert_after(int ele, int search)
{
    struct node *curr, *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = ele;

    if (start != NULL)
    {
        curr = start;
        while (curr != NULL && curr->data != search)
        {
            curr = curr->next;
        }
        if (curr != NULL)
        {
            temp->next = curr->next;
            curr->next = temp;
        }
        else
        {
            printf("Element not found");
        }
    }
    printf("List is empty");
}

void insertBefore(int ele, int search)
{
    struct node *curr, *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = ele;

    if (start != NULL)
    {
        curr = start;
        while (curr->next != NULL && curr->next->data != search)
        {
            curr = curr->next;
        }
        if (curr != NULL)
        {
            temp->next = curr->next;
            curr->next = temp;
        }
        else
        {
            printf("Element not found");
        }
    }
    printf("List is empty");
}

int deleteFirst()
{
    int x = -99;
    struct node *temp;
    if (start != NULL)
    {
        temp = start;
        x = temp->data;
        start = temp->next;
        free(temp);
        temp = NULL;
    }
    else
    {
        printf("List is Empty");
    }
}

int deleteEnd()
{
    int x = -99;
    struct node *temp, *curr;
    if (start != NULL)
    {
        if (start->next == NULL)
        {
            temp = start;
            x = start->data;
            start = NULL;
            free(temp);
        }

        else
        {
            curr = start;
            while (curr->next->next != NULL)
            {
                curr = curr->next;
            }
            temp = curr->next;
            x = temp->data;
            curr->next = NULL;
            free(temp);
        }
    }
    else
    {
        printf("list is empty");
    }
    return x;
}

void deleteAtspecific(int search)
{
    struct node *temp, *curr;
    if (start != NULL)
    {
        if (start == search)
        {
            temp = start;
            start = temp->next;
            free(temp);
            temp = NULL;
        }
        else{
            curr=start;
            while(curr->next !=NULL && curr->next->data !=search)
            curr=curr->next;

            if(curr->next!=NULL){
                temp=curr->next;
                curr->next=temp->next;
                free(temp);
                temp=NULL;
            }
            else{
                printf("Element not found");
            }
        }
    }
    else{
        printf("List is empty");
    }
}

void display()
{

    struct node *curr;
    curr = start;
    printf("List element are \n");
    while (curr != NULL)
    {
        printf(" %d---> ", curr->data);
        curr = curr->next;
    }
}

int main()
{

    start = NULL;

    insertAtBeg(45);
    insertEnd(5);
    // insert_after(12,5);
    insertBefore(12, 5);

    // deleteFirst();
    deleteEnd();

    display();
}
