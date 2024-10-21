#pragma once
#include"binaryTree.hpp"

struct Node* completeBinaryTree(){
    struct Node* root = newNode(1);
    root->left = newNode(12);
    root->left->left = newNode(5);
    //root->left->right = newNode(6);

    root->right = newNode(9);
    // root->right->right = newNode(5);
    root->right->left = newNode(10);
    return root;
}

// count the number of nodes.
int countNodesNumber(struct Node* root){
    if(root==nullptr) return 0;
    return (1 + countNodesNumber(root->left) + countNodesNumber(root->right));
}

// check if complete binary tree
bool isCompleteBinary(struct Node* root, int index, int numberNodes){
    // if empty return true
    if(root==nullptr) return true;

    // check if levels are fully filled, except the lowest level
    if(index >= numberNodes) return false;

    return (isCompleteBinary(root->left, 2 * index + 1, numberNodes) && 
            isCompleteBinary(root->right, 2 * index + 2, numberNodes));
}