#include <stdio.h>
#include <stdlib.h>

// Stack data structure:
// 1. Follows LIFO(last in first out) principle
// 2. can be implemented using array and linked list
// 3. insertion and deletion takes place from only one point

// implementation using array
// struct Stack{
//     int top;  
//     int *data;
//     int size;
// };

// struct Stack createStack(int size){
//     struct Stack stack;
//     stack.top = -1;
//     stack.size = size;
//     stack.data = (int*)malloc(size * sizeof(int));
//     return stack;
// }

// void push(struct Stack* st, int value){
//     if(st->top == st->size-1) printf("\nStack overflow!\n");
//     else{
//         st->data[++st->top] = value;
//     }
// }

// int pop(struct Stack* st){
//     if(st->top == -1){
//         printf("\nStack is empty!\n");
//         return -1;
//     }
//     return st->data[st->top--];
// }

// int peek(struct Stack *st){
//     if(st->top == -1){
//         printf("\nStack is empty!\n");
//         return -1;
//     }
//     return st->data[st->top];
// }

// int count(struct Stack *st){
//     return st->top+1;
// }

// int max(struct Stack *st){
//     if(st->top == -1){
//         printf("\nStack is empty!\n");
//         return -1;
//     }
//     int max = st->data[0];
//     for(int i = 1; i <= st->top; i++){
//         if(max < st->data[i]) max = st->data[i];
//     }
//     return max;
// }

// int min(struct Stack *st){
//     if(st->top == -1){
//         printf("\nStack is empty!\n");
//         return -1;
//     }
//     int min = st->data[0];
//     for(int i = 1; i <= st->top; i++){
//         if(min > st->data[i]) min = st->data[i];
//     }
//     return min;
// }

// void display(struct Stack* st){
//     if(st->top == -1) printf("\nStack is empty\n");
//     else{
//         for(int i=st->top; i>=0; i--){
//             printf("%d ", st->data[i]);
//         }
//         printf("\n");
//     }
// }




// // //
// implementation using Linked list
struct Node {
    int data;
    struct Node *next;
};

struct Node* push(struct Node *top, int value){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    
    top = newNode;
    return top;
}

struct Node* pop(struct Node *top, int *holder){
    if(top == NULL){
        printf("\nStack is empty!\n");
        return -1;
    }
    struct Node *temp = top;
    top = top->next;
    
    *holder = temp->data; // transfering popped item 
    free(temp);
    return top;
}

int peek(struct Node* top){
    if(top == NULL){
        printf("\nStack is empty!\n");
        return -1;
    }
    return top->data;
}

int count(struct Node* top){
    struct Node *temp = top;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

void display(struct Node *top){
    struct Node *temp = top;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    
    // // array implementation of stack
    // struct Stack myStack = createStack(5);
    // push(&myStack, 10);
    // push(&myStack, 20);
    // push(&myStack, 30);
    // push(&myStack, 40);
    
    // printf("top Item: %d \n",peek(&myStack));
    // printf("current max item: %d \n",max(&myStack));
    // printf("current min item: %d \n",min(&myStack));
    
    // display(&myStack);
    
    // printf("popped Item: %d \n",pop(&myStack));
    // printf("popped Item: %d \n",pop(&myStack));
    
    // display(&myStack);
    
    // printf("current item count: %d \n",count(&myStack));
    
    // // linked list implementation of stack
    struct Node *top = NULL;
    top = push(top, 10);
    top = push(top, 20);
    top = push(top, 30);
    top = push(top, 40);
    
    printf("top item: %d\n", peek(top));
    display(top);
    
    int value;
    top = pop(top, &value);
    printf("popped value %d\n", value);
    top = pop(top, &value);
    printf("popped value %d\n", value);
    
    printf("current count: %d\n", count(top));
    
    display(top);
    
    return 0;
}
