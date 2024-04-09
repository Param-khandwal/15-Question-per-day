#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *start;
void insert_beg(int);
void insert_end(int);
void insert_after(int, int);
void insert_before(int, int);
int delete_f();
int delete_l();
void delete_spec(int);
void trave_for();
void trave_back();
void insert();
void delete();
void traverse();
void funpf();
void insert_beg(int ele)
{
    struct node *temp;                                 // temp initilization
    temp = (struct node *)malloc(sizeof(struct node)); // memory allocation
    temp->data = ele;                                  // setting the data to the input value
    temp->next = start;                                // pointer address of next element from start
    start = temp;                                      // passing address of temp to start
}
void insert_end(int ele)
{
    struct node *temp, *curr;                          // initialize temp and curr
    temp = (struct node *)malloc(sizeof(struct node)); // reserving memory for temp
    temp->data = ele;                                  // data assignment
    temp->next = NULL;                                 // setting temp next address to null since its the last element
    if (start == NULL)                                 // no element in the list
        start = temp;                                  // passing address of temp to start
    else
    {
        curr = start;              // initialize for traversal
        while (curr->next != NULL) // while loop for traversing
            curr = curr->next;
        curr->next = temp; // assigning temps address to last element
    }
}
void insert_after(int ele, int sele)
{
    struct node *curr, *temp;
    if (start != NULL)
    {                                              // checking if list is empty
        curr = start;                              // initialize curr
        while (curr != NULL && curr->data != sele) // traversal till the end or till the element is found
            curr = curr->next;
        if (curr != NULL)
        {                                                      // element found and list is not exhausted
            temp = (struct node *)malloc(sizeof(struct node)); // reserve memory
            temp->data = ele;                                  // assigning the value
            temp->next = curr->next;                           // address of next shift to temp
            curr->next = temp;                                 // address of temp given to curr
        }
        else
            printf("Element not found");
    }
    printf("l*ist is empty");
}
void insert_before(int ele, int sele)
{
    struct node *curr, *temp; // initialize
    if (start != NULL)
    { // if starting is null exit the program
        if (start->data = sele)
        {                                                      // if sele is found at the start, Insert_Beg function
            temp = (struct node *)malloc(sizeof(struct node)); // size allocation
            temp->data = ele;
            temp->next = start;
            start = temp;
        }
        else
        {
            while (curr->next != NULL && curr->next->data != sele) // 2nd condition to peek onto next element
                curr = curr->next;                                 // search till element is found
            if (curr->next != NULL)
            {                            // element found case
                temp->next = curr->next; // next address given to temp
                curr->next = temp;       // temp address given to next
            }
            else
                printf("Element not found");
        }
    }
    else
        printf("list is empty");
}
int delete_f()
{
    int x = -999;      // arbritary element
    struct node *temp; // initialize
    if (start != NULL)
    {                       // checking if elements are present
        temp = start;       // start address passed to temp
        x = temp->data;     // value return
        start = temp->next; // temp contains address of next element which is passed to start
        free(temp);         // free temp
        temp = NULL;        // pointer NULL
    }
    else
        printf("List is empty");
    return x;
}
int delete_l()
{
    int x = -999;
    struct node *temp, *curr; // initialize
    if (start != NULL)
    {
        if (start->next == NULL)
        { // if its the first element
            temp = start;
            x = start->data;
            start = NULL;
            free(temp);
        }
        else
        {
            curr = start;
            while (curr->next->next != NULL) // traversing till the end
                curr = curr->next;
            temp = curr->next; //
            x = temp->data;    // returning the data
            curr->next = NULL; // setting the last element to null
            free(temp);        // free memory
        }
    }
    else
        printf("List is empty");
    return x;
}
void delete_spec(int sele)
{
    struct node *temp, *curr; // initialize
    if (start != NULL)
    {
        if (start->data == sele)
        { // if the first element is the data sele
            temp = start;
            start = temp->next; // assign next element address to start
            free(temp);         // free the deleted element memory
            temp = NULL;
        }
        else
        {
            curr = start;
            while (curr->next != NULL && curr->next->data != sele) // traverse till the element is found
                curr = curr->next;
            if (curr->next != NULL)
            {                            // element found before the end of the list
                temp = curr->next;       // curr address given to temp
                curr->next = temp->next; // temps address passed to curr
                free(temp);              // memory freed
                temp = NULL;
            }
            else
                printf("Element not found");
        }
    }
    else
        printf("List is empty");
}
void trave_for()
{
    struct node *curr;
    curr = start;
    while (curr != NULL)
    {
        printf("%d", curr->data);
        curr = curr->next;
    }
}
void trave_back()
{
    if (start != NULL)
        funpf(start);
    else
        printf("The list empty");
}
void funpf(struct node *curr)
{
    if (curr != NULL)
    {
        funpf(curr->next);
        printf("%d", curr->data);
    }
}
void reverse()
{
    struct node *rev, *temp;
    rev = NULL;
    while (start != NULL)
    {
        temp = start; // deleting first
        start = temp->next;
        temp->next = rev; // Inserting first
        rev = temp;
    }
    start = rev;
}
int main()
{
    start = NULL;
    int ch;
    do
    {
        printf("Enter your choice\n 1.Insert\n 2.Delete\n 3.Traverse\n 4.Reverse\n 5.exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert();
            break;
        case 2:
            delete ();
            break;
        case 3:
            traverse();
            break;
        case 4:
            reverse();
            break;
        case 5:
            exit(1);
            break;
        default:
            printf("Not a valid option");
        }
    } while (ch != 5);
}
void insert()
{
    int ch, ele, sele;
    while (ch != 6)
    {
        printf("Enter your choice\n 1.Insert beg\n 2.Insert last\n 3.Insert before\n 4.Insert after\n 5.Go back");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter the element to enter:");
            scanf("%d", &ele);
            insert_beg(ele);
            break;
        case 2:
            printf("\nEnter the element to enter:");
            scanf("%d", &ele);
            insert_end(ele);
            break;
        case 3:
            printf("\nEnter the element to enter:");
            scanf("%d", &ele);
            printf("Enter the element before which element needs to be inserted:");
            scanf("%d", &sele);
            insert_before(ele, sele);
            break;
        case 4:
            printf("\nEnter the element to enter:");
            scanf("%d", &ele);
            printf("Enter the element after which element needs to be inserted:");
            scanf("%d", &sele);
            insert_after(ele, sele);
            break;
        case 5:
            trave_for();
            break;
        case 6:
            break;
        default:
            printf("Enter valid option");
        }
    }
}
void delete()
{
    int ch, sele;
    while (ch != 5)
    {
        printf("Enter your choice\n 1.Delete beg\n 2.Delete last\n 3.Delete spec\n 4.Go back");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            delete_f();
            break;
        case 2:
            delete_l();
            break;
        case 3:
            printf("Enter the element to be deleted:");
            scanf("%d", &sele);
            delete_spec(sele);
            break;
        case 4:
            trave_for();
            break;
        case 5:
            break;
        default:
            printf("Enter valid option");
        }
    }
}
void traverse()
{
    int ch;
    while (ch != 3)
    {
        printf("Enter your choice\n 1.Travel forward\n 2.Travel backward\n 3.Go back");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            trave_for();
            break;
        case 2:
            trave_back();
            break;
        case 3:
            break;
        default:
            printf("Enter valid option");
        }
    }
}
