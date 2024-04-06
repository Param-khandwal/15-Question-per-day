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

char peek(struct stack *s) {
    return s->items[s->top];
}

int precedence(char op) {
    switch(op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

void infixToPostfix(char *infix, char *postfix) {
    struct stack s;
    initStack(&s);
    
    int i = 0, j = 0;
    while (infix[i] != '\0') {
        char ch = infix[i];
        switch (ch) {
            case '(': 
                push(&s, ch);
                break;
            case ')': 
                while (!isEmpty(&s) && peek(&s) != '(') {
                    postfix[j++] = pop(&s);
                }
                pop(&s); // Pop '('
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(ch)) {
                    postfix[j++] = pop(&s);
                }
                push(&s, ch);
                break;
            default:
                postfix[j++] = ch; // Operand
        }
        i++;
    }
    
    // Pop remaining operators from the stack
    while (!isEmpty(&s)) {
        postfix[j++] = pop(&s);
    }
    postfix[j] = '\0'; // Null-terminate the postfix string
}

int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE];
    printf("Enter an infix expression: ");
    scanf("%[^\n]s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    return 0;
}
