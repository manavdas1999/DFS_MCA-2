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
    // // two pointer approach (head is fixed (incoming end), tail is moving (outgoing end))
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
    
    // // tail pointer approach(tail is moving (outgoing end))
    // first node
    // struct Node* tail = createNode(arr[0]);
    // tail->next = tail;
    // for(int i = 1; i<size; i++){
    //     struct Node* newNode = createNode(arr[i]);
    //     newNode->next = tail->next; // tail->next holds outgoing end
    //     tail->next = newNode;
    //     tail = tail->next; // tail forward moves
    // }
    
    // return tail;
}

void display(struct Node* head){
    struct Node* temp = head;
    do{
        // temp = temp->next; // for tail approach
        printf("%d ", temp->data);
        temp = temp->next; // 2 pointer approach
    }while(temp != head);
    printf("\n");
}


int count(struct Node* head){
   if(head == NULL) return 0;
   int count = 0;
   struct Node* temp=head;
   do{
       count++;
       temp=temp->next;
   }while(temp != head);
   
   return count;
}


struct Node* insertAtHead(struct Node* head, int data){
    // // two pointer approach
    struct Node* temp = head;
    do{
        temp=temp->next;
    }while(temp->next != head);  // stop at tail node
    temp->next = createNode(data);
    temp=temp->next; // temp on new node
    temp->next = head;
    head = temp;
    return head;
}

void insertBetween(struct Node* head, int pos, int data){
    // count + 1 as we can add in the end
    if(pos <=0 || pos>count(head)+1) printf("\nInvalid position!\n");
    else{
        struct Node* temp = head;
        for(int i=0; i<pos-2; i++) temp=temp->next;
        struct Node* newNode = createNode(data);
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

struct Node* deleteAtHead(struct Node* head){
    struct Node* temp = head;
    struct Node* del = head;
    do{
        temp=temp->next;
    }while(temp->next != head);
    head=head->next; // new head
    temp->next = head; //points to new head
    free(del);
    
    return head;
}

void deleteBetween(struct Node* head, int pos){
    if(pos <=0 || pos>count(head)) printf("\nInvalid position!\n");
    else{
        struct Node* temp = head;
        struct Node* del;
        for(int i=0; i<pos-2; i++) temp=temp->next;
        del = temp->next;
        temp->next = del->next;
        free(del);
    }
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
    insertBetween(head, 5, 11);
    // deleteBetween(head, 2);
    head = insertAtHead(head, 20);
    display(head);
    head = deleteAtHead(head);
    display(head);
    printf("%d", count(head));
    return 0;
}






