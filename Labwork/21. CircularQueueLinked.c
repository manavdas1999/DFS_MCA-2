/*
21. Write a program to implement Circular queue 
using Linked List and perform the following 
operation on it. 
1. Enqueue. 
2. Dequeue. 
3. Traverse. 
4. Peek 
*/

#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the circular queue
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Structure to represent a circular queue
typedef struct {
    Node* rear;
} Queue;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize the circular queue
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (queue == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    queue->rear = NULL;
    return queue;
}

// Function to check if the circular queue is empty
int isEmpty(Queue* queue) {
    return queue->rear == NULL;
}

// Function to add an element to the circular queue (enqueue)
void enqueue(Queue* queue, int data) {
    Node* newNode = createNode(data);
    if (isEmpty(queue)) {
        newNode->next = newNode; // Point to itself
    } else {
        newNode->next = queue->rear->next;
        queue->rear->next = newNode;
    }
    queue->rear = newNode;
}

// Function to remove an element from the circular queue (dequeue)
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue underflow\n");
        exit(1);
    }
    int data;
    Node* temp = queue->rear->next;
    data = temp->data;
    if (queue->rear == temp) { // Only one node
        queue->rear = NULL;
    } else {
        queue->rear->next = temp->next;
    }
    free(temp);
    return data;
}

// Function to traverse and display the circular queue
void traverse(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    Node* temp = queue->rear->next;
    printf("Queue elements: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != queue->rear->next);
    printf("\n");
}

// Function to peek at the front element of the circular queue
int peek(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        exit(1);
    }
    return queue->rear->next->data;
}

int main() {
    Queue* queue = createQueue();

    // Enqueue elements
    printf("Enqueueing elements: ");
    for (int i = 1; i <= 5; i++) {
        enqueue(queue, i);
        printf("%d ", i);
    }
    printf("\n");

    // Traverse and display the queue
    traverse(queue);

    // Dequeue an element
    int item = dequeue(queue);
    printf("Dequeued element: %d\n", item);

    // Peek at the front element
    printf("Front element of the queue: %d\n", peek(queue));

    return 0;
}
