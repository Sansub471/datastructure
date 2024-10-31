#pragma once
#include<vector>
#include"TreeNode.hpp"

class postorderInorderToBinaryTree {
public:
    std::vector<int> inorder;
    std::vector<int> postorder;
    int postIndex;

    int search(int start, int end, int value){
        for(int i = start; i <= end; ++i){
            if(inorder[i] == value) return i; // sure found
        }
        return -1; // for compiler
    }
    TreeNode* makeTree(int start, int end){
        if(start > end ) return nullptr;
        int key = this->postorder.at(this->postIndex); 
        int index = search(start, end, key);
        this->postIndex--;
        TreeNode* node = new TreeNode(key);
        node->right = makeTree(index + 1, end);
        node->left = makeTree(start, index - 1);
        return node;

    }
    TreeNode* buildTree(std::vector<int>& inorder, std::vector<int>& postorder) {
        if(inorder.empty() || postorder.empty()) return nullptr;
        this->inorder = inorder;
        this->postorder = postorder;
        this->postIndex = postorder.size() - 1;
        return makeTree(0, this->postIndex);
    }
};