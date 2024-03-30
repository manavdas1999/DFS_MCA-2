
// Circular queue 
#include <stdio.h>
#include <stdlib.h>

struct Queue{
    int size;
    int front;
    int rear;
    int *q;
};

void initialize(struct Queue *que, int size){
    que->size = size;
    que->front = -1;
    que->rear = -1;
    que->q = (int*)malloc(sizeof(int)*que->size);
}

void enqueue(struct Queue *que, int val){
    if((que->rear+1)%que->size == que->front){
        printf("\nQueue is full\n");
    }
    else{
        que->rear = (que->rear+1) % que->size; // forward motion
        que->q[que->rear] = val;
    }
}

int dequeue(struct Queue *que){
    if(que->front == que->rear){
        printf("\nQueue is empty\n");
        return -1;
    }
    else{
        que->front = (que->front + 1) % que->size;
        return que->q[que->front];
    }
}

void display(struct Queue *que){
    if(que->front == que->rear){
        printf("\nQueue is empty\n");
    } 
    else{
        int i = (que->front) % que->size;
        do{
            i = (i+1) % que->size; // forward
            printf("%d ", que->q[i]);
        }while(i != que->rear);
        printf("\n");
    }
}


int main() {
    struct Queue q1;
    initialize(&q1, 5);
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
