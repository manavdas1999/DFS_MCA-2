/*
15. Write a program to implement stack using linked 
list and perform following operations on it. 
1. Push. 
2. Pop. 
3. Peek. 
4. Traverse. 
5. Search. 
*/
#include <stdio.h>
#include <stdlib.h>

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
        return NULL;
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
    
    // // linked list implementation of stack
    struct Node *top = NULL;
    top = push(top, 10);
    top = push(top, 20);
    top = push(top, 30);
    top = push(top, 40);
    
    printf("Current Stack after pushing 5 items: ");
    display(top);
    
    
    printf("top item: %d\n", peek(top));
    
    int value;
    top = pop(top, &value);
    printf("popped value %d\n", value);
    top = pop(top, &value);
    printf("popped value %d\n", value);
    
    printf("Current Stack after popping twice: ");
    display(top);
    
    printf("current count: %d\n", count(top));
    
    return 0;
}
