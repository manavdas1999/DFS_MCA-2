#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Pre-order traversal creation
struct Node* createPreOrder(){
    int input;
    printf("\nEnter data for node (-1 if no node):");
    scanf("%d", &input);
    
    if(input == -1){
        return NULL;
    }

    // Parent
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = input;

    // Left Child 
    printf("\nLeft Node of %d: ", newNode->data);
    newNode->left = create();

    // Right Child 
    printf("\nRight Node of %d: ", newNode->data);
    newNode->right = create();
    
    return newNode;
}


int main() {
    struct Node* root;
    root = createPreOrder();

    return 0;
}
