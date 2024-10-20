#pragma once
// Tilt of a binary tree = sum of tilt of each node
// tilt of each node = |sum of left subtree nodes - sum of right sub tree node|

// My method : If you don't want to modify the original tree
// in tiltCalculate() replace root->left->val with subtreeSum(root->left)
// and replace root->right->val with subtreeSum(root->right) 
struct key{
    int treeSum;
    int tiltSum;
};

template<typename T>
    key calculateTilt(T* root){
        if(root == nullptr) return {0,0};
        key lTree = calculateTilt(root->left);
        key rTree = calculateTilt(root->right);
        key k;
        k.treeSum = root->data + lTree.treeSum + rTree.treeSum;
        k.tiltSum = std::abs(lTree.treeSum - rTree.treeSum) + lTree.tiltSum + rTree.tiltSum;
        return k;
    }

template<typename T>
    int treeTilt(T* root) {
        key k = calculateTilt(root);
        return k.tiltSum;
    }
    // Time = O(n)
    // Space  = O(n)