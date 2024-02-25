

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
                break;
            }
            p = p->next;
        }
        struct Node *temp = add(value);
        temp->next = p->next;
        p->next = temp;
    }
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
    printf("%d\n", count(head));
    printf("%d\n", sum(head));
    printf("%d\n", max(head));
    printf("%d\n", min(head));
    
    struct Node *myElement = search(head, 3);
    printf("%d\n", myElement->data);
    
    insert(head, 2, 22);
    append(head, 11);
    insertAtFirst(head, 12);
     display(head);

    
        // struct Node *t = head; //both point ar first node
    // while(t != NULL){
    //     printf("%d ", t->data);
    //     t = t->next; // moving forward
    // }

    
    return 0;
}
