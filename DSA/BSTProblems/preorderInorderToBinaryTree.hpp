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
#include <iostream>
#include <vector>
#include <unordered_map>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Helper function to build the tree
TreeNode* buildTreeHelper(const std::vector<int>& preorder, int& preorderIndex, 
                          int inorderStart, int inorderEnd, 
                          std::unordered_map<int, int>& inorderMap) {
    // Base case: if the current range is invalid
    if (inorderStart > inorderEnd) {
        return nullptr;
    }

    // Get the root value from preorder and increment preorder index
    int rootValue = preorder[preorderIndex++];
    TreeNode* root = new TreeNode(rootValue);

    // Locate the index of the root in inorder traversal using the map
    int inorderIndex = inorderMap[rootValue];

    // Recursively build the left and right subtrees
    root->left = buildTreeHelper(preorder, preorderIndex, inorderStart, inorderIndex - 1, inorderMap);
    root->right = buildTreeHelper(preorder, preorderIndex, inorderIndex + 1, inorderEnd, inorderMap);

    return root;
}

// Main function to build tree
TreeNode* buildTree(const std::vector<int>& preorder, const std::vector<int>& inorder) {
    std::unordered_map<int, int> inorderMap;
    
    // Build a map to store the index of each value in inorder traversal
    for (int i = 0; i < inorder.size(); ++i) {
        inorderMap[inorder[i]] = i;
    }

    int preorderIndex = 0;
    return buildTreeHelper(preorder, preorderIndex, 0, inorder.size() - 1, inorderMap);
}

// Function to print the tree (inorder traversal for verification)
void printInorder(TreeNode* root) {
    if (root == nullptr) return;
    printInorder(root->left);
    std::cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    std::vector<int> preorder = {3, 9, 20, 15, 7};
    std::vector<int> inorder = {9, 3, 15, 20, 7};

    TreeNode* root = buildTree(preorder, inorder);

    std::cout << "Inorder traversal of the constructed tree: ";
    printInorder(root);

    return 0;
}

// Pretty similar to my ides, just using map for constant lookup process.