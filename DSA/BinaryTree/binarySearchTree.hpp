#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

// Implement Nodes of binary tree

#ifndef BINARY_TREE_STRUCT_NODE
#define BINARY_TREE_STRUCT_NODE
// 1: Using struct
struct SNode {
    int data;
    SNode* left;
    SNode* right;

    SNode(int key) {
        data = key;
        left = nullptr;
        right = nullptr;
    }
};

#endif


#ifndef BINARY_TREE_CLASS_NODE
#define BINARY_TREE_CLASS_NODE
// 2: Using class
class CNode {
public:
    int data;
    CNode* left, * right;

    CNode(int key) {
        data = key;
        left = nullptr;
        right = nullptr;
    }
};
#endif

// create a new SNode
SNode* newSNode(int data){
    SNode* root = new SNode(data);
    return root;
}

// create a new CNode
CNode* newCNode(int data){
    CNode* root = new CNode(data);
    return root;
}

#include<iostream>
// Tree traversal functions: DFS techniques
// Recursive technique
template <typename T>
    void preorderDFS(T* root){
        if(root == nullptr) return;
        std::cout<<root->data<<" ,";
        preorderDFS(root->left);
        preorderDFS(root->right);
    }

template <typename T>
    void inorderDFS(T* root){

    }

template <typename T>
    void postorderDFS(T* root){
        
    }

#endif