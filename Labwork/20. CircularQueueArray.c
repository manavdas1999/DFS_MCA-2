/*
20. Write a program to implement Circular queue 
using array and perform the following operation 
on it. 
1. Enqueue. 
2. Dequeue. 
3. Traverse. 
4. Peek 
7. Search 
5. Max element in Queue 
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure to represent a circular queue
typedef struct {
    int front, rear, capacity;
    int *array;
} Queue;

// Function to create a circular queue
Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (queue == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    queue->front = -1;
    queue->rear = -1;
    queue->capacity = capacity;
    queue->array = (int*)malloc(capacity * sizeof(int));
    if (queue->array == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    return queue;
}

// Function to check if the queue is full
int isFull(Queue* queue) {
    return (queue->rear + 1) % queue->capacity == queue->front;
}

// Function to check if the queue is empty
int isEmpty(Queue* queue) {
    return queue->front == -1;
}

// Function to add an element to the queue (enqueue)
void enqueue(Queue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue overflow\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
}

// Function to remove an element from the queue (dequeue)
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue underflow\n");
        exit(1);
    }
    int item = queue->array[queue->front];
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % queue->capacity;
    }
    return item;
}

// Function to traverse and display the queue
void traverse(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    int i = queue->front;
    while (i != queue->rear) {
        printf("%d ", queue->array[i]);
        i = (i + 1) % queue->capacity;
    }
    printf("%d\n", queue->array[i]);
}

// Function to peek at the front element of the queue
int peek(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        exit(1);
    }
    return queue->array[queue->front];
}

// Function to search for an element in the queue
int search(Queue* queue, int key) {
    if (isEmpty(queue)) {
        return 0; // Element not found
    }
    int i = queue->front;
    while (i != queue->rear) {
        if (queue->array[i] == key) {
            return 1; // Element found
        }
        i = (i + 1) % queue->capacity;
    }
    if (queue->array[i] == key) {
        return 1; // Element found
    }
    return 0; // Element not found
}

// Function to find the maximum element in the queue
int maxElement(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        exit(1);
    }
    int max = queue->array[queue->front];
    int i = (queue->front + 1) % queue->capacity;
    while (i != (queue->rear + 1) % queue->capacity) {
        if (queue->array[i] > max) {
            max = queue->array[i];
        }
        i = (i + 1) % queue->capacity;
    }
    return max;
}

int main() {
    int capacity, item, key;
    printf("Enter the capacity of the queue: ");
    scanf("%d", &capacity);

    Queue* queue = createQueue(capacity);

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
    item = dequeue(queue);
    printf("Dequeued element: %d\n", item);

    // Peek at the front element
    printf("Front element of the queue: %d\n", peek(queue));

    // Search for an element
    key = 3;
    if (search(queue, key)) {
        printf("Element %d found in the queue\n", key);
    } else {
        printf("Element %d not found in the queue\n", key);
    }

    // Find the maximum element in the queue
    printf("Maximum element in the queue: %d\n", maxElement(queue));

    return 0;
}
