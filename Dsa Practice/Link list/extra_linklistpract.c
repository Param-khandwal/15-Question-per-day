#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void linklisttraver(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf(" Element %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct node *insertatBeg(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}

struct node *insertAtIndex(struct node *head, int data, int index)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    int i=0;
    while (i != index-1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;

    return head;
}

void insertatEnd(struct node *p)
{
}

void Insertafternode()
{
}
int main()
{
    struct node *head, *second;
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    head->data = 7;
    head->next = second;

    second->data = 12;
    second->next = NULL;

    // head=insertatBeg(head,56);
    // head=insertatBeg(head,45);

    head = insertAtIndex(head, 45, 1);
    head = insertAtIndex(head, 55, 1);
    linklisttraver(head);
}