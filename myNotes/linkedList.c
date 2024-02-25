

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

void append(struct Node *head, int value){
    struct Node *p = head;
    while(p->next != NULL){
        p=p->next;
    }
    p->next = add(value);
}

// insert at first is not working for some reason
void insertAtFirst(struct Node *head, int value){
    struct Node *temp = add(value);
    temp->next = head;
    head = temp;
}


void insert(struct Node *head, int pos, int value){
    // insert at first
    if(pos == 0){
        // struct Node *temp = add(value);
        // temp->next = head;
        // head = temp;
        // display(head);

        return;
    }
    else{
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
}

int deleteFirst(struct Node *head){
    if(head == NULL) return 0;
    int val = head->data;
    struct Node *p = head;
    head = head->next;
    free(p);
    return val;
}

int deleteNode(struct Node *head, int pos){
    struct Node *p = head, *temp;
    for(int i=1; i<=pos-1; i++){
        if(p == NULL) {
                printf("\nInvalid Position.\n");
                return 0;
            }
        p=p->next;
    }
    temp = p->next; //deleting node
    p->next = temp->next;
    int val = temp->data;
    free(temp);
    return val;
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

// TODO: reverse using sliding pointers technique
// TODO: sort
// TODO: remove duplicate

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
    printf("%d\n", count(head));
    printf("%d\n", sum(head));
    printf("%d\n", max(head));
    printf("%d\n", min(head));
    
    struct Node *myElement = search(head, 3);
    printf("%d\n", myElement->data);
    
    insert(head, 2, 22);
    append(head, 11);
    // insertAtFirst(head, 12);
    display(head);
    
    // TODO: deleteAtFIrst not working properly
    // printf("%d\n", deleteFirst(head));
    deleteNode(head, 3);
    display(head);
    
    printf("%d\n", isSorted(head));
    
    arrayReverse(head);
    display(head);

    

    
    return 0;
}
