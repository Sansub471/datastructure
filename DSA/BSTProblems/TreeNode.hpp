//Definition for a binary tree node.
#ifndef TREE_NODE_LEET
#define TREE_NODE_LEET

struct TreeNode {
    union{   
        int val;
        int data;
    };
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#endif