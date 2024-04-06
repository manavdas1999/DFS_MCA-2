/*
19. Write a program to implement Linear queue using linked list 
and perform the following operation on it. 

1. Enqueue
2. Dequeue
3. Traverse 
4. Peek 
5. Search 
6. Max element in Queue 
*/

#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the queue
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Structure to represent a linear queue
typedef struct {
    Node* front;
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

// Function to initialize the queue
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (queue == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Function to add an element to the queue (enqueue)
void enqueue(Queue* queue, int data) {
    Node* newNode = createNode(data);
    if (queue->rear == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Function to remove an element from the queue (dequeue)
int dequeue(Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue underflow\n");
        exit(1);
    }
    int data = queue->front->data;
    Node* temp = queue->front;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    return data;
}

// Function to traverse and display the queue
void traverse(Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    Node* current = queue->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to peek at the front element of the queue
int peek(Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty\n");
        exit(1);
    }
    return queue->front->data;
}

// Function to search for an element in the queue
int search(Queue* queue, int key) {
    if (queue->front == NULL) {
        return 0; // Element not found
    }
    Node* current = queue->front;
    while (current != NULL) {
        if (current->data == key) {
            return 1; // Element found
        }
        current = current->next;
    }
    return 0; // Element not found
}

// Function to find the maximum element in the queue
int maxElement(Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty\n");
        exit(1);
    }
    int max = queue->front->data;
    Node* current = queue->front->next;
    while (current != NULL) {
        if (current->data > max) {
            max = current->data;
        }
        current = current->next;
    }
    return max;
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

    // Search for an element
    int key = 3;
    if (search(queue, key)) {
        printf("Element %d found in the queue\n", key);
    } else {
        printf("Element %d not found in the queue\n", key);
    }

    // Find the maximum element in the queue
    printf("Maximum element in the queue: %d\n", maxElement(queue));

    return 0;
}
