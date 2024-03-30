// Linked List implementation of Queue
#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node *next;
};

struct Queue{
    struct Node *front;
    struct Node *rear;
};

void initialize(struct Queue *que){
    que->front = NULL;
    que->rear = NULL;
}

void enqueue(struct Queue *que, int val){
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    // if heap is full
    if(temp == NULL){
        printf("\nNo more space available\n");
    }
    else{
        if(que->front == NULL){
            // first node
            temp->data = val;
            temp->next = NULL;
            que->front = que->rear = temp;
        }
        else{
            // not first node
            temp->data = val;
            temp->next = NULL;
            (que->rear)->next = temp;
            que->rear = (que->rear)->next; // moving rear forward
        }
    }
}

int dequeue(struct Queue *que){
    int val = -1;
    if(que->front == NULL){
        printf("\nQueue is empty\n");
    }
    else{
        struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
        temp = que->front;
        que->front = que->front->next; // moving front forward
        val = temp->data;
        free(temp);
    }
    return val;
}

void display(struct Queue *que){
    if(que->front == NULL){
        printf("\nQueue is empty\n");
    }
    else{
        struct Node *temp = que->front;
        while(temp != NULL){
            printf("%d ", temp->data);
            temp = temp->next; 
        }
        printf("\n");
    }
}

int main() {
    struct Queue q1;
    initialize(&q1);
    enqueue(&q1, 5);
    enqueue(&q1, 3);
    enqueue(&q1, 8);
    enqueue(&q1, 9);
    
    display(&q1);
    
    dequeue(&q1);
    dequeue(&q1);
    
    display(&q1);
    
     
    return 0;
}
