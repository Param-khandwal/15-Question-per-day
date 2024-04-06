#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

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

int isOperand(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
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

void infixToPrefix(char *infix, char *prefix) {
    struct stack s;
    initStack(&s);
    
    int len = strlen(infix);
    char reversed[len + 1];
    int j = 0;
    for (int i = len - 1; i >= 0; i--) {
        reversed[j] = infix[i];
        j++;
    }
    reversed[j] = '\0';

    char postfix[len + 1];
    int k = 0;
    for (int i = 0; reversed[i] != '\0'; i++) {
        char ch = reversed[i];
        if (isOperand(ch)) {
            postfix[k] = ch;
            k++;
        } else if (ch == ')') {
            push(&s, ch);
        } else if (ch == '(') {
            while (!isEmpty(&s) && peek(&s) != ')') {
                postfix[k] = pop(&s);
                k++;
            }
            if (!isEmpty(&s)) {
                pop(&s); // Discard '('
            }
        } else {
            while (!isEmpty(&s) && precedence(ch) < precedence(peek(&s))) {
                postfix[k] = pop(&s);
                k++;
            }
            push(&s, ch);
        }
    }
    while (!isEmpty(&s)) {
        postfix[k] = pop(&s);
        k++;
    }
    postfix[k] = '\0';

    j = 0;
    len = strlen(postfix);
    for (int i = len - 1; i >= 0; i--) {
        prefix[j] = postfix[i];
        j++;
    }
    prefix[j] = '\0';
}

int main() {
    char infix[MAX_SIZE];
    char prefix[MAX_SIZE];
    printf("Enter an infix expression: ");
    scanf("%[^\n]s", infix);

    infixToPrefix(infix, prefix);

    printf("Prefix expression: %s\n", prefix);

    return 0;
}
