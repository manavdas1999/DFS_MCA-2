/*
27. Write a C program to check if a given expression has balanced parenthesis or not.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Structure for stack
typedef struct {
    int top;
    char items[MAX_SIZE];
} Stack;

// Function to initialize stack
void initialize(Stack *s) {
    s->top = -1;
}

// Function to check if stack is empty
bool isEmpty(Stack *s) {
    return s->top == -1;
}

// Function to push onto stack
void push(Stack *s, char c) {
    if (s->top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    s->items[++(s->top)] = c;
}

// Function to pop from stack
char pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return s->items[(s->top)--];
}

// Function to check if an expression has balanced parentheses
bool hasBalancedParentheses(char *exp) {
    Stack s;
    initialize(&s);

    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(') {
            push(&s, '(');
        } else if (exp[i] == ')') {
            if (isEmpty(&s)) {
                return false; // Unbalanced, ')' without '('
            }
            pop(&s);
        }
    }

    // If stack is empty, all parentheses are balanced
    return isEmpty(&s);
}

int main() {
    char exp[MAX_SIZE];

    printf("Enter an expression: ");
    fgets(exp, MAX_SIZE, stdin);

    if (hasBalancedParentheses(exp)) {
        printf("The expression has balanced parentheses.\n");
    } else {
        printf("The expression does not have balanced parentheses.\n");
    }

    return 0;
}
