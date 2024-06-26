#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *start;

void insertAtBeg(int ele)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = ele;
    temp->next = start; // Corrected assignment
    start = temp;
}

void insertAtEnd(int ele)
{
    struct node *temp, *curr;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = ele;
    temp->next = NULL;

    if (start == NULL)
    {
        start = temp;
    }
    else
    {
        curr = start;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = temp;
    }
}

void insertAfter(int ele, int search)
{
    struct node *temp, *curr;
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
            free(temp); // Free the allocated memory
        }
    }
    else
    {
        printf("list is empty");
        free(temp); // Free the allocated memory
    }
}

void insertBefore(int ele, int search)
{
    struct node *temp, *curr;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = ele;

    if (start != NULL)
    {
        if (start->data == search)
        {
            temp->next = start;
            start = temp;
        }
        else
        {
            curr = start;
            while (curr->next != NULL && curr->next->data != search)
            {
                curr = curr->next;
            }
            if (curr->next != NULL)
            {
                temp->next = curr->next;
                curr->next = temp;
            }
            else
            {
                printf("element not found");
                free(temp); // Free the allocated memory
            }
        }
    }
    else
    {
        printf("list is empty");
        free(temp); // Free the allocated memory
    }
}

int deleteFirst()
{
    int x = -999;
    struct node *temp;
    if (start != NULL)
    {
        temp = start;
        x = temp->data;
        start = temp->next;
        free(temp);
    }
    else
    {
        printf("list is empty");
    }
    return x;
}

int deleteLast()
{
    int x = -999;
    struct node *temp, *curr;
    if (start != NULL)
    {
        curr = start;
        if (curr->next == NULL)
        {
            temp = start;
            x = start->data;
            start = NULL;
            free(temp);
        }
        else
        {
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
        printf("List is empty");
    }
    return x;
}

int deletePos(int search)
{
    int x = -999;
    struct node *temp, *curr;

    if (start != NULL)
    {
        if (start->data == search)
        {
            temp = start;
            start = temp->next;
            x = temp->data;
            free(temp);
        }
        else
        {
            curr = start;
            while (curr->next != NULL && curr->next->data != search)
            {
                curr = curr->next;
            }
            if (curr->next != NULL)
            {
                temp = curr->next;
                curr->next = temp->next;
                x = temp->data;
                free(temp);
            }
            else
            {
                printf("Element not found");
            }
        }
    }
    else
    {
        printf("List is empty");
    }
    return x;
}

void displayFor()
{
    struct node *temp;
    temp = start;
    if (start == NULL)
    {
        printf("No element in the list");
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
    }
}

void displayBack()
{
    if (start != NULL)
    {
        funcf(start);
    }
    else
    {
        printf("List is empty");
    }
}

void funcf(struct node *curr)
{
    if (curr != NULL)
    {
        funcf(curr->next);
        printf("%d\t", curr->data);
    }
}

void reverse()
{
    struct node *temp, *rev;
    rev = NULL;
    while (start != NULL)
    {
        temp = start;
        start = temp->next;
        temp->next = rev;
        rev = temp;
    }
    start = rev;
}

int main()
{
    start = NULL;
    insertAtBeg(45);
    insertAtEnd(45);
    insertAtEnd(15);
    insertAtEnd(25);
    insertAtEnd(65);
    deletePos(65);

    displayFor();
    displayBack();
}
