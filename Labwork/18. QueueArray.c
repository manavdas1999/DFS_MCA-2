/*
18. Write a program to implement Linear queue using 
array and perform the following operation on it. 
1. Enqueue. 
2. Dequeue. 
3. Traverse. 
4. Peek 
5. Search 
6. Max element in Queue 
*/

#include <stdio.h>
#include <stdlib.h>

// Structure to represent a linear queue
typedef struct {
    int front, rear, capacity;
    int *array;
} Queue;

// Function to create a linear queue
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
    return queue->rear == queue->capacity - 1;
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
    queue->array[++(queue->rear)] = item;
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
        queue->front++;
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
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->array[i]);
    }
    printf("\n");
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
        return -1; // Element not found
    }
    for (int i = queue->front; i <= queue->rear; i++) {
        if (queue->array[i] == key) {
            return i; // Return index of element if found
        }
    }
    return -1; // Element not found
}

// Function to find the maximum element in the queue
int maxElement(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        exit(1);
    }
    int max = queue->array[queue->front];
    for (int i = queue->front + 1; i <= queue->rear; i++) {
        if (queue->array[i] > max) {
            max = queue->array[i];
        }
    }
    return max;
}

int main() {
    int capacity, choice, item, key;
    printf("Enter the capacity of the queue: ");
    scanf("%d", &capacity);

    Queue* queue = createQueue(capacity);

    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Traverse\n");
        printf("4. Peek\n");
        printf("5. Search\n");
        printf("6. Max element in Queue\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &item);
                enqueue(queue, item);
                break;
            case 2:
                item = dequeue(queue);
                printf("Dequeued element: %d\n", item);
                break;
            case 3:
                traverse(queue);
                break;
            case 4:
                item = peek(queue);
                printf("Front element of the queue: %d\n", item);
                break;
            case 5:
                printf("Enter the element to search: ");
                scanf("%d", &key);
                if (search(queue, key) != -1) {
                    printf("Element %d found in the queue\n", key);
                } else {
                    printf("Element %d not found in the queue\n", key);
                }
                break;
            case 6:
                item = maxElement(queue);
                printf("Maximum element in the queue: %d\n", item);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
