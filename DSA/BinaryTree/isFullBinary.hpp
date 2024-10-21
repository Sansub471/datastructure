#pragma once
#include"binaryTree.hpp"

// To check whether a binary tree is full binary tree or not?
// Node is c-style structure node


bool isFullBinaryTree(struct Node* root){
    // check for emptiness, if root is NULL
    if(root == nullptr) return true;

    // if no children it is full binary
    if((root->left == nullptr) && (root->right == nullptr)) return true;

    // if both children, both left and right subtree must be full binary
    // only one children clearly means no full binary
    if((root->left) && (root->right)){
        return (isFullBinaryTree(root->left) && isFullBinaryTree(root->right));
    }

    return false;
}