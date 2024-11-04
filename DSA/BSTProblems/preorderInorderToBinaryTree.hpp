// in place of #indef #def #endif block
#pragma once
#include"TreeNode.hpp"
#include <iostream>
#include <vector>
#include <unordered_map>

TreeNode* makeTree(const std::vector<int>& preorder, int& preOrderIndex, 
                    int inStart, int inEnd, 
                    std::unordered_map<int, int>& inorderMap){
    // Base case: if the current range is invalid
    if(inStart > inEnd) return nullptr;

    // Get the root value from preorder and increment preorder index
    int rootVal = preorder[preOrderIndex++];
    TreeNode* root = new TreeNode(rootVal);

    // Locate the index of the root in inorder traversal using the map
    int inorderIdx = inorderMap[rootVal];
   
    // Recursively build the left and right subtrees
    root->left = makeTree(preorder, preOrderIndex, inStart, inorderIdx - 1, inorderMap);
    root->right = makeTree(preorder, preOrderIndex, inorderIdx + 1, inEnd, inorderMap);
    return root;
    
}
TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
    if(preorder.empty() || inorder.empty()) return nullptr;
    // Build a map to store the index of each value in inorder traversal
    std::unordered_map<int, int> inorderMap;
    for(int i = 0; i < inorder.size(); ++i){
        inorderMap[inorder[i]] = i;
    }
    int preOrderIndex = 0; // first element is the root
    int inStart = 0, inEnd = inorder.size() - 1;
    return makeTree(preorder, preOrderIndex, inStart, inEnd, inorderMap);        
}