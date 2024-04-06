#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct stack {
    int items[MAX_SIZE];
    int top;
};

void initStack(struct stack *s) {
    s->top = -1;
}

int isFull(struct stack *s) {
    return s->top == MAX_SIZE - 1;
}

int isEmpty(struct stack *s) {
    return s->top == -1;
}

void push(struct stack *s, int value) {
    if (isFull(s)) {
        printf("Stack is full. Cannot push.\n");
        return;
    }
    s->top++;
    s->items[s->top] = value;
    printf("Pushed %d onto the stack.\n", value);
}

int pop(struct stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty. Cannot pop.\n");
        return -1;
    }
    int popped = s->items[s->top];
    s->top--;
    printf("Popped %d from the stack.\n", popped);
    return popped;
}

void display(struct stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack contents: ");
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->items[i]);
    }
    printf("\n");
}

int main() {
    struct stack s;
    initStack(&s);
    int choice, value;
    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&s, value);
                break;
            case 2:
                pop(&s);
                break;
            case 3:
                display(&s);
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
