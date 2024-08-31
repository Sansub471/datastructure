// This is a C-like implementation
#ifndef BINARY_TREE_C_LIKE
#define BINARY_TREE_C_LIKE

#ifndef BINARY_TREE_NODE
#define BINARY_TREE_NODE
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};
#endif

// Create a new node
struct Node* newNode(int data);

#include<iostream>
// create a new node
struct Node* newNode(int data){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data; // same as (*node).data = data
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

// Depth first traversal techniques
void Preorder(struct Node* node);
void Inorder(struct Node* node);
void Postorder(struct Node* node);


#endif