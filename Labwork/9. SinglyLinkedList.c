/*
Write a program to following operations on singly linked list

1.	Addition of a new node when list is empty.
2.	 Addition of a node at the end of the list.
3.	 Addition of a node at the beginning of linked list.
4.	 Addition of a node at the specific position.
5.	 Traversing a linked list.
6.	Counting number of nodes in linked list.
7.	 Deleting a node from the linked list by specifying the value of the deleting node. 
8.	Reverse A linked List.
9.	Sorting.
10.	Search
11.	Insert a node in a sorted linked list such that linked list remains sorted

*/


#include <stdio.h>
#include <stdlib.h>


struct Node{
    int data;
    struct Node *next; //self referencing structure
};

// creates a new node and returns its address
struct Node* add(int element){
    struct Node *p = (struct Node*)malloc(sizeof(struct Node));
    p->data = element;
    p->next = NULL;
    
    return p;
}


// creates a LL by given array
struct Node* create(int arr[], int size){
    struct Node *p, *q;
    // initial 
    p = add(arr[0]);
    q = p;
    for(int i = 1; i<size; i++){
        q->next = add(arr[i]);
        q = q->next; // moving q forward
    }
    // NOTE: q is currently pointing at NULL (add() takes care of it)
    return p;
}

// display or traverse
void display(struct Node *head){
    struct Node *t = head; //both point ar first node
    while(t != NULL){
        printf("%d ", t->data);
        t = t->next; // moving forward
    }
    printf("\n");
}

int count(struct Node *head){
    int count = 0;
    struct Node *p = head;
    while(p != NULL){
        count++;
        p= p->next;
    } 
    return count; //for the head node
}

int sum(struct Node *head){
    int sum=0;
    struct Node *p = head;
    while(p != NULL){
        sum += p->data;
        p = p->next;
    }
    return sum;
}

int max(struct Node *head){
    int max = 0;
    struct Node *p = head;
    while(p != NULL){
        if(max < p->data) max = p->data;
        p = p->next;
    }
    return max;
}

int min(struct Node *head){
    int min = 100;  // some large value
    struct Node *p = head;
    while(p != NULL){
        if(min > p->data) min = p->data;
        p = p->next;
    }
    return min;
}

// only linear search works for LL
struct Node* search(struct Node *head, int value){
    struct Node *p = head;
    while(p != NULL){
        if(p->data == value) return p; //returning address
        p = p->next;
    }
    return NULL; // not found
}

// insert at end
void append(struct Node *head, int value){
    struct Node *p = head;
    while(p->next != NULL){
        p=p->next;
    }
    p->next = add(value);
}

// insert at first (NOTE: return the new head if changing the head)
struct Node* insertAtFirst(struct Node *head, int value){
    struct Node *temp = add(value);
    temp->next = head;
    head = temp;
    return head;
}


void insert(struct Node *head, int pos, int value){
    // insert at any other
    struct Node *p = head;
    for(int i=1; i<=pos-2; i++){
        if(p == NULL) {
            printf("\nInvalid Position.\n");
            return;
        }
        p = p->next;
    }
    struct Node *temp = add(value);
    temp->next = p->next;
    p->next = temp;
}

struct Node* deleteFirst(struct Node *head){
    if(head == NULL) return NULL;
    struct Node *p = head;
    head = head->next;
    free(p);
    return head;
}

void deleteNode(struct Node *head, int pos){
    struct Node *p = head, *temp;
    for(int i=1; i<=pos-1; i++){
        if(p == NULL) {
                printf("\nInvalid Position.\n");
                return;
            }
        p=p->next;
    }
    temp = p->next; //deleting node
    p->next = temp->next;
    int val = temp->data;
    free(temp);
}

// Function to sort the linked list using Bubble Sort
void bubbleSort(struct Node* head) {
    int swapped;
    struct Node *ptr1;
    struct Node *lptr = NULL;

    // Check if the list is empty
    if (head == NULL) {
        return;
    }

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                // Swap data of adjacent nodes
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

int isSorted(struct Node *head){
    if(head == NULL){
        printf("\nEMPTY\n");
        return -1;
    }
    if(head->next == NULL) return 0;
    
    struct Node *p = head;
    while(p->next->next != NULL){
        if(p->data > p->next->data) return 0;
        p=p->next;
    }
    return 1;
}

void arrayReverse(struct Node *head){
    // size of linked list
    int size = count(head);
    int *arr = (int*)malloc(size * sizeof(int));
    if(count == 0){
        printf("\nEMPTY\n");
        return;
    }
    struct Node *p = head;
    // store value of LL to an array
    for(int i=0; i<size; i++){
        arr[i] = p->data;
        p=p->next;
    }
    
    p = head;
    for(int i=size-1; i>=0; i--){
        p->data = arr[i];
        p=p->next;
    }
}

// TODO: sort

int main() {
    
    // intialization of head
    struct Node *head = NULL;
    
    // Linking of nodes via array
    int values[] = {1,2,3,4};
    head = create(values, 4);
    
    printf("Current linked list:  ");
    display(head);
    printf("\n");
    
    printf("current count of nodes: %d\n", count(head));
    printf("net sum of nodes: %d\n", sum(head));
    printf("maximum value in nodes: %d\n", max(head));
    printf("minimum value in nodes: %d\n", min(head));
    
    struct Node *myElement = search(head, 3);
    printf("searched element: %d\n", myElement->data);
    
    insert(head, 2, 22);
    append(head, 11);
    head = insertAtFirst(head, 12);
    
    printf("Current linked list after inserting some nodes:  ");
    display(head);
    
    head = deleteFirst(head);
    deleteNode(head, 3);
    printf("Current linked list after deleting some nodes:  ");
    display(head);
    
    printf("is Linked list sorted? %d\n", isSorted(head));
    
    arrayReverse(head);
    printf("Current linked list after reversing:  ");
    display(head);
    
    bubbleSort(head);
    printf("Current linked list after sorting:  ");
    display(head);

    

    
    return 0;
}
