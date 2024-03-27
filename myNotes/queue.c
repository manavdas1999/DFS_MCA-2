// Queue implementation using array
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
    que->q = (int *)malloc(sizeof(int) * que->size);
}

void enqueue(struct Queue *que, int val){
    if(que->rear == que->size-1){
        printf("\nQueue is full\n");
    }
    else{
        que->rear++;
        que->q[que->rear] = val;
    }
}

// assuming front is before the first element
int dequeue(struct Queue *que){
    if(que->front == que->rear){
        printf("\nQueue is empty\n");
        return -1;
    }
    else{
        que->front++;
        return que->q[que->front];
    }
}

void display(struct Queue *que){
    for(int i=que->front+1; i<=que->rear; i++){
        printf("%d ", que->q[i]);
    }
    printf("\n");
}

int isEmpty(struct Queue *que){
    return que->front == que->rear ? 1 : 0;
}

int front(struct Queue *que){
    if(que->front == que->rear) return -1;
    return que->q[que->front+1];
}

int rear(struct Queue *que){
    if(que->front == que->rear) return -1;
    return que->q[que->rear];
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
