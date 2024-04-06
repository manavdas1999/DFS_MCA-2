/*
22. Write a program to implement concept of MultiStack and Multi-Queue 
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure for Multi-Stack
typedef struct {
    int *array;
    int top1;
    int top2;
} MultiStack;

// Structure for Multi-Queue
typedef struct {
    int *array;
    int front;
    int rear;
} MultiQueue;

// Function prototypes
MultiStack* createMultiStack();
void pushStack1(MultiStack *ms, int data);
void pushStack2(MultiStack *ms, int data);
int popStack1(MultiStack *ms);
int popStack2(MultiStack *ms);
MultiQueue* createMultiQueue();
void enqueue(MultiQueue *mq, int data);
int dequeue(MultiQueue *mq);

// Function to create a Multi-Stack
MultiStack* createMultiStack() {
    MultiStack *ms = (MultiStack*)malloc(sizeof(MultiStack));
    if (ms == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    ms->array = (int*)malloc(MAX_SIZE * sizeof(int));
    if (ms->array == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    ms->top1 = -1;
    ms->top2 = MAX_SIZE;
    return ms;
}

// Function to push data onto Stack 1
void pushStack1(MultiStack *ms, int data) {
    if (ms->top1 + 1 == ms->top2) {
        printf("Stack overflow.\n");
        return;
    }
    ms->array[++ms->top1] = data;
}

// Function to push data onto Stack 2
void pushStack2(MultiStack *ms, int data) {
    if (ms->top2 - 1 == ms->top1) {
        printf("Stack overflow.\n");
        return;
    }
    ms->array[--ms->top2] = data;
}

// Function to pop data from Stack 1
int popStack1(MultiStack *ms) {
    if (ms->top1 == -1) {
        printf("Stack underflow.\n");
        return -1;
    }
    return ms->array[ms->top1--];
}

// Function to pop data from Stack 2
int popStack2(MultiStack *ms) {
    if (ms->top2 == MAX_SIZE) {
        printf("Stack underflow.\n");
        return -1;
    }
    return ms->array[ms->top2++];
}

// Function to create a Multi-Queue
MultiQueue* createMultiQueue() {
    MultiQueue *mq = (MultiQueue*)malloc(sizeof(MultiQueue));
    if (mq == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    mq->array = (int*)malloc(MAX_SIZE * sizeof(int));
    if (mq->array == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    mq->front = -1;
    mq->rear = -1;
    return mq;
}

// Function to enqueue data into Multi-Queue
void enqueue(MultiQueue *mq, int data) {
    if (mq->rear == MAX_SIZE - 1) {
        printf("Queue overflow.\n");
        return;
    }
    mq->array[++mq->rear] = data;
    if (mq->front == -1) {
        mq->front = 0;
    }
}

// Function to dequeue data from Multi-Queue
int dequeue(MultiQueue *mq) {
    if (mq->front == -1) {
        printf("Queue underflow.\n");
        return -1;
    }
    int data = mq->array[mq->front++];
    if (mq->front > mq->rear) {
        mq->front = mq->rear = -1;
    }
    return data;
}

// Main function
int main() {
    // Example usage of Multi-Stack
    MultiStack *ms = createMultiStack();
    pushStack1(ms, 1);
    pushStack2(ms, 2);
    pushStack1(ms, 3);
    printf("Popped from Stack 1: %d\n", popStack1(ms));
    printf("Popped from Stack 2: %d\n", popStack2(ms));

    // Example usage of Multi-Queue
    MultiQueue *mq = createMultiQueue();
    enqueue(mq, 1);
    enqueue(mq, 2);
    enqueue(mq, 3);
    printf("Dequeued: %d\n", dequeue(mq));
    printf("Dequeued: %d\n", dequeue(mq));
    
    // Free allocated memory
    free(ms->array);
    free(ms);
    free(mq->array);
    free(mq);
    
    return 0;
}
