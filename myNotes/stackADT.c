#include <stdio.h>
#include <stdlib.h>

// Stack data structure:
// 1. Follows LIFO(last in first out) principle
// 2. can be implemented using array and linked list
// 3. insertion and deletion takes place from only one point

// implementation using array
struct Stack{
    int top;  
    int *data;
    int size;
};

struct Stack createStack(int size){
    struct Stack stack;
    stack.top = -1;
    stack.size = size;
    stack.data = (int*)malloc(size * sizeof(int));
    return stack;
}

void push(struct Stack* st, int value){
    if(st->top == st->size-1) printf("\nStack overflow!\n");
    else{
        st->data[++st->top] = value;
    }
}


void display(struct Stack* st){
    if(st->top == -1) printf("\nStack is empty\n");
    else{
        for(int i=0; i<=st->top; i++){
            printf("%d ", st->data[i]);
        }
        printf("\n");
    }
}


int main() {
    
    struct Stack myStack = createStack(5);
    push(&myStack, 10);
    push(&myStack, 20);
    push(&myStack, 30);
    push(&myStack, 40);
    
    display(&myStack);
    
    
    return 0;
}
