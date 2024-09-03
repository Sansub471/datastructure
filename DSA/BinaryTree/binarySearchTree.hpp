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
    CNode* left;
    CNode* right;

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

// Example BST Trees
// Using structure node
SNode* BST_ONE(){
    SNode* root = newSNode(8);
    root->left = newSNode(3);
    root->right = newSNode(10);

    root->left->left = newSNode(1);
    root->left->right = newSNode(6);
    root->left->right->left = newSNode(4);
    return root;
}

// using class node
CNode* BST_TWO(){
    CNode* root = newCNode(8);
    root->left = newCNode(3);
    root->right = newCNode(10);
    root->right->right = newCNode(14);

    root->left->left = newCNode(1);
    root->left->right = newCNode(6);
    root->left->right->left = newCNode(4);
    root->left->right->right = newCNode(7);
    return root;

}

#include<iostream>
// Tree traversal functions: DFS techniques
// Recursive technique
template <typename T>
    void preorderDFS(T* root){
        if(root == nullptr) return;
        std::cout<<root->data<<", ";
        preorderDFS(root->left);
        preorderDFS(root->right);
    }

template <typename T>
    void inorderDFS(T* root){
        if(root == nullptr) return;
        inorderDFS(root->left);
        std::cout<< root->data <<", ";
        inorderDFS(root->right);
    }

template <typename T>
    void postorderDFS(T* root){
        postorderDFS(root->left);
        postorderDFS(root->right);
        std::cout<< root->data <<", ";

    }

#endif