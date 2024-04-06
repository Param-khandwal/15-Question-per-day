#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* mergeSortedLists(struct Node* L1, struct Node* L2) {
    if (L1 == NULL) {
        return L2;
    }
    if (L2 == NULL) {
        return L1;
    }
    struct Node* mergedList = NULL;
    if (L1->data <= L2->data) {
        mergedList = L1;
        L1 = L1->next;
    } else {
        mergedList = L2;
        L2 = L2->next;
    }
    struct Node* current = mergedList;
    while (L1 != NULL && L2 != NULL) {
        if (L1->data <= L2->data) {
            current->next = L1;
            L1 = L1->next;
        } else {
            current->next = L2;
            L2 = L2->next;
        }
        current = current->next;
    }
    if (L1 != NULL) {
        current->next = L1;
    }
    if (L2 != NULL) {
        current->next = L2;
    }
    return mergedList;
}

void display(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node* L1 = createNode(1);
    L1->next = createNode(3);
    L1->next->next = createNode(5);

    struct Node* L2 = createNode(2);
    L2->next = createNode(4);
    L2->next->next = createNode(6);

    printf("List 1: ");
    display(L1);
    printf("List 2: ");
    display(L2);

    struct Node* mergedList = mergeSortedLists(L1, L2);

    printf("Merged List: ");
    display(mergedList);

    return 0;
}
