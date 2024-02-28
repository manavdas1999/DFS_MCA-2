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

void display(struct Node* head){
    struct Node* temp = head;
    do{
        printf("%d ", temp->data);
        temp = temp->next;
    }while(temp != head);
    printf("\n");
}

int main() {
 
    struct Node *head = NULL;
    // // manual 
    // head = createNode(10);
    // head->next = head; // one node CLL
    // printf("%d", head->data);
    
    // // adding more nodes
    // head->next = createNode(20);
    // head->next->next = head; // two node CLL
    // printf("%d", head->next->data);
    int values[] = {1,2,3,4};
    head = createFromArray(values, 4);
    display(head);
    return 0;
}






