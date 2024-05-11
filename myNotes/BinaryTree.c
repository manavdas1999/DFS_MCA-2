#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// pre-order traversal creation
struct Node* createPreOrder(){
    int input;
    printf("\nEnter data for node (-1 if no node):");
    scanf("%d", &input);
    
    if(input == -1){
        return NULL;
    }
    
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = input;
    
    printf("\nLeft Node of %d: ", newNode->data);
    newNode->left = createPreOrder();
    printf("\nRight Node of %d: ", newNode->data);
    newNode->right = createPreOrder();
    
    return newNode;
}

void preOrderTraversal(struct Node* temp){
    if(temp != NULL){
        printf("%d ", temp->data);
        preOrderTraversal(temp->left);
        preOrderTraversal(temp->right);
    }
}

void inOrderTraversal(struct Node* temp){
    if(temp != NULL){
        inOrderTraversal(temp->left);
        printf("%d ", temp->data);
        inOrderTraversal(temp->right);
    }
}

void postOrderTraversal(struct Node* temp){
    if(temp != NULL){
        postOrderTraversal(temp->left);
        postOrderTraversal(temp->right);
        printf("%d ", temp->data);
    }
}

int main() {
    struct Node* root;
    root = createPreOrder();
    
    preOrderTraversal(root);
    printf("\n");
    inOrderTraversal(root);
    printf("\n");
    postOrderTraversal(root);
    

    return 0;
}
