

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

int main() {
    
    // intialization of head
    struct Node *head = NULL;
    
    // Manual linking of nodes
    // head = add(1);
    // head->next = add(2);
    
    // Linking of nodes via array
    int values[] = {1,2,3,4};
    head = create(values, 4);

    
    // printf("%d", head->data);
    // printf("%d", head->next->data);
    
    display(head);
    
    return 0;
}
