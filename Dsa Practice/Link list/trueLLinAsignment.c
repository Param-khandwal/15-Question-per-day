#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct LinkedList {
    struct Node* head;
    struct Node* tail;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertAtBeginning(struct LinkedList* list, int data) {
    struct Node* newNode = createNode(data);
    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        newNode->next = list->head;
        list->head->prev = newNode;
        list->head = newNode;
    }
}

void insertAtEnd(struct LinkedList* list, int data) {
    struct Node* newNode = createNode(data);
    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        list->tail->next = newNode;
        newNode->prev = list->tail;
        list->tail = newNode;
    }
}

void deleteNode(struct LinkedList* list, int data) {
    struct Node* current = list->head;
    while (current != NULL) {
        if (current->data == data) {
            if (current == list->head) {
                list->head = current->next;
                if (list->head != NULL) {
                    list->head->prev = NULL;
                }
            } else if (current == list->tail) {
                list->tail = current->prev;
                if (list->tail != NULL) {
                    list->tail->next = NULL;
                }
            } else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }
            free(current);
            return;
        }
        current = current->next;
    }
    printf("Element %d not found in the list.\n", data);
}

void traverseForward(struct LinkedList* list) {
    struct Node* current = list->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void traverseReverse(struct LinkedList* list) {
    struct Node* current = list->tail;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->prev;
    }
    printf("\n");
}

int search(struct LinkedList* list, int data) {
    struct Node* current = list->head;
    int index = 0;
    while (current != NULL) {
        if (current->data == data) {
            return index;
        }
        current = current->next;
        index++;
    }
    return -1;
}

void reverseList(struct LinkedList* list) {
    struct Node* current = list->head;
    struct Node* prev = NULL;
    struct Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        current->prev = next;
        prev = current;
        current = next;
    }
    list->tail = list->head;
    list->head = prev;
}

int main() {
    struct LinkedList list;
    list.head = NULL;
    list.tail = NULL;

    int choice, data;
    while (1) {
        printf("\n1. Insert at beginning\n2. Insert at end\n3. Delete node\n4. Traverse forward\n5. Traverse reverse\n6. Search element\n7. Reverse list\n8. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                insertAtBeginning(&list, data);
                break;
            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(&list, data);
                break;
            case 3:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                deleteNode(&list, data);
                break;
            case 4:
                printf("Elements in the list (forward): ");
                traverseForward(&list);
                break;
            case 5:
                printf("Elements in the list (reverse): ");
                traverseReverse(&list);
                break;
            case 6:
                printf("Enter data to search: ");
                scanf("%d", &data);
                int index = search(&list, data);
                if (index != -1) {
                    printf("Element found at index %d.\n", index);
                } else {
                    printf("Element not found in the list.\n");
                }
                break;
            case 7:
                reverseList(&list);
                printf("List reversed.\n");
                break;
            case 8:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
