/*
17. Write a program to evaluate a Postfix expression using Stack. 
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 100

// Structure to represent a stack
typedef struct {
    int top;
    int items[MAX_SIZE];
} Stack;

// Function to initialize the stack
void initialize(Stack *stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(Stack *stack, int item) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    stack->items[++(stack->top)] = item;
}

// Function to pop an element from the stack
int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack->items[(stack->top)--];
}

// Function to evaluate a postfix expression
int evaluatePostfix(char* postfix) {
    Stack stack;
    initialize(&stack);

    for (int i = 0; postfix[i] != '\0'; i++) {
        if (isdigit(postfix[i])) {
            push(&stack, postfix[i] - '0');
        } else {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);
            switch (postfix[i]) {
                case '+':
                    push(&stack, operand1 + operand2);
                    break;
                case '-':
                    push(&stack, operand1 - operand2);
                    break;
                case '*':
                    push(&stack, operand1 * operand2);
                    break;
                case '/':
                    push(&stack, operand1 / operand2);
                    break;
            }
        }
    }
    return pop(&stack);
}

int main() {
    char postfix[MAX_SIZE];
    printf("Enter a postfix expression: ");
    fgets(postfix, sizeof(postfix), stdin);
    postfix[strcspn(postfix, "\n")] = '\0'; // Remove the newline character

    int result = evaluatePostfix(postfix);
    printf("Result: %d\n", result);

    return 0;
}
