#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *start;

void insertAtBeg(int elem)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = elem;
    temp->prev = NULL;
    if (start == NULL)
    {
        temp->next = NULL;
        start = temp;
    }
    else
    {
        temp->next = start;
        start->prev = temp;
        start = temp;
    }
}

void insertAtEnd(int elem)
{
    struct node *temp, *curr;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = elem;
    temp->next = NULL;

    if (start == NULL)
    {
        temp->prev = NULL;
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
        temp->prev = curr;
    }
}

void insertAfter(int elem, int search)
{
    struct node *temp, *curr;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = elem;
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
            if (curr->next != NULL)
            {
                curr->next->prev = temp;
            }
            curr->next = temp;
            temp->prev = curr;
        }
        else
        {
            printf("Element not found");
        }
    }
    else
    {
        printf("List is empty");
    }
}

void insertBefore(int elem, int search)
{
    struct node *temp, *curr;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = elem;
    if (start != NULL)
    {
        if (start->data == search)
        {
            temp->next = start;
            start->prev = temp;
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
                curr->next->prev = temp;
                curr->next = temp;
                temp->prev = curr;
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
}


int deleteFirst()
{
    int x = -1;
    if (start != NULL)
    {
        struct node *temp = start;
        start = start->next;
        if (start != NULL)
        {
            start->prev = NULL;
        }
        x = temp->data;
        free(temp);
    }
    return x;
}

int deleteLast()
{
    int x = -1;
    if (start != NULL)
    {
        struct node *curr = start;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        if (curr->prev != NULL)
        {
            curr->prev->next = NULL;
        }
        else
        {
            start = NULL;
        }
        x = curr->data;
        free(curr);
    }
    return x;
}

void deleteSpec(int search)
{
    // Implement this function
}

void displayForw()
{
    struct node *curr = start;
    while (curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

void displayBack()
{
    struct node *curr = start;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    while (curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->prev;
    }
    printf("\n");
}

void Reverse()
{
    // Implement this function
}

int main()
{
    start = NULL;
    insertAtBeg(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAtBeg(5);

    printf("List Forward: ");
    displayForw();

    printf("List Backward: ");
    displayBack();

    int deletedFirst = deleteFirst();
    printf("Deleted First: %d\n", deletedFirst);
    printf("List After Deleting First: ");
    displayForw();

    int deletedLast = deleteLast();
    printf("Deleted Last: %d\n", deletedLast);
    printf("List After Deleting Last: ");
    displayForw();

    return 0;
}
