#include"binaryTree.hpp"

// DFS:preorder traversal
void Preorder(struct Node* node){
    if(node == nullptr){
        return;
    }
    std::cout<< node->data << ", ";
    Preorder(node->left);
    Preorder(node->right);
}

// DFS:inorder traversal
void Inorder(struct Node* node){
    if(node == nullptr){
        return;
    }
    Inorder(node->left);
    std::cout<< node->data<<", ";
    Inorder(node->right);
}

// DFS:post order traversal
void Postorder(struct Node* node){
    if (node == nullptr){
        return;
    }
    Postorder(node->left);
    Postorder(node->right);
    std::cout<< node->data<< ", ";
}