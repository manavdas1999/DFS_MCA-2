

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next, *prev;
};

struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node*));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

struct Node* createFromArray(int arr[], int size){
    struct Node *head, *temp;
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

void display(struct Node* head){
    struct Node* temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp= temp->next;
    }
    printf("\n");
}

int main() {
    
    struct Node* head;
    // // manual
    // head = createNode(10);
    // head->next = createNode(20);
    // head->next->prev = head; // pointing back
    // printf("%d, %d", head->data, head->next->data);
    int values[] = {1,2,3,4};
    head = createFromArray(values, 4);
    display(head);
    
    return 0;
}
