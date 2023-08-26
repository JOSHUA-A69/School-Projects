#include <stdio.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int main() {
    struct Node* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(15);
    
    printf("%d\n", root->data);        // Outputs 10
    printf("%d\n", root->left->data);   // Outputs 5
    printf("%d\n", root->right->data);  // Outputs 15
    
    return 0;
}
