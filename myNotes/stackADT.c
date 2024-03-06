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

int pop(struct Stack* st){
    if(st->top == -1){
        printf("\nStack is empty!\n");
        return -1;
    }
    return st->data[st->top--];
}

int peek(struct Stack *st){
    if(st->top == -1){
        printf("\nStack is empty!\n");
        return -1;
    }
    return st->data[st->top];
}

int count(struct Stack *st){
    return st->top+1;
}

int max(struct Stack *st){
    if(st->top == -1){
        printf("\nStack is empty!\n");
        return -1;
    }
    int max = st->data[0];
    for(int i = 1; i <= st->top; i++){
        if(max < st->data[i]) max = st->data[i];
    }
    return max;
}

int min(struct Stack *st){
    if(st->top == -1){
        printf("\nStack is empty!\n");
        return -1;
    }
    int min = st->data[0];
    for(int i = 1; i <= st->top; i++){
        if(min > st->data[i]) min = st->data[i];
    }
    return min;
}

void display(struct Stack* st){
    if(st->top == -1) printf("\nStack is empty\n");
    else{
        for(int i=st->top; i>=0; i--){
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
    
    printf("top Item: %d \n",peek(&myStack));
    printf("current max item: %d \n",max(&myStack));
    printf("current min item: %d \n",min(&myStack));
    
    display(&myStack);
    
    printf("popped Item: %d \n",pop(&myStack));
    printf("popped Item: %d \n",pop(&myStack));
    
    display(&myStack);
    
    printf("current item count: %d \n",count(&myStack));
    
    return 0;
}
