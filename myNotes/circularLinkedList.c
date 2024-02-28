// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* createFromArray(int arr[], int size){
    struct Node* head = NULL;
    struct Node* tail = NULL;
    
    // first node
    head = createNode(arr[0]);
    head->next = head;
    
    tail = head;
    
    for(int i=1; i<size; i++){
        tail->next = createNode(arr[i]);
        tail = tail->next;
        tail->next = head;
    }
    
    return head;
}

int main() {
 

    return 0;
}
