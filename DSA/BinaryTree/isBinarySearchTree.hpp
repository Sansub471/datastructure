#pragma once
#include"binaryTree.hpp"
#include<climits>

bool BSThelper(Node* root, long minValue, long maxValue){
    if(root == nullptr) return true;
    if(root->data > minValue && root->data < maxValue
        && BSThelper(root->left, minValue, root->data)
        && BSThelper(root->right, root->data, maxValue)){
            return true;
    }else{
        return false;
    }
}

bool isValidBST(Node* root) {
    if(root == nullptr) return true;
    return BSThelper(root, LONG_MIN, LONG_MAX);
}
