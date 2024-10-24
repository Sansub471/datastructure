#pragma once
#include"TreeNode.hpp"
#include<vector>
#include<map>
#include<algorithm>

// My solution
TreeNode* insertNode(TreeNode* root, int val){
    TreeNode* newNode = new TreeNode(val);
    if(root == nullptr) return newNode;
    if(val < root->val){
        root->left = insertNode(root->left, val);
    }else{
        root->right = insertNode(root->right, val);
    }
    return root;
}
TreeNode* bstFromPreorder(std::vector<int>& preorder) {
    if(preorder.empty()) return nullptr;
    TreeNode* root = nullptr;
    for(const auto& elem: preorder){
        root = insertNode(root, elem);
    }
    return root;
}

// Leetcode
TreeNode* rec(int left, int right, int& preIdx, std::vector<int>& preorder, std::vector<int>& inorder, std::map<int, int>& valueIdx){
    if (left > right || preIdx >= preorder.size()) return nullptr;
    TreeNode* root = new TreeNode(preorder[preIdx]);
    int idx = valueIdx[preorder[preIdx]];
    preIdx++;
    root->left = rec(left, idx-1, preIdx, preorder, inorder, valueIdx);
    root->right = rec(idx+1, right, preIdx, preorder, inorder, valueIdx);
    return root;
}
TreeNode* bstFromPreorderLeet(std::vector<int>& preorder) {
    std::vector<int> inorder = preorder;
    std::sort(inorder.begin(), inorder.end());
    std::map<int, int> valueIdx;
    int n = inorder.size();
    for(int i=0;i<n;i++) valueIdx[inorder[i]] = i;
    int preIdx = 0;
    TreeNode* root = rec(0, preorder.size() - 1, preIdx, preorder, inorder, valueIdx);
    return root;
}