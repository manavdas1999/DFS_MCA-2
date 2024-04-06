/*
12. Write a program to following operations on Doubly Circular linked list

1.	Addition of a new node when list is empty.
2.	Addition of a node at the end of the list.
3.	Addition of a node at the beginning of linked list.
4.	Addition of a node at the specific position.
5.	Traversing a linked list.
6.	Counting number of nodes in linked list.
7.	Deleting a node from the linked list at beginning, at end, at specific position. 
8.	Reverse A linked List.
9.	Sorting
10.	Search
*/

#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node of the doubly circular linked list
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to add a new node when the list is empty
Node* addToEmpty(Node* last, int data) {
    if (last != NULL) {
        printf("List is not empty\n");
        return last;
    }
    Node* newNode = createNode(data);
    last = newNode;
    last->prev = last;
    last->next = last;
    return last;
}

// Function to add a node at the end of the doubly circular linked list
Node* addToEnd(Node* last, int data) {
    if (last == NULL) {
        return addToEmpty(last, data);
    }
    Node* newNode = createNode(data);
    newNode->prev = last;
    newNode->next = last->next;
    last->next->prev = newNode;
    last->next = newNode;
    last = newNode;
    return last;
}

// Function to add a node at the beginning of the doubly circular linked list
Node* addToBeginning(Node* last, int data) {
    if (last == NULL) {
        return addToEmpty(last, data);
    }
    Node* newNode = createNode(data);
    newNode->prev = last;
    newNode->next = last->next;
    last->next->prev = newNode;
    last->next = newNode;
    return last;
}

// Function to add a node at a specific position
Node* addAtPosition(Node* last, int data, int position) {
    if (last == NULL) {
        printf("List is empty\n");
        return last;
    }
    if (position == 1) {
        return addToBeginning(last, data);
    }
    Node* newNode = createNode(data);
    Node* current = last->next;
    for (int i = 1; i < position - 1 && current != last; i++) {
        current = current->next;
    }
    if (current == last) {
        printf("Position out of range\n");
        return last;
    }
    newNode->prev = current;
    newNode->next = current->next;
    current->next->prev = newNode;
    current->next = newNode;
    return last;
}

// Function to traverse the doubly circular linked list
void traverse(Node* last) {
    if (last == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* current = last->next;
    printf("Doubly Circular Linked List: ");
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != last->next);
    printf("\n");
}

// Function to count number of nodes in linked list
int countNodes(Node* last) {
    if (last == NULL) {
        return 0;
    }
    int count = 0;
    Node* current = last->next;
    do {
        count++;
        current = current->next;
    } while (current != last->next);
    return count;
}

// Function to delete a node from the beginning of the doubly circular linked list
Node* deleteFromBeginning(Node* last) {
    if (last == NULL) {
        printf("List is empty\n");
        return last;
    }
    if (last->next == last) {
        free(last);
        last = NULL;
        return last;
    }
    Node* temp = last->next;
    last->next = temp->next;
    temp->next->prev = last;
    free(temp);
    return last;
}

// Function to delete a node from the end of the doubly circular linked list
Node* deleteFromEnd(Node* last) {
    if (last == NULL) {
        printf("List is empty\n");
        return last;
    }
    if (last->next == last) {
        free(last);
        last = NULL;
        return last;
    }
    Node* temp = last;
    last = last->prev;
    last->next = temp->next;
    temp->next->prev = last;
    free(temp);
    return last;
}

// Function to delete a node from a specific position in the doubly circular linked list
Node* deleteFromPosition(Node* last, int position) {
    if (last == NULL) {
        printf("List is empty\n");
        return last;
    }
    if (position == 1) {
        return deleteFromBeginning(last);
    }
    Node* current = last->next;
    for (int i = 1; i < position && current != last; i++) {
        current = current->next;
    }
    if (current == last) {
        printf("Position out of range\n");
        return last;
    }
    current->prev->next = current->next;
    current->next->prev = current->prev;
    free(current);
    return last;
}

// Function to reverse the doubly circular linked list
Node* reverseList(Node* last) {
    if (last == NULL) {
        printf("List is empty\n");
        return last;
    }
    Node* current = last->next;
    Node* temp;
    do {
        temp = current->next;
        current->next = current->prev;
        current->prev = temp;
        current = temp;
    } while (current != last->next);
    last = last->prev;
    return last;
}

// Function to sort the doubly circular linked list
Node* sortList(Node* last) {
    if (last == NULL) {
        printf("List is empty\n");
        return last;
    }
    Node* current = last->next;
    Node* index = NULL;
    int temp;
    do {
        index = current->next;
        while (index != last->next) {
            if (current->data > index->data) {
                temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
            index = index->next;
        }
        current = current->next;
    } while (current != last->next);
    return last;
}

// Function to search for a node with given data in the doubly circular linked list
void search(Node* last, int key) {
    if (last == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* current = last->next;
    int position = 0;
    do {
        position++;
        if (current->data == key) {
            printf("%d found at position %d\n", key, position);
            return;
        }
        current = current->next;
    } while (current != last->next);
    printf("%d not found in the list\n", key);
}

// Function to free memory allocated for the doubly circular linked list
void freeList(Node* last) {
    if (last == NULL) {
        return;
    }
    Node* current = last->next;
    Node* temp;
    while (current != last) {
        temp = current;
        current = current->next;
        free(temp);
    }
    free(last);
}

int main() {
    Node* last = NULL;

    // Addition of a new node when list is empty
    last = addToEmpty(last, 10);
    traverse(last);

    // Addition of a node at the end of the list
    last = addToEnd(last, 20);
    printf("\nAfter adding a node at end - ");
    traverse(last);

    // Addition of a node at the beginning of linked list
    last = addToBeginning(last, 5);
    printf("\nAfter adding a node at head - ");
    traverse(last);

    // Addition of a node at the specific position
    last = addAtPosition(last, 15, 2);
    printf("\nAfter adding a node at position 2 - ");
    traverse(last);

    // Traversing a linked list
    printf("\nNumber of nodes in linked list: %d\n", countNodes(last));

    // Deleting a node from the linked list at beginning
    last = deleteFromBeginning(last);
    printf("\nAfter deleting a node at head - ");
    traverse(last);

    // Deleting a node from the linked list at end
    last = deleteFromEnd(last);
    printf("\nAfter deleting a node at end - ");
    traverse(last);

    // Deleting a node from the linked list at specific position
    last = deleteFromPosition(last, 2);
    printf("\nAfter deleting a node at position 2 - ");
    traverse(last);

    // Reverse A linked List
    last = reverseList(last);
    printf("\nAfter reversing the list - ");
    traverse(last);

    // Sorting a linked list
    last = sortList(last);
    printf("\nAfter sorting the list - ");
    traverse(last);

    // Search
    printf("\n");
    search(last, 10);
    printf("\n");
    search(last, 30);

    // Free memory allocated for the linked list
    freeList(last);

    return 0;
}
