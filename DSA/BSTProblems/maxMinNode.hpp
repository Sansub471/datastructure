//#include"../BinaryTree/binarySearchTree.hpp"

// Iterative
template <typename T>
    int MaxNode(T* root){
        if(root == nullptr) return -1; // empty tree
        T* current = root;
        while(current->right != nullptr) current = current->right;
        return current->data;
    }

template <typename T>
    int MinNode(T* root){
        if( root == nullptr) return -1; // empty tree
        T* current = root;
        while(current->left != nullptr) current = current->left;
        return current->data;
    }

// Recursive
template<typename T>
    int maxNode(T* root){
        if( root == nullptr) return -1;
        else if(root->right == nullptr) return root->data;
        return maxNode(root->right);
    }
    
template<typename T>
    int minNode(T* root){
        if(root == nullptr) return -1;
        else if(root->left == nullptr) return root->data;
        return minNode(root->left);
    }