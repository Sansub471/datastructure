#pragma once
#include"binaryTree.hpp"

struct Node* balancedBinaryTree(){
    // give a tree to test balancec binary condition
    struct Node* root = newNode(1);
    root->left = newNode(2); 
    root->right = newNode(3);

    root->left->left = newNode(4);
    root->left->right = newNode(5);
    //root->left->right->left = newNode(6);
    return root;
}

bool isBalancedBinary(struct Node* root, int* height){
    int leftheight = 0, rightHeight = 0;
    bool l=false, r=false;

    if(root==nullptr){
        *height = 0;
        return true;
    }

    l = isBalancedBinary(root->left, &leftheight);
    r = isBalancedBinary(root->right, &rightHeight);

    *height = (leftheight > rightHeight ? leftheight : rightHeight) + 1;
    if(std::abs(leftheight - rightHeight) >= 2){
        return false;
    }
    else{
        return l && r;
    }
}