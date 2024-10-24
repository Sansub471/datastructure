#pragma once
#include"TreeNode.hpp"
// helper function for isSymmetric
bool checkSymmetry(TreeNode* p, TreeNode* q){
        if(p == nullptr || q == nullptr) return p == q; // Both or one is null
        if(p->val != q->val) return false;
        bool pT = checkSymmetry(p->left, q->right);
        bool qT = checkSymmetry(p->right, q->left);
        return pT && qT;
    }

bool isSymmetric(TreeNode* root) {
    if(root == nullptr) return true;
    return checkSymmetry(root->left, root->right); 
}