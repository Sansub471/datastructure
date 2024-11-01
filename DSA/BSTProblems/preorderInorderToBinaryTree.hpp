// in place of #indef #def #endif block
#pragma once
#include<vector>
#include"TreeNode.hpp"

class preorderInorderToBinaryTree{
public:
    std::vector<int> preorder;
    std::vector<int> inorder;
    int preOrderIndex;
    
    // the element is guaranteed to be found
    int search(int start, int end, int value){
        for(int i = start; i <= end; ++i){
            if(this->inorder.at(i) == value) return i;
        }
        return -1; // for compiler issue
    }
    TreeNode* makeTree(int start, int end){
        if(start > end) return nullptr;
        int key = this->preorder.at(this->preOrderIndex);
        int index = this->search(start, end, key);
        TreeNode* node = new TreeNode(key);
        this->preOrderIndex++;
        node->left = makeTree(start, index - 1);
        node->right = makeTree(index + 1, end);
        return node;
        
    }
    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
        if(preorder.empty() || inorder.empty()) return nullptr;
        this->preorder = preorder;
        this->inorder = inorder;
        this->preOrderIndex = 0;
        return makeTree(0, inorder.size() - 1);        
    }
};

// Better solution using unordered map
// The day starts for now.