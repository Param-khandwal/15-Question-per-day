#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

struct stack {
    char *items;
    int top;
};

void initStack(struct stack *s) {
    s->top = -1;
    s->items = (char *)malloc(MAX_SIZE * sizeof(char));
    if (s->items == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
}

int isEmpty(struct stack *s) {
    return s->top == -1;
}

void push(struct stack *s, char value) {
    s->top++;
    s->items[s->top] = value;
}

char pop(struct stack *s) {
    char popped = s->items[s->top];
    s->top--;
    return popped;
}

bool isBalanced(char *expr) {
    struct stack s;
    initStack(&s);
    
    for (int i = 0; expr[i] != '\0'; i++) {
        switch (expr[i]) {
            case '(':
            case '{':
            case '[':
                push(&s, expr[i]);
                break;
            case ')':
                if (isEmpty(&s) || pop(&s) != '(')
                    return false;
                break;
            case '}':
                if (isEmpty(&s) || pop(&s) != '{')
                    return false;
                break;
            case ']':
                if (isEmpty(&s) || pop(&s) != '[')
                    return false;
                break;
        }
    }

    return isEmpty(&s);
}

int main() {
    char expr[MAX_SIZE];
    printf("Enter an expression: ");
    scanf("%[^\n]s", expr);

    if (isBalanced(expr)) {
        printf("The expression is balanced.\n");
    } else {
        printf("The expression is not balanced.\n");
    }

    return 0;
}
