/*
10. Write a program to following operations on Doubly linked list

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

// Define a structure for a node of the doubly linked list
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to add a new node when the list is empty from an array
Node* createFromArray(int arr[], int size){
    Node *head, *temp;
    // first node
    head = createNode(arr[0]);
    temp = head;
    for(int i=1; i<size; i++){
        temp->next = createNode(arr[i]);
        temp->next->prev = temp;
        temp=temp->next;
    }
    return head;
}

// Function to add a node at the end of the list
Node* addAtEnd(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        return head;
    }
    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
    return head;
}

// Function to add a node at the beginning of the list
Node* addAtHead(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        return head;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
    return head;
}

// Function to add a node at a specific position
Node* addAtPosition(Node* head, int data, int position) {
    if (position == 1) {
        return addAtHead(head, data);
    }
    Node* newNode = createNode(data);
    Node* current = head;
    for (int i = 1; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Position out of range\n");
        return head;
    }
    newNode->next = current->next;
    if (current->next != NULL) {
        current->next->prev = newNode;
    }
    current->next = newNode;
    newNode->prev = current;
    return head;
}

// Function to traverse the linked list
void traverse(Node* head) {
    printf("Linked List: ");
    Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to count number of nodes in linked list
int countNodes(Node* head) {
    int count = 0;
    Node *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Function to delete a node from the beginning of the linked list
Node* deleteFromHead(Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }
    Node* temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    free(temp);
    return head;
}

// Function to delete a node from the end of the linked list
Node* deleteFromEnd(Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }
    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    if (current->prev != NULL) {
        current->prev->next = NULL;
    }
    free(current);
    return head;
}

// Function to delete a node from a specific position in the linked list
Node* deleteFromPosition(Node* head, int position) {
    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }
    if (position == 1) {
        return deleteFromHead(head);
    }
    Node* current = head;
    for (int i = 1; i < position && current != NULL; i++) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Position out of range\n");
        return head;
    }
    current->prev->next = current->next;
    if (current->next != NULL) {
        current->next->prev = current->prev;
    }
    free(current);
    return head;
}

// Function to reverse a linked list
Node* reverseList(Node* head) {
    Node *temp = NULL;
    Node *current = head;
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != NULL) {
        head = temp->prev;
    }
    return head;
}

// Function to sort a linked list
Node* sortList(Node* head) {
    Node* current = head;
    Node* index = NULL;
    int temp;
    if (head == NULL) {
        return head;
    } else {
        while (current != NULL) {
            index = current->next;
            while (index != NULL) {
                if (current->data > index->data) {
                    temp = current->data;
                    current->data = index->data;
                    index->data = temp;
                }
                index = index->next;
            }
            current = current->next;
        }
        return head;
    }
}

// Function to search for a node with given data in the linked list
void search(Node* head, int key) {
    int position = 0;
    Node *temp = head;
    while (temp != NULL) {
        position++;
        if (temp->data == key) {
            printf("%d found at position %d\n", key, position);
            return;
        }
        temp = temp->next;
    }
    printf("%d not found in the list\n", key);
}

// Function to free memory allocated for the linked list
void freeList(Node* head) {
    Node* current = head;
    Node* temp;
    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    Node* head = NULL;

    // Addition of a new node when list is empty
    int arr[] = {10,20,15,30};
    head = createFromArray(arr, 4);
    traverse(head);

    // Addition of a node at the end of the list
    head = addAtEnd(head, 20);
    printf("\nAfter adding new node at end - ");
    traverse(head);

    // Addition of a node at the beginning of linked list
    head = addAtHead(head, 5);
    printf("\nAfter adding new node at Head - ");
    traverse(head);

    // Addition of a node at the specific position
    head = addAtPosition(head, 15, 2);
    printf("\nAfter adding new node at position 2 - ");
    traverse(head);

    // Traversing a linked list
    printf("\nNumber of nodes in linked list: %d\n", countNodes(head));

    // Deleting a node from the linked list at beginning
    head = deleteFromHead(head);
    printf("\nAfter deleting a node from head - ");
    traverse(head);

    // Deleting a node from the linked list at end
    head = deleteFromEnd(head);
    printf("\nAfter deleting a node from end - ");
    traverse(head);

    // Deleting a node from the linked list at specific position
    head = deleteFromPosition(head, 2);
    printf("\nAfter deleting a node from position 2 - ");
    traverse(head);

    // Reverse A linked List
    head = reverseList(head);
    printf("\nAfter reversing the list - ");
    traverse(head);

    // Sorting a linked list
    head = sortList(head);
    printf("\nAfter Sorting the list - ");
    traverse(head);

    // Search
    printf("\n");
    search(head, 10);
    printf("\n");
    search(head, 30);

    // Free memory allocated for the linked list
    freeList(head);

    return 0;
}
